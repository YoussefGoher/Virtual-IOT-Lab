/*
 * main.c
 *
 *  Created on: Feb 5, 2024
 *      Author: eng_youssef_goher
 */

#include"STD_Types.h"
#include"BIT_MATH.h"
#include"NVIC_INTERFACE.h"
#include"MRCC_INTERFACE.h"
#include"MGPIO_INTERFACE.h"
#include"MSTK_Interface.h"
#include"MUSART_Interface.h"
#include"FLASH_SECTOR_F4.h"
void BOOTLOADER_Work(void);
u8 chartoByte(u8 ch);
#define	SCB_VTOR *((volatile u32*)0xE000ED08)
void func4(void);

typedef void (*Function_t)(void);
Function_t myFunctionPointer2=0;

void main(void){
		MRCC_voidInit();
		MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
		MRCC_voidEnablePeripheral(RCC_APB2,4);
		MSTK_voidInit();
		MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
		MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);
		MGPIO_voidConfigureAlterFun(GPIO_PORTA,GPIO_PIN9, AF7);
		MGPIO_voidConfigureAlterFun(GPIO_PORTA,GPIO_PIN10, AF7);
		MUSART_voidInit();
		MUSART_EnableUSART(MUSART_USART1);
		Flash_Erase_APP();
		BOOTLOADER_Work();
		func4();
		while(1){
		}
}
//MUSART_voidReceive MUSART_voidTransmit
void BOOTLOADER_Work(void){
	u8 Local_u8recivearray[256] = {'\0'};
	u32 Local_Counter = 0;
	u32 address = 0;
	u32 data = 0;
	u8 temp_u8recive = 0;

	MUSART_voidTransmit(MUSART_USART1, "STARTBOOT\r\n", 11);
	MUSART_voidTransmit(MUSART_USART1, "OK\r\n", 4);
	while (temp_u8recive != ';') {
		Local_Counter = 0;
		do {
			MUSART_voidReceive(MUSART_USART1, &temp_u8recive);
			if (temp_u8recive != ';' && temp_u8recive != '\n') {
				if (Local_Counter < 255) {
					Local_u8recivearray[Local_Counter++] = chartoByte(temp_u8recive);
				} else {
					// Handle buffer overflow
					MUSART_voidTransmit(MUSART_USART1, "ERROR: Buffer Overflow\r\n", 25);
					return;
				}
			}
		} while (temp_u8recive != '\n' && temp_u8recive != ';');

		if (Local_Counter >= 18) { // Ensuring there's enough data to parse
			address=	(Local_u8recivearray[1]<<28)|
						(Local_u8recivearray[2]<<24)|
						(Local_u8recivearray[3]<<20)|
						(Local_u8recivearray[4]<<16)|
						(Local_u8recivearray[5]<<12)|
						(Local_u8recivearray[6]<<8)|
						(Local_u8recivearray[7]<<4)|
						(Local_u8recivearray[8]<<0);

			data=		(Local_u8recivearray[10]<<28)|
						(Local_u8recivearray[11]<<24)|
						(Local_u8recivearray[12]<<20)|
						(Local_u8recivearray[13]<<16)|
						(Local_u8recivearray[14]<<12)|
						(Local_u8recivearray[15]<<8)|
						(Local_u8recivearray[16]<<4)|
						(Local_u8recivearray[17]<<0);
			Flash_Write_Word(address, data);
			MUSART_voidTransmit(MUSART_USART1, "OK\r\n", 4);
		} else {
			// Handle incorrect data size
			MUSART_voidTransmit(MUSART_USART1, "ERROR: Insufficient Data\r\n", 27);
			return;
		}
	}
}
u8 chartoByte(u8 ch){
	u8 Local_u8Return=0;
	if(ch>='0'&&ch<='9'){
		Local_u8Return=ch-'0';
	}
	else if(ch>='A'&&ch<='F'){
		Local_u8Return=ch-'A'+10;
	}
	else if(ch>='a'&&ch<='f'){
		Local_u8Return=ch-'a'+10;
	}
	else{
		Local_u8Return=0;
	}
	return Local_u8Return;
}
void func4(void){
	SCB_VTOR=0x8000<<9;
	myFunctionPointer2 =*(Function_t*)0x08008004;
	myFunctionPointer2();
}
