/***********************************/
/* SWC:     SCHEDULER Driver       */
/* Author:  Youssef Goher          */
/* Version: V1                     */
/* Date:    11 June 2023           */
/***********************************/

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "SCHEDULER_config.h"
#include "SCHEDULER_interface.h"
#include "SCHEDULER_private.h"
#include "MSTK_interface.h"

void Scheduler_voidSchedulerStart(void){
MSTK_voidInit();
MSTK_voidSetIntervalPeriodic(SCHEDULER_SYS_Tick_Time_MS,&Scheduler_SchedulerWork);
}

void Scheduler_voidCreatTesk(u8 copy_u8TeskPriority,u32 copy_u32TeskPeriodicity,void (*PF)(void),u32 copy_u32TaskFristDelay){
    if(copy_u8TeskPriority>SCHEDULER_NO_OF_TESKS){
        //do nothing
    }
    else{
        Tasks_Arr[copy_u8TeskPriority].TeskPeriodicity=copy_u32TeskPeriodicity;
        Tasks_Arr[copy_u8TeskPriority].TaskFristDelay=copy_u32TaskFristDelay;
        Tasks_Arr[copy_u8TeskPriority].pf=PF;
    }
}

void Scheduler_voidSchedulerStop(void){
	MSTK_voiDisableSTK();
}

static void Scheduler_SchedulerWork(void){
    u8 Local_u8counter;
    for(Local_u8counter=0;Local_u8counter<SCHEDULER_NO_OF_TESKS;Local_u8counter++){
        if(Tasks_Arr[Local_u8counter].TaskFristDelay==0){
                if (Tasks_Arr[Local_u8counter].pf!=NULL)
                {
                    Tasks_Arr[Local_u8counter].pf();
                }
                Tasks_Arr[Local_u8counter].TaskFristDelay=Tasks_Arr[Local_u8counter].TeskPeriodicity-1;
            }
        else{
            Tasks_Arr[Local_u8counter].TaskFristDelay--;
        }
    }
}
