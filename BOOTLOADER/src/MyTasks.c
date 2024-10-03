/*
 * MyTasks.c
 *
 *  Created on: Feb 8, 2024
 *      Author: eng_youssef_goher
 */
#include"STD_Types.h"
#include"NVIC_INTERFACE.h"
#include"MRCC_INTERFACE.h"
#include"MGPIO_INTERFACE.h"
#include"MyTasks.h"
#include"MUSART_Interface.h"
#include"FLASH_SECTOR_F4.h"
#include"MSTK_Interface.h"

Function_t myFunctionPointer=0;

void APP_Initialize(void){
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN0,GPIO_NOPUPD,GPIO_MEDIUM_SPEED);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN1,GPIO_NOPUPD,GPIO_MEDIUM_SPEED);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN2,GPIO_NOPUPD,GPIO_MEDIUM_SPEED);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN3,GPIO_NOPUPD,GPIO_MEDIUM_SPEED);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN4,GPIO_NOPUPD,GPIO_MEDIUM_SPEED);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN5,GPIO_NOPUPD,GPIO_MEDIUM_SPEED);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN6,GPIO_NOPUPD,GPIO_MEDIUM_SPEED);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN7,GPIO_NOPUPD,GPIO_MEDIUM_SPEED);
}

void DAC_task(void){
	static u8 state = 0;
	MGPIO_voidSetPortVlue(GPIO_PORTA,state);
	state++;
}

void USART_voidRecieveCode(void) {
	u8 address[4];
	u8 data[4];
	u32 u32_address=0;
	u32 u32_data=0;
    u32 local_counter;
    u8 inner_counter;
    u8 upper = 0;
    u8 lower = 0;
    u8 flag_dummy = 0;
    u16 counter = 0;
    u8 ReceivedData = '\0';
    u8 receivedChecksum = 0; // Store the received checksum

    for (local_counter = 0; ReceivedData != ';'; local_counter++) {
    	MUSART_voidReceive(MUSART_USART1,&ReceivedData);
        if (ReceivedData == ':') {
        	MGPIO_voidSetResetPin(GPIO_PORTA,GPIO_PIN0,GPIO_SET);
            for (inner_counter = 4; inner_counter > 0; inner_counter--) {
                local_counter++;
                MUSART_voidReceive(MUSART_USART1,&ReceivedData);
                upper = change_char_whit_vlue(ReceivedData);
                local_counter++;
                MUSART_voidReceive(MUSART_USART1,&ReceivedData);
                lower = change_char_whit_vlue(ReceivedData);
                address[inner_counter - 1] = ((upper * 16) + lower);
            }
            local_counter++;
            MUSART_voidReceive(MUSART_USART1,&ReceivedData);
            u32_address = *((u32*)&address);
            if (ReceivedData == ',') {
                for (inner_counter = 4; inner_counter > 0; inner_counter--) {
                    local_counter++;
                    MUSART_voidReceive(MUSART_USART1,&ReceivedData);
                    upper = change_char_whit_vlue(ReceivedData);
                    local_counter++;
                    MUSART_voidReceive(MUSART_USART1,&ReceivedData);
                    lower = change_char_whit_vlue(ReceivedData);
                    data[inner_counter - 1] = ((upper * 16) + lower);
                }
            }
            u32_data = *((u32*)&data);

            // Receive the checksum
            local_counter++;
            MUSART_voidReceive(MUSART_USART1,&ReceivedData);
            receivedChecksum = change_char_whit_vlue(ReceivedData);

            // Calculate the expected checksum
            u8 calculatedChecksum = calculateChecksum(u32_address, u32_data);
            if(!flag_dummy){
            	 flag_dummy = 1;
            }
            else{
            // Verify the checksum
            if (receivedChecksum == calculatedChecksum) {
                // Checksum is valid, proceed with writing to flash
                if (flag_dummy && (u32_address <= 0x8040000) && (u32_address >= 0x08008000)) {
                    Flash_Write_Word(u32_address, u32_data);
                }
            } else {
                // Checksum error, handle it here
                // You can log an error, discard the data, or take appropriate action.
            }
            }
            counter++;
        }

    }
    MGPIO_voidSetResetPin(GPIO_PORTA,GPIO_PIN0,GPIO_RESET);
}
u8 change_char_whit_vlue(u8 character){
	u8 Local_vlue=';';
	switch(character){
	case '0':
		Local_vlue= 0;
		break;
	case '1':
		Local_vlue= 1;
			break;
	case '2':
		Local_vlue= 2;
			break;
	case '3':
		Local_vlue= 3;
			break;
	case '4':
		Local_vlue= 4;
			break;
	case '5':
		Local_vlue= 5;
			break;
	case '6':
		Local_vlue= 6;
			break;
	case '7':
		Local_vlue= 7;
			break;
	case '8':
		Local_vlue= 8;
			break;
	case '9':
		Local_vlue= 9;
			break;
	case 'a':
	case 'A':
		Local_vlue= 10;
			break;
	case 'b':
	case 'B':
		Local_vlue= 11;
			break;
	case 'c':
	case 'C':
		Local_vlue= 12;
			break;
	case 'd':
	case 'D':
		Local_vlue= 13;
			break;
	case 'e':
	case 'E':
		Local_vlue= 14;
			break;
	case 'f':
	case 'F':
		Local_vlue= 15;
			break;

	}
	return Local_vlue;
}

u8 calculateChecksum(u32 address, u32 data) {
	u8 checksum=0;
    // Calculate the checksum by adding the address and data bytes
	checksum = (address%10)+(data%10);
    return checksum%10;
}

void func(void){
	SCB_VTOR=0x8000<<9;
	myFunctionPointer =*(Function_t*)0x08008004;
	myFunctionPointer();
}
