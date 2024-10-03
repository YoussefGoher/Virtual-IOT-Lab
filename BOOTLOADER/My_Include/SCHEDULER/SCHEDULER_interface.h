/***********************************/
/* SWC:     SCHEDULER Driver       */
/* Author:  Youssef Goher          */
/* Version: V1                     */
/* Date:    11 June 2023           */
/***********************************/
/*File Gaurd*/
#ifndef SCHEDULER_INTERFACE_H
#define SCHEDULER_INTERFACE_H

void Scheduler_voidSchedulerStart(void);
void Scheduler_voidCreatTesk(u8 copy_u8TeskPriority,u32 copy_u32TeskPeriodicity,void (*pf)(void),u32 copy_u32TaskFristDelay);
void Scheduler_voidSchedulerStop(void);

#endif