/***********************************/
/* SWC:     SCHEDULER Driver       */
/* Author:  Youssef Goher          */
/* Version: V1                     */
/* Date:    11 June 2023           */
/***********************************/
/*File Gaurd*/
#ifndef SCHEDULER_PRIVATE_H
#define SCHEDULER_PRIVATE_H

static void Scheduler_SchedulerWork(void);

typedef struct 
{
    void (*pf)(void);
    u32 TeskPeriodicity;
    u32 TaskFristDelay;
}TCB_T;

TCB_T Tasks_Arr[SCHEDULER_NO_OF_TESKS]={NULL};


#endif
