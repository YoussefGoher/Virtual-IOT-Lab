/*
 * MRCC_Interface.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Ibrahim
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

/**********************************General Macros****************************************/
/**************Buses*********************/
#define RCC_APB1			0
#define RCC_APB2			1
#define RCC_AHB1			2
#define RCC_AHB2			3
/***************APB1*********************/
#define RCC_APB1_TIM2		0
#define RCC_APB1_TIM3		1
#define RCC_APB1_TIM4		2
#define RCC_APB1_TIM5		3
#define RCC_APB1_WWDG		11
#define RCC_APB1_SPI2		14
#define RCC_APB1_SPI3		15
#define RCC_APB1_USART2		17
#define RCC_APB1_I2C1		21
#define RCC_APB1_I2C2		22
#define RCC_APB1_I2C3		23
#define RCC_APB1_PWR		28
/***************AHB1*********************/
#define RCC_AHB1_GPIOA		0
#define RCC_AHB1_GPIOB		1
#define RCC_AHB1_GPIOC		2
#define RCC_AHB1_GPIOD		3
#define RCC_AHB1_GPIOE		4
#define RCC_AHB1_GPIOH		7
#define RCC_AHB1_CRCRST		12
#define RCC_AHB1_DMA1		21
#define RCC_AHB1_DMA2		22
/***************AHB2*********************/
#define RCC_AHB2_OTGFS		7
/***************APB2*********************/
#define RCC_APB2_TIM1		0
/**********************APB_Prescalers*********************************/
#define RCC_APB_PRESCALER_BY_1      0b000
#define RCC_APB_PRESCALER_BY_2 		0b100
#define RCC_APB_PRESCALER_BY_4      0b101
#define RCC_APB_PRESCALER_BY_8      0b110
#define RCC_APB_PRESCALER_BY_16     0b111
/**********************AHB_Prescalers*********************************/
#define RCC_AHB_PRESCALER_BY_1      0b0000
#define RCC_AHB_PRESCALER_BY_2 		0b1000
#define RCC_AHB_PRESCALER_BY_4      0b1001
#define RCC_AHB_PRESCALER_BY_8      0b1010
#define RCC_AHB_PRESCALER_BY_16     0b1011
#define RCC_AHB_PRESCALER_BY_64     0b1100
#define RCC_AHB_PRESCALER_BY_128    0b1101
#define RCC_AHB_PRESCALER_BY_256    0b1110
#define RCC_AHB_PRESCALER_BY_512    0b1111
/********************************Functions Prototypes************************************/
void MRCC_voidInit(void);
void MRCC_voidEnablePeripheral(u32 copyu32_BusAddress , u32 copyu32_Peripheral);
void MRCC_voidDisablePeripheral(u32 copyu32_BusAddress , u32 copyu32_Peripheral);

void MRCC_voidSetAPB1Prescaler(u8 copyu8APB1Prescaler);
void MRCC_voidSetAPB2Prescaler(u8 copyu8APB2Prescaler);
void MRCC_voidSetAHBPrescaler(u8 copyu8AHB1Prescaler);


#endif /* MRCC_INTERFACE_H_ */
