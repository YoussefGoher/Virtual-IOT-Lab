/*
 * MEXTI_Configurations.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Ibrahim Refaey
 */


#include "BIT_MATH.h"
#include "STD_Types.h"
#include "MEXTI_Interface.h"
#include "MEXTI_private.h"
#include "MEXTI_Config.h"


/*
 * MEXTI_Configuartions {
	 * Line
	 * Port
	 * Mode
	 * Initial Value
 * }
 */


MEXTI_Configuartions MEXTI_Config [MEXTI_NUMBER] =
{
		{
				MEXTI_LINE0,
				MEXTI_PORTA,
				MEXTI_FALLING_EDGE,
				MEXTI_DISABLED
		}
		,
		{
				MEXTI_LINE2,
				MEXTI_PORTB,
				MEXTI_RISING_EDGE,
				MEXTI_ENABLED
		}
		,
		{
				MEXTI_LINE3,
				MEXTI_PORTA,
				MEXTI_ON_CHANGE,
				MEXTI_DISABLED
		}
};


