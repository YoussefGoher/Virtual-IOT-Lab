/*
 * flash_programmer.c
 *
 *  Created on: Apr 17, 2024
 *      Author: eng_youssef_goher
 */

#include "MUSART_Interface.h"
#include "FLASH_SECTOR_F4.h"
#include "STD_Types.h"
#include "flash_programmer.h"

u32 extendedAddress = 0;  // Global extended address for HEX parsing


void Flash_Program_Init(void) {
	MUSART_voidInit();
	MUSART_EnableUSART(MUSART_USART1);
	Flash_Erase_APP();
}

u8 hexCharToByte(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

u32 parseHex(char *str, u8 len) {
    u32 value = 0;
    while (len--) {
        value = (value << 4) | hexCharToByte(*str++);
    }
    return value;
}

int calculate_checksum(const char *record, int byteCount) {
    unsigned int sum = 0;
    for (int i = 0; i < byteCount + 4; ++i) {
        u32 value = parseHex(record + 1 + 2 * i, 2);
        sum += value;
    }
    return (~sum + 1) & 0xFF;
}

int HEX_ParseRecord(char *record, u32 *address, u8 *data, u32 *dataLength, u32 *extendedAddress) {
    if (record[0] != ':') return -1;

    u8 byteCount = parseHex(record + 1, 2);
    u32 recAddress = parseHex(record + 3, 4);
    u8 recType = parseHex(record + 7, 2);
    char *dataPos = record + 9;

    int calculatedChecksum = calculate_checksum(record, byteCount);
    u8 readChecksum = parseHex(record + 9 + byteCount * 2, 2);
    if (calculatedChecksum != readChecksum) {
        return -2;  // Checksum error
    }

    switch (recType) {
        case 0x00:  // Data record
            *address = *extendedAddress + recAddress;
            *dataLength = byteCount;

            for (u32 i = 0; i < byteCount; i++) {
                data[i] = parseHex(dataPos + 2 * i, 2);
            }
            return 0;

        case 0x01:  // End of File record
            *dataLength = 0;
            return 1;

        case 0x02:  // Extended Segment Address record
            *extendedAddress = parseHex(dataPos, 4) << 4;
            return 2;

        case 0x04:  // Extended Linear Address record
            *extendedAddress = parseHex(dataPos, 4) << 16;
            return 3;

        default:
            return -3;  // Unsupported record type
    }
}

void Error_Handler(void) {
    __disable_irq();
    while (1) {}
}

void Receive_Intel_HEX_Record(void) {
    u32 address;
    u8 data[256];
    u32 dataLength;
    char hexRecord[512];

    MUSART_voidReceiveString(MUSART_USART1, (u8 *)hexRecord);  // Assume USART2 is used

    if (HEX_ParseRecord(hexRecord, &address, data, &dataLength, &extendedAddress) == 0) {
        Flash_Write_Data(address, (u32 *)data, dataLength / sizeof(u32));
    }
}


