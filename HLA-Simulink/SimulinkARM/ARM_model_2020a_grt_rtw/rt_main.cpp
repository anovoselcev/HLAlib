/*
 * Code generation for Simulink model "ARM_model_2020a"
 *
 * File version               : 9.3 (R2020a) 18-Nov-2019
 * File generated on          : Fri Jan 29 13:13:21 2021
 * C source code generated on : Fri Jan 29 13:13:21 2021
 *
 * Compiler specified defines:
 *   RT
 *   MODEL           = ARM_model_2020a
 *   NUMST           = 1 (Number of sample times)
 *   NCSTATES        = 0 (Number of continuous states)
 *   TID01EQ         = 0
 *                     (Set to 1 if sample time task id's 0 and 1 have equal rates)
 *
 * For more information:
 *   o Simulink Coder User's Guide
 */

#ifndef _WIN32
#define _WIN32
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT                   0x0500
#endif

#include <windows.h>
#include <process.h>
#include "rtmodel.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <float.h>
#include "ARM_model_2020a.h"           /* Model's header file */
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef EXIT_FAILURE
#define EXIT_FAILURE                   1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS                   0
#endif

#define RUN_FOREVER                    -1.0
#define MdlInitializeSizes()                                     /* No op */
#define MdlInitializeSampleTimes()                               /* No op */
#define MdlStart()                                               /* No op */
#define MdlOutputs()                   ARM_model_2020a_Obj.step()
#define MdlUpdate()                                              /* No Op */
#define MdlTerminate()                 ARM_model_2020a_Obj.terminate()
#define rt_CreateIntegrationData(S)                              /* No op */
#define rt_UpdateContinuousStates(S)                             /* No op */

/*==================================*
 * Global data local to this module *
 *==================================*/
static struct {
  int_T stopExecutionFlag;
  int_T isrOverrun;
  int_T overrunFlags[NUMST];
  const char_T *errmsg;
} GBLbuf;

static ARM_model_2020aModelClass ARM_model_2020a_Obj;/* Instance of model class */

#define CHECK_STATUS(status,fcn)       if (status != 0) {fprintf(stderr, "Call to %s returned error status (%d).\n", (fcn),(status)); perror((fcn)); fflush(stderr); exit(EXIT_FAILURE);}

typedef struct {
  HANDLE threadHandle;
  unsigned threadID;
  int_T index;
  HANDLE startEvent;
  HANDLE stopEvent;
  LONG exitFlag;
} ThreadInfo;

ThreadInfo periodicThread[1];
ThreadInfo periodicTriggerThread[1];
int threadPriority[4] = { THREAD_PRIORITY_ABOVE_NORMAL,
  THREAD_PRIORITY_NORMAL,
  THREAD_PRIORITY_BELOW_NORMAL,
  THREAD_PRIORITY_LOWEST };

HANDLE rtClock[1];
HANDLE quitEvent = NULL;
BOOL OnCtrlHandler(DWORD ctrl)
{
  SetEvent(quitEvent);
  return true;
}

unsigned __stdcall baseRateTaskScheduler(void *arg)
{
  volatile boolean_T noErr;
  DWORD waitResult;
  HANDLE orTimer;
  LARGE_INTEGER orDueTime;
  HANDLE eventArray[2];
  int_T taskId[1] = { 0 };

  noErr = (rtmGetErrorStatus(ARM_model_2020a_Obj.getRTM()) == (NULL));
  eventArray[0] = quitEvent;
  eventArray[1] = rtClock[0];
  orTimer = CreateWaitableTimer(NULL, false, NULL);
  orDueTime.QuadPart = (LONGLONG)(0.2 * 1e7 * -1);
  while (noErr) {
    /* Wait for the next event from the timer */
    waitResult = WaitForMultipleObjects(2, eventArray, false, INFINITE);
    if ((waitResult == WAIT_OBJECT_0) || (waitResult == WAIT_FAILED)) {
      /* The quitEvent is set or the wait failed */
      noErr = false;
      continue;
    }

    CHECK_STATUS(SetWaitableTimer(orTimer, &orDueTime, 0, NULL, NULL, false) ==
                 false, "SetWaitableTimer");
    waitResult = WaitForSingleObject(periodicThread[taskId[0]].stopEvent, 0);
    if (waitResult == WAIT_TIMEOUT) {
      printf("Overrun - rate for periodic task %d too fast.\n", taskId[0]);
      WaitForSingleObject(periodicThread[taskId[0]].stopEvent,INFINITE);
    }

    noErr = (rtmGetErrorStatus(ARM_model_2020a_Obj.getRTM()) == (NULL));
    if (noErr) {
      SetEvent(periodicThread[taskId[0]].startEvent);
    }

    if (WaitForSingleObject(orTimer, 0) == WAIT_OBJECT_0) {
      printf("Overrun - periodic trigger 0 base rate too fast.\n");
    }
  }                                    /* while */

  InterlockedIncrement(&periodicThread[taskId[0]].exitFlag);
  SetEvent(periodicThread[taskId[0]].startEvent);
  _endthreadex(0);
  return 0;
}

unsigned __stdcall periodicTask(void *arg)
{
  DWORD waitResult;
  ThreadInfo* info = (ThreadInfo*)arg;
  volatile boolean_T noErr = true;
  while (noErr) {
    waitResult = WaitForSingleObject(info->startEvent,INFINITE);
    if ((waitResult != WAIT_OBJECT_0) || info->exitFlag) {
      /* Wait failed or exitFlag is set */
      noErr = false;
      continue;
    }

    MdlOutputs();
    MdlUpdate();
    SetEvent(info->stopEvent);
  }

  _endthreadex(0);
  return 0;
}

int main(int argc, char *argv[])
{
  int i;
  LARGE_INTEGER stNanoSec;
  LONG stMilliPeriod;
  int priority[1];

  /* Unused arguments */
  (void)(argc);
  (void)(argv);
  priority[0] = threadPriority[0];
  CHECK_STATUS(SetConsoleCtrlHandler((PHANDLER_ROUTINE)OnCtrlHandler, true) ==
               false, "SetConsoleCtrlHandler");
  for (i = 0; i < 1; i++) {
    rtClock[i] = NULL;
  }

  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(ARM_model_2020a_Obj.getRTM(), 0);

  /* Set the priority of the main thread */
  CHECK_STATUS(SetThreadPriority(GetCurrentThread(),
    THREAD_PRIORITY_TIME_CRITICAL) == false, "SetThreadPriority");

  /* Create & initialize events used for thread synchronization */
  quitEvent = CreateEvent(NULL, true, false, NULL);
  CHECK_STATUS(quitEvent == NULL,"CreateEvent");
  for (i = 0; i < 1; i++) {
    rtClock[i] = CreateWaitableTimer(NULL, false, NULL);
    CHECK_STATUS(rtClock[i] == NULL,"CreateWaitableTimer");
  }

  /************************
   * Initialize the model *
   ************************/

  /* Initialize model */
  ARM_model_2020a_Obj.initialize();
  if (rtmGetErrorStatus(ARM_model_2020a_Obj.getRTM()) != (NULL)) {
    puts("Error during model registration");
    exit(EXIT_FAILURE);
  }

  MdlInitializeSizes();
  MdlInitializeSampleTimes();
  MdlStart();

  /* Create periodic threads */
  for (i = 0; i < 1; i++) {
    periodicThread[i].index = (int_T) i;
    periodicThread[i].exitFlag = 0;

    /* Create the events that will be used by the thread */
    periodicThread[i].startEvent = CreateEvent(NULL, false, false, NULL);
    CHECK_STATUS(periodicThread[i].startEvent == NULL, "CreateEvent");
    periodicThread[i].stopEvent = CreateEvent(NULL, false, true, NULL);
    CHECK_STATUS(periodicThread[i].stopEvent == NULL, "CreateStopEventEvent");

    /* Create the thread in suspended mode */
    periodicThread[i].threadHandle = (HANDLE)_beginthreadex(NULL, 0,
      &periodicTask, &periodicThread[i], CREATE_SUSPENDED, &periodicThread[i].
      threadID);
    CHECK_STATUS(periodicThread[i].threadID == 0,"_beginthreadex");

    /* Set the thread priority */
    CHECK_STATUS(SetThreadPriority(periodicThread[i].threadHandle, priority[i]) ==
                 false, "SetThreadPriority");

    /* Start the thread */
    CHECK_STATUS(ResumeThread(periodicThread[i].threadHandle) == -1,
                 "ResumeThread");
  }

  /* Create periodic trigger threads */
  {
    periodicTriggerThread[0].index = 0;
    periodicTriggerThread[0].exitFlag = 0;
    periodicTriggerThread[0].startEvent = NULL;
    periodicTriggerThread[0].stopEvent = NULL;

    /* Create the thread in suspended mode */
    periodicTriggerThread[0].threadHandle = (HANDLE)_beginthreadex(NULL, 0,
      &baseRateTaskScheduler, NULL, CREATE_SUSPENDED, &periodicTriggerThread[0].
      threadID);
    CHECK_STATUS(periodicTriggerThread[0].threadHandle == 0,"_beginthreadex");

    /* Set the periodic trigger thread priority */
    CHECK_STATUS(SetThreadPriority(periodicTriggerThread[0].threadHandle,
      THREAD_PRIORITY_HIGHEST) == false, "SetThreadPriority");

    /* Start the periodic trigger thread */
    CHECK_STATUS(ResumeThread(periodicTriggerThread[0].threadHandle) == -1,
                 "ResumeThread");
  }

  /* Real-time scheduling timer */
  stNanoSec.QuadPart = (LONGLONG)(0.2 * 1e7 * -1);
  stMilliPeriod = (LONG)(0.2 * 1e3);
  CHECK_STATUS(SetWaitableTimer(rtClock[0], &stNanoSec, stMilliPeriod, NULL,
    NULL, false) == false, "SetWaitableTimer");

  /* Wait for a stopping condition. */
  for (i = 0; i < 1; i++) {
    WaitForSingleObject(periodicTriggerThread[i].threadHandle, INFINITE);
  }

  /* Clean up */
  for (i = 0; i< 1; i++) {
    if (rtClock[i] != NULL) {
      CloseHandle(rtClock[i]);
    }

    if (periodicTriggerThread[i].threadHandle != NULL) {
      CloseHandle(periodicTriggerThread[i].threadHandle);
    }
  }

  if (quitEvent != NULL) {
    CloseHandle(quitEvent);
  }

  for (i = 0; i < 1; i++) {
    if (periodicThread[i].startEvent != NULL) {
      CloseHandle(periodicThread[i].startEvent);
    }

    if (periodicThread[i].stopEvent != NULL) {
      CloseHandle(periodicThread[i].stopEvent);
    }

    if (periodicThread[i].threadHandle != NULL) {
      CloseHandle(periodicThread[i].threadHandle);
    }
  }

  printf("**stopping the model**\n");
  fflush(stdout);
  if (rtmGetErrorStatus(ARM_model_2020a_Obj.getRTM()) != NULL) {
    fprintf(stderr, "\n**%s**\n", rtmGetErrorStatus(ARM_model_2020a_Obj.getRTM()));
  }

  MdlTerminate();
  return 0;
}
