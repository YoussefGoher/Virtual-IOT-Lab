/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/



#include"STD_Types.h"
#include"BIT_MATH.h"
#include"NVIC_REG.h"
#include"NVIC_INTERFACE.h"


static u32 StaticGlobal_u32PriorityConfig =	_16GROUP_NOSUBGROUP;

void MNVIC_VidEnablePeripheral ( u8 Copy_u8INTID ){

	MNVIC->ISER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;

}

void MNVIC_VidDisablePeripheral ( u8 Copy_u8INTID ){

	MNVIC->ICER[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;

}


void MNVIC_VidSetPending ( u8 Copy_u8INTID ){

	MNVIC->ISPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;


}

void MNVIC_VidClearPending ( u8 Copy_u8INTID ){

	MNVIC->ICPR[ Copy_u8INTID / 32 ] = 1 << ( Copy_u8INTID % 32 ) ;

}


u8   MNVIC_u8GetActive( u8 Copy_u8INTID ){

	u8 LOC_u8Active = GET_BIT( (MNVIC->IAPR[ Copy_u8INTID/32 ]) , ( Copy_u8INTID % 32 ) );
	return LOC_u8Active ;

}


void MNVIC_VidSetPeripheralPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority ){

	u8 Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (StaticGlobal_u32PriorityConfig - 0x05FA0300) / 256 )  ;
	//Core Peripheral
	if( Copy_u8INTID < 0  ){

		if( Copy_u8INTID == MEMORY_MANAGE || Copy_u8INTID == BUS_FAULT || Copy_u8INTID == USAGE_FAULT ){

			Copy_u8INTID += 3;
			SCB_->SHPR1 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );

		}
		else if ( Copy_u8INTID == SV_CALL ){

			Copy_u8INTID += 7;
			SCB_->SHPR2 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );

		}
		else if( Copy_u8INTID == PEND_SV || Copy_u8INTID == SYSTICK ){

			Copy_u8INTID += 8;

			SCB_->SHPR3 = ( Priority ) << ( (8 * Copy_u8INTID) + 4 );

		}

	}
    //External Peripheral
	else if( Copy_u8INTID >= 0 ){
		MNVIC->IPR[ Copy_u8INTID ] = Priority << 4 ;
	}
}

void NVIC_voidSetPriorityConfig(u32 Copy_u32PriprityOption)
{
    StaticGlobal_u32PriorityConfig =Copy_u32PriprityOption;
    SCB_ -> AIRCR = StaticGlobal_u32PriorityConfig;
}

void NVIC_voidMakeSoftwareInterrupt(u32 Copy_u32InterruptID)
{
	MNVIC -> STIR = Copy_u32InterruptID;
}
