/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#define NO_SUB_PRIORITY 0
#define PEND_SV        -6
#define SYSTICK        -5
#define SV_CALL        -4
#define MEMORY_MANAGE  -3
#define BUS_FAULT      -2
#define USAGE_FAULT    -1

typedef enum {
    _16GROUP_NOSUBGROUP = 0x05FA0300,
    _8GROUP_2SUBGROUP   = 0x05FA0400,
    _4GROUP_4SUBGROUP   = 0x05FA0500,
    _2GROUP_8SUBGROUP   = 0x05FA0600,
    _NOGROUP_16SUBGROUP = 0x05FA0700
} GROUPS_options;

#define GROUPS_option GROUPS_options

typedef enum {
	GROUP0,
	GROUP1,
	GROUP2,
	GROUP3,
	GROUP4,
	GROUP5,
	GROUP6,
	GROUP7,
	GROUP8,
	GROUP9,
	GROUP10,
	GROUP11,
	GROUP12,
	GROUP13,
	GROUP14,
	GROUP15
} GROUP;

typedef enum {
	SUBGROUP0,
	SUBGROUP1,
	SUBGROUP2,
	SUBGROUP3,
	SUBGROUP4,
	SUBGROUP5,
	SUBGROUP6,
	SUBGROUP7,
	SUBGROUP8,
	SUBGROUP9,
	SUBGROUP10,
	SUBGROUP11,
	SUBGROUP12,
	SUBGROUP13,
	SUBGROUP14,
	SUBGROUP15
} SUBGROUP;

#define GROUPS GROUP

#include "Vector_Table.h"

void MNVIC_VidEnablePeripheral  ( u8 Copy_u8INTID );

void MNVIC_VidDisablePeripheral ( u8 Copy_u8INTID );

void MNVIC_VidSetPending        ( u8 Copy_u8INTID );

void MNVIC_VidClearPending      ( u8 Copy_u8INTID );

u8   MNVIC_u8GetActive          ( u8 Copy_u8INTID );

void MNVIC_VidSetPeripheralPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority);

void NVIC_voidSetPriorityConfig(u32 Copy_u32PriprityOption);

void NVIC_voidMakeSoftwareInterrupt(u32 Copy_u32InterruptID);

#endif /* NVIC_INTERFACE_H_ */
