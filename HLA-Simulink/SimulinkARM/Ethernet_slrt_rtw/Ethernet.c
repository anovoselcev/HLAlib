/*
 * Ethernet.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Ethernet".
 *
 * Model version              : 1.29
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Feb  3 18:21:41 2021
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "Ethernet_capi.h"
#include "Ethernet.h"
#include "Ethernet_private.h"

/* Block signals (default storage) */
B_Ethernet_T Ethernet_B;

/* Block states (default storage) */
DW_Ethernet_T Ethernet_DW;

/* Real-time model */
RT_MODEL_Ethernet_T Ethernet_M_;
RT_MODEL_Ethernet_T *const Ethernet_M = &Ethernet_M_;

/* Model output function */
static void Ethernet_output(void)
{
  int32_T i;
  real_T tmp;

  /* Outputs for Atomic SubSystem: '<Root>/Ethernet' */
  /* S-Function (slrtIPConfig): '<S1>/UDP Configure' */

  /* Level2 S-Function Block: '<S1>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = Ethernet_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Sin: '<S1>/Sine Wave1' */
  if (Ethernet_DW.systemEnable != 0) {
    Ethernet_DW.lastSin = sin(Ethernet_P.SineWave1_Freq * Ethernet_M->Timing.t[0]);
    Ethernet_DW.lastCos = cos(Ethernet_P.SineWave1_Freq * Ethernet_M->Timing.t[0]);
    Ethernet_DW.systemEnable = 0;
  }

  Ethernet_B.SineWave1 = ((Ethernet_DW.lastSin * Ethernet_P.SineWave1_PCos +
    Ethernet_DW.lastCos * Ethernet_P.SineWave1_PSin) * Ethernet_P.SineWave1_HCos
    + (Ethernet_DW.lastCos * Ethernet_P.SineWave1_PCos - Ethernet_DW.lastSin *
       Ethernet_P.SineWave1_PSin) * Ethernet_P.SineWave1_Hsin) *
    Ethernet_P.SineWave1_Amp + Ethernet_P.SineWave1_Bias;

  /* End of Sin: '<S1>/Sine Wave1' */

  /* S-Function (xpcbytepacking): '<S1>/Byte Packing 2' */

  /* Byte Packing: <S1>/Byte Packing 2 */
  (void)memcpy((uint8_T*)&Ethernet_B.BytePacking2[0] + 0, (uint8_T*)
               &Ethernet_B.SineWave1, 8);

  /* Sin: '<S1>/Sine Wave5' */
  if (Ethernet_DW.systemEnable_e != 0) {
    Ethernet_DW.lastSin_n = sin(Ethernet_P.SineWave5_Freq * Ethernet_M->
      Timing.t[0]);
    Ethernet_DW.lastCos_n = cos(Ethernet_P.SineWave5_Freq * Ethernet_M->
      Timing.t[0]);
    Ethernet_DW.systemEnable_e = 0;
  }

  Ethernet_B.SineWave5 = ((Ethernet_DW.lastSin_n * Ethernet_P.SineWave5_PCos +
    Ethernet_DW.lastCos_n * Ethernet_P.SineWave5_PSin) *
    Ethernet_P.SineWave5_HCos + (Ethernet_DW.lastCos_n *
    Ethernet_P.SineWave5_PCos - Ethernet_DW.lastSin_n *
    Ethernet_P.SineWave5_PSin) * Ethernet_P.SineWave5_Hsin) *
    Ethernet_P.SineWave5_Amp + Ethernet_P.SineWave5_Bias;

  /* End of Sin: '<S1>/Sine Wave5' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  tmp = floor(Ethernet_B.SineWave5);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  Ethernet_B.DataTypeConversion = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (xpcbytepacking): '<S1>/Byte Packing 6' */

  /* Byte Packing: <S1>/Byte Packing 6 */
  (void)memcpy((uint8_T*)&Ethernet_B.BytePacking6[0] + 0, (uint8_T*)
               &Ethernet_B.DataTypeConversion, 4);

  /* Sin: '<S1>/Sine Wave6' */
  if (Ethernet_DW.systemEnable_m != 0) {
    Ethernet_DW.lastSin_k = sin(Ethernet_P.SineWave6_Freq * Ethernet_M->
      Timing.t[0]);
    Ethernet_DW.lastCos_g = cos(Ethernet_P.SineWave6_Freq * Ethernet_M->
      Timing.t[0]);
    Ethernet_DW.systemEnable_m = 0;
  }

  Ethernet_B.SineWave6 = ((Ethernet_DW.lastSin_k * Ethernet_P.SineWave6_PCos +
    Ethernet_DW.lastCos_g * Ethernet_P.SineWave6_PSin) *
    Ethernet_P.SineWave6_HCos + (Ethernet_DW.lastCos_g *
    Ethernet_P.SineWave6_PCos - Ethernet_DW.lastSin_k *
    Ethernet_P.SineWave6_PSin) * Ethernet_P.SineWave6_Hsin) *
    Ethernet_P.SineWave6_Amp + Ethernet_P.SineWave6_Bias;

  /* End of Sin: '<S1>/Sine Wave6' */

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  tmp = floor(Ethernet_B.SineWave6);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  Ethernet_B.DataTypeConversion1 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion1' */

  /* S-Function (xpcbytepacking): '<S1>/Byte Packing 7' */

  /* Byte Packing: <S1>/Byte Packing 7 */
  (void)memcpy((uint8_T*)&Ethernet_B.BytePacking7[0] + 0, (uint8_T*)
               &Ethernet_B.DataTypeConversion1, 2);

  /* SignalConversion generated from: '<S1>/UDP Send1' */
  for (i = 0; i < 8; i++) {
    Ethernet_B.TmpSignalConversionAtUDPSend1In[i] = Ethernet_B.BytePacking2[i];
  }

  Ethernet_B.TmpSignalConversionAtUDPSend1In[8] = Ethernet_B.BytePacking6[0];
  Ethernet_B.TmpSignalConversionAtUDPSend1In[9] = Ethernet_B.BytePacking6[1];
  Ethernet_B.TmpSignalConversionAtUDPSend1In[10] = Ethernet_B.BytePacking6[2];
  Ethernet_B.TmpSignalConversionAtUDPSend1In[11] = Ethernet_B.BytePacking6[3];
  Ethernet_B.TmpSignalConversionAtUDPSend1In[12] = Ethernet_B.BytePacking7[0];
  Ethernet_B.TmpSignalConversionAtUDPSend1In[13] = Ethernet_B.BytePacking7[1];

  /* End of SignalConversion generated from: '<S1>/UDP Send1' */

  /* S-Function (slrtUDPSend): '<S1>/UDP Send1' */

  /* Level2 S-Function Block: '<S1>/UDP Send1' (slrtUDPSend) */
  {
    SimStruct *rts = Ethernet_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* End of Outputs for SubSystem: '<Root>/Ethernet' */
}

/* Model update function */
static void Ethernet_update(void)
{
  real_T HoldSine;
  real_T HoldCosine;

  /* Update for Atomic SubSystem: '<Root>/Ethernet' */
  /* Update for Sin: '<S1>/Sine Wave1' */
  HoldSine = Ethernet_DW.lastSin;
  HoldCosine = Ethernet_DW.lastCos;
  Ethernet_DW.lastSin = HoldSine * Ethernet_P.SineWave1_HCos + HoldCosine *
    Ethernet_P.SineWave1_Hsin;
  Ethernet_DW.lastCos = HoldCosine * Ethernet_P.SineWave1_HCos - HoldSine *
    Ethernet_P.SineWave1_Hsin;

  /* Update for Sin: '<S1>/Sine Wave5' */
  HoldSine = Ethernet_DW.lastSin_n;
  HoldCosine = Ethernet_DW.lastCos_n;
  Ethernet_DW.lastSin_n = HoldSine * Ethernet_P.SineWave5_HCos + HoldCosine *
    Ethernet_P.SineWave5_Hsin;
  Ethernet_DW.lastCos_n = HoldCosine * Ethernet_P.SineWave5_HCos - HoldSine *
    Ethernet_P.SineWave5_Hsin;

  /* Update for Sin: '<S1>/Sine Wave6' */
  HoldSine = Ethernet_DW.lastSin_k;
  HoldCosine = Ethernet_DW.lastCos_g;
  Ethernet_DW.lastSin_k = HoldSine * Ethernet_P.SineWave6_HCos + HoldCosine *
    Ethernet_P.SineWave6_Hsin;
  Ethernet_DW.lastCos_g = HoldCosine * Ethernet_P.SineWave6_HCos - HoldSine *
    Ethernet_P.SineWave6_Hsin;

  /* End of Update for SubSystem: '<Root>/Ethernet' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Ethernet_M->Timing.clockTick0)) {
    ++Ethernet_M->Timing.clockTickH0;
  }

  Ethernet_M->Timing.t[0] = Ethernet_M->Timing.clockTick0 *
    Ethernet_M->Timing.stepSize0 + Ethernet_M->Timing.clockTickH0 *
    Ethernet_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void Ethernet_initialize(void)
{
  /* Start for Atomic SubSystem: '<Root>/Ethernet' */
  /* Start for S-Function (slrtIPConfig): '<S1>/UDP Configure' */
  /* Level2 S-Function Block: '<S1>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = Ethernet_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Width: '<S1>/Width1' */
  Ethernet_B.Width1 = 14.0;

  /* Start for S-Function (slrtUDPSend): '<S1>/UDP Send1' */
  /* Level2 S-Function Block: '<S1>/UDP Send1' (slrtUDPSend) */
  {
    SimStruct *rts = Ethernet_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<Root>/Ethernet' */

  /* Enable for Atomic SubSystem: '<Root>/Ethernet' */
  /* Enable for Sin: '<S1>/Sine Wave1' */
  Ethernet_DW.systemEnable = 1;

  /* Enable for Sin: '<S1>/Sine Wave5' */
  Ethernet_DW.systemEnable_e = 1;

  /* Enable for Sin: '<S1>/Sine Wave6' */
  Ethernet_DW.systemEnable_m = 1;

  /* End of Enable for SubSystem: '<Root>/Ethernet' */
}

/* Model terminate function */
static void Ethernet_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Ethernet' */

  /* Terminate for S-Function (slrtIPConfig): '<S1>/UDP Configure' */
  /* Level2 S-Function Block: '<S1>/UDP Configure' (slrtIPConfig) */
  {
    SimStruct *rts = Ethernet_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (slrtUDPSend): '<S1>/UDP Send1' */
  /* Level2 S-Function Block: '<S1>/UDP Send1' (slrtUDPSend) */
  {
    SimStruct *rts = Ethernet_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/Ethernet' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Ethernet_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Ethernet_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Ethernet_initialize();
}

void MdlTerminate(void)
{
  Ethernet_terminate();
}

/* Registration function */
RT_MODEL_Ethernet_T *Ethernet(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Ethernet_M, 0,
                sizeof(RT_MODEL_Ethernet_T));
  rtsiSetSolverName(&Ethernet_M->solverInfo,"FixedStepDiscrete");
  Ethernet_M->solverInfoPtr = (&Ethernet_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Ethernet_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Ethernet_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Ethernet_M->Timing.sampleTimes = (&Ethernet_M->Timing.sampleTimesArray[0]);
    Ethernet_M->Timing.offsetTimes = (&Ethernet_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Ethernet_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    Ethernet_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Ethernet_M, &Ethernet_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Ethernet_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Ethernet_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Ethernet_M, -1);
  Ethernet_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Ethernet_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Ethernet_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Ethernet_M->rtwLogInfo, (NULL));
    rtliSetLogT(Ethernet_M->rtwLogInfo, "tout");
    rtliSetLogX(Ethernet_M->rtwLogInfo, "");
    rtliSetLogXFinal(Ethernet_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Ethernet_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Ethernet_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(Ethernet_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Ethernet_M->rtwLogInfo, 1);
    rtliSetLogY(Ethernet_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Ethernet_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Ethernet_M->rtwLogInfo, (NULL));
  }

  Ethernet_M->solverInfoPtr = (&Ethernet_M->solverInfo);
  Ethernet_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Ethernet_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Ethernet_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Ethernet_M->blockIO = ((void *) &Ethernet_B);
  (void) memset(((void *) &Ethernet_B), 0,
                sizeof(B_Ethernet_T));

  /* parameters */
  Ethernet_M->defaultParam = ((real_T *)&Ethernet_P);

  /* states (dwork) */
  Ethernet_M->dwork = ((void *) &Ethernet_DW);
  (void) memset((void *)&Ethernet_DW, 0,
                sizeof(DW_Ethernet_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  Ethernet_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Ethernet_M->NonInlinedSFcns.sfcnInfo;
    Ethernet_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Ethernet_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Ethernet_M->Sizes.numSampTimes);
    Ethernet_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Ethernet_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,Ethernet_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Ethernet_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Ethernet_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Ethernet_M));
    rtssSetStepSizePtr(sfcnInfo, &Ethernet_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Ethernet_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &Ethernet_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &Ethernet_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Ethernet_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &Ethernet_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Ethernet_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Ethernet_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Ethernet_M->solverInfoPtr);
  }

  Ethernet_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&Ethernet_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    Ethernet_M->childSfunctions =
      (&Ethernet_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Ethernet_M->childSfunctions[0] =
      (&Ethernet_M->NonInlinedSFcns.childSFunctions[0]);
    Ethernet_M->childSfunctions[1] =
      (&Ethernet_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: Ethernet/<S1>/UDP Configure (slrtIPConfig) */
    {
      SimStruct *rts = Ethernet_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Ethernet_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Ethernet_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Ethernet_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Ethernet_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Ethernet_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Ethernet_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Ethernet_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Ethernet_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Ethernet_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Ethernet_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Ethernet_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* path info */
      ssSetModelName(rts, "UDP Configure");
      ssSetPath(rts, "Ethernet/Ethernet/UDP Configure");
      ssSetRTModel(rts,Ethernet_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Ethernet_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Ethernet_P.UDPConfigure_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Ethernet_P.UDPConfigure_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Ethernet_P.UDPConfigure_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Ethernet_P.UDPConfigure_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Ethernet_P.UDPConfigure_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Ethernet_P.UDPConfigure_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)Ethernet_P.UDPConfigure_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)Ethernet_P.UDPConfigure_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)Ethernet_P.UDPConfigure_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)Ethernet_P.UDPConfigure_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)Ethernet_P.UDPConfigure_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)Ethernet_P.UDPConfigure_P12_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &Ethernet_DW.UDPConfigure_IWORK[0]);
      ssSetPWork(rts, (void **) &Ethernet_DW.UDPConfigure_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Ethernet_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Ethernet_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Ethernet_DW.UDPConfigure_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Ethernet_DW.UDPConfigure_PWORK[0]);
      }

      /* registration */
      slrtIPConfig(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Ethernet/<S1>/UDP Send1 (slrtUDPSend) */
    {
      SimStruct *rts = Ethernet_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Ethernet_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Ethernet_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Ethernet_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Ethernet_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Ethernet_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Ethernet_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Ethernet_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Ethernet_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Ethernet_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Ethernet_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &Ethernet_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &Ethernet_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Ethernet_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Ethernet_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               Ethernet_B.TmpSignalConversionAtUDPSend1In);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 14);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &Ethernet_B.Width1);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "UDP Send1");
      ssSetPath(rts, "Ethernet/Ethernet/UDP Send1");
      ssSetRTModel(rts,Ethernet_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Ethernet_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Ethernet_P.UDPSend1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Ethernet_P.UDPSend1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Ethernet_P.UDPSend1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Ethernet_P.UDPSend1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Ethernet_P.UDPSend1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)Ethernet_P.UDPSend1_P6_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &Ethernet_DW.UDPSend1_IWORK[0]);
      ssSetPWork(rts, (void **) &Ethernet_DW.UDPSend1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Ethernet_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Ethernet_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Ethernet_DW.UDPSend1_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Ethernet_DW.UDPSend1_PWORK);
      }

      /* registration */
      slrtUDPSend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 14);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  Ethernet_M->Sizes.numContStates = (0);/* Number of continuous states */
  Ethernet_M->Sizes.numY = (0);        /* Number of model outputs */
  Ethernet_M->Sizes.numU = (0);        /* Number of model inputs */
  Ethernet_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Ethernet_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Ethernet_M->Sizes.numBlocks = (13);  /* Number of blocks */
  Ethernet_M->Sizes.numBlockIO = (10); /* Number of block outputs */
  Ethernet_M->Sizes.numBlockPrms = (99);/* Sum of parameter "widths" */
  return Ethernet_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
