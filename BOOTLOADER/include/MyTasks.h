/*
 * MyTasks.h
 *
 *  Created on: Feb 8, 2024
 *      Author: eng_youssef_goher
 */

#ifndef MYTASKS_H_
#define MYTASKS_H_

#define DAC_UPDATE_OUTPUT_SYSTEM_TICKS	125
#define DAC_TASK_FD_SYSTEM_TICKS		0

#define	SCB_VTOR *((volatile u32*)0xE000ED08)

void APP_Initialize(void);
void DAC_task(void);
void USART_voidRecieveCode(void);
u8 change_char_whit_vlue(u8 character);
u8 calculateChecksum(u32 address, u32 data);
void func(void);
typedef void (*Function_t)(void);

#endif /* MYTASKS_H_ */
