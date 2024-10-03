/*
 * flash_programmer.h
 *
 *  Created on: Apr 17, 2024
 *      Author: eng_youssef_goher
 */

#ifndef FLASH_PROGRAMMER_H_
#define FLASH_PROGRAMMER_H_


void Flash_Program_Init(void);
void Error_Handler(void);
void Receive_Intel_HEX_Record(void);
int HEX_ParseRecord(char *record, u32 *address, u8 *data, u32 *dataLength, u32 *extendedAddress);


#endif /* 02_HAL_FLASH_PROGRAMMER_FLASH_PROGRAMMER_H_ */
