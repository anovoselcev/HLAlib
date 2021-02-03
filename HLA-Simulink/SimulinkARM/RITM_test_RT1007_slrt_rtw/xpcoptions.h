#ifndef __RITM_test_RT1007_XPCOPTIONS_H___
#define __RITM_test_RT1007_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "RITM_test_RT1007.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                1
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_RITM_test_RT1007_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  1
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            2048
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0
#define SLRTFTZOFFFLAG                 0

/* Change all stepsize using the newBaseRateStepSize */
void RITM_test_RT1007_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_RITM_test_RT1007_T *const RITM_test_RT1007_M)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  RITM_test_RT1007_M->Timing.stepSize0 = RITM_test_RT1007_M->Timing.stepSize0 *
    ratio;
  RITM_test_RT1007_M->Timing.stepSize1 = RITM_test_RT1007_M->Timing.stepSize1 *
    ratio;
  RITM_test_RT1007_M->Timing.stepSize2 = RITM_test_RT1007_M->Timing.stepSize2 *
    ratio;
  RITM_test_RT1007_M->Timing.stepSize = RITM_test_RT1007_M->Timing.stepSize *
    ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  RITM_test_RT1007_ChangeStepSize(stepSize, RITM_test_RT1007_M);
}

void XPCCALLCONV SLRTSetErrorStatus(const char * errMsg)
{
  rtmSetErrorStatus(RITM_test_RT1007_M, errMsg);
}

#endif                                 /* __RITM_test_RT1007_XPCOPTIONS_H___ */
