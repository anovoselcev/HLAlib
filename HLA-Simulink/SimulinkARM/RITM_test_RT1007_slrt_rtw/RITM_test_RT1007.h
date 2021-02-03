/*
 * RITM_test_RT1007.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RITM_test_RT1007".
 *
 * Model version              : 1.136
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Fri Jan 29 11:05:46 2021
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RITM_test_RT1007_h_
#define RTW_HEADER_RITM_test_RT1007_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef RITM_test_RT1007_COMMON_INCLUDES_
# define RITM_test_RT1007_COMMON_INCLUDES_
#include <xpcimports.h>
#include <string.h>
#include <math.h>
#include <serialdefines.h>
#include <xpctarget.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "can_message.h"
#include "xpctarget.h"
#include "xpcimports.h"
#endif                                 /* RITM_test_RT1007_COMMON_INCLUDES_ */

#include "RITM_test_RT1007_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtw_xpc.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
# define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
# define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
# define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
# define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
# define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
# define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_RITM_test_RT1007       RT_MODEL_RITM_test_RT1007_T

/* Definition for use in the target main file */
#define RITM_test_RT1007_rtModel       RT_MODEL_RITM_test_RT1007_T

/* user code (top of export header file) */
#include "can_message.h"

/* Block signals (default storage) */
typedef struct {
  CAN_DATATYPE CA_MA_rx_o2;            /* '<S6>/CA_MA_rx' */
  CAN_DATATYPE CANPack;                /* '<S6>/CAN Pack' */
  CAN_DATATYPE CA_MA_rx1_o2;           /* '<S6>/CA_MA_rx1' */
  serialfifoptr RateTransition1;       /* '<S24>/Rate Transition1' */
  serialfifoptr FIFOwrite1_o1;         /* '<S24>/FIFO write 1' */
  serialfifoptr FIFOwrite2_o1;         /* '<S24>/FIFO write 2' */
  serialfifoptr RateTransition3;       /* '<S24>/Rate Transition3' */
  serialfifoptr FIFOwrite1_o1_o;       /* '<S23>/FIFO write 1' */
  serialfifoptr FIFOwrite2_o1_f;       /* '<S23>/FIFO write 2' */
  serialfifoptr RateTransition1_j;     /* '<S23>/Rate Transition1' */
  serialfifoptr RateTransition3_e;     /* '<S23>/Rate Transition3' */
  serialfifoptr RateTransition;        /* '<S23>/Rate Transition' */
  serialfifoptr RateTransition2;       /* '<S23>/Rate Transition2' */
  serialfifoptr RateTransition_d;      /* '<S24>/Rate Transition' */
  serialfifoptr RateTransition2_p;     /* '<S24>/Rate Transition2' */
  serialfifoptr FIFOwrite2;            /* '<S33>/FIFO write 2' */
  serialfifoptr FIFOwrite1;            /* '<S32>/FIFO write 1' */
  serialfifoptr FIFOwrite2_e;          /* '<S28>/FIFO write 2' */
  serialfifoptr FIFOwrite1_e;          /* '<S27>/FIFO write 1' */
  real_T ASCIIDecode;                  /* '<S7>/ASCII Decode ' */
  real_T SineWave;                     /* '<S7>/Sine Wave' */
  real_T CANUnpack_o1;                 /* '<S6>/CAN Unpack' */
  real_T CANUnpack_o3;                 /* '<S6>/CAN Unpack' */
  real_T SineWave_k;                   /* '<S6>/Sine Wave' */
  real_T BAISCAP_o1;                   /* '<S3>/BA-IS-CAP' */
  real_T BAISCAP_o2;                   /* '<S3>/BA-IS-CAP' */
  real_T BAISCAP1_o1;                  /* '<S3>/BA-IS-CAP1' */
  real_T BAISCAP1_o2;                  /* '<S3>/BA-IS-CAP1' */
  real_T BAISCAP2_o1;                  /* '<S3>/BA-IS-CAP2' */
  real_T BAISCAP2_o2;                  /* '<S3>/BA-IS-CAP2' */
  real_T BAISCAP3_o1;                  /* '<S3>/BA-IS-CAP3' */
  real_T BAISCAP3_o2;                  /* '<S3>/BA-IS-CAP3' */
  real_T Constant1;                    /* '<S3>/Constant1' */
  real_T Constant8;                    /* '<S3>/Constant8' */
  real_T Constant2;                    /* '<S3>/Constant2' */
  real_T Constant3;                    /* '<S3>/Constant3' */
  real_T BA_IS_gpio_di_o1;             /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o2;             /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o3;             /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o4;             /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o5;             /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o6;             /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o7;             /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o8;             /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o9;             /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o10;            /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o11;            /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o12;            /* '<S1>/BA_IS_gpio_di' */
  real_T BA_IS_gpio_di_o13;            /* '<S1>/BA_IS_gpio_di' */
  real_T Twiceasecond;                 /* '<S1>/Twice a second' */
  uint32_T ReadIntStatusFC1_o2;        /* '<S31>/Read Int Status FC1' */
  uint32_T FIFOread2_o1[61];           /* '<S35>/FIFO read 2' */
  uint32_T FIFOread2_o2;               /* '<S35>/FIFO read 2' */
  uint32_T ReadHWFIFO2[65];            /* '<S33>/Read HW FIFO2' */
  uint32_T FIFOread1_o1[61];           /* '<S34>/FIFO read 1' */
  uint32_T FIFOread1_o2;               /* '<S34>/FIFO read 1' */
  uint32_T ReadHWFIFO1[65];            /* '<S32>/Read HW FIFO1' */
  uint32_T ReadIntStatusFC1_o2_o;      /* '<S26>/Read Int Status FC1' */
  uint32_T FIFOread2_o1_h[61];         /* '<S30>/FIFO read 2' */
  uint32_T FIFOread2_o2_g;             /* '<S30>/FIFO read 2' */
  uint32_T ReadHWFIFO2_e[65];          /* '<S28>/Read HW FIFO2' */
  uint32_T FIFOread1_o1_e[61];         /* '<S29>/FIFO read 1' */
  uint32_T FIFOread1_o2_k;             /* '<S29>/FIFO read 1' */
  uint32_T ReadHWFIFO1_b[65];          /* '<S27>/Read HW FIFO1' */
  uint32_T CANUnpack_o2;               /* '<S6>/CAN Unpack' */
  uint32_T BAISUART_rx_o2;             /* '<S5>/BA-IS-UART_rx' */
  uint32_T BAISUART_rx_o3;             /* '<S5>/BA-IS-UART_rx' */
  uint32_T BAISI2C_read_o2;            /* '<S2>/BA-IS-I2C_read' */
  int32_T CA_MA_rx_o1;                 /* '<S6>/CA_MA_rx' */
  int32_T CA_MA_tx_p;                  /* '<S6>/CA_MA_tx' */
  int32_T CA_MA_rx1_o1;                /* '<S6>/CA_MA_rx1' */
  uint8_T FIFOread[1025];              /* '<S7>/FIFO read ' */
  uint8_T ASCIIEncode[128];            /* '<S7>/ASCII Encode ' */
  uint8_T CANUnpack_o4;                /* '<S6>/CAN Unpack' */
  uint8_T CANUnpack_o5;                /* '<S6>/CAN Unpack' */
  uint8_T CANUnpack_o6;                /* '<S6>/CAN Unpack' */
  uint8_T CANUnpack_o7;                /* '<S6>/CAN Unpack' */
  uint8_T CA_MA_status_e[5];           /* '<S19>/CA_MA_status' */
  uint8_T RxErrorCounter;              /* '<S19>/Signal Conversion' */
  uint8_T TxErrorCounter;              /* '<S19>/Signal Conversion1' */
  uint8_T BAISUART_rx_o1[16];          /* '<S5>/BA-IS-UART_rx' */
  uint8_T Output;                      /* '<S15>/Output' */
  uint8_T ManualSwitch[4];             /* '<S5>/Manual Switch' */
  uint8_T FixPtSum1;                   /* '<S17>/FixPt Sum1' */
  uint8_T FixPtSwitch;                 /* '<S18>/FixPt Switch' */
  uint8_T Output_b;                    /* '<S11>/Output' */
  uint8_T ManualSwitch_g[4];           /* '<S4>/Manual Switch' */
  uint8_T BAISSPI1[4];                 /* '<S4>/BA-IS-SPI1' */
  uint8_T FixPtSum1_b;                 /* '<S13>/FixPt Sum1' */
  uint8_T FixPtSwitch_f;               /* '<S14>/FixPt Switch' */
  uint8_T Bias1[4];                    /* '<S4>/Bias1' */
  uint8_T BAISI2C_read_o1[4];          /* '<S2>/BA-IS-I2C_read' */
  uint8_T ExtractDesiredBits;          /* '<S22>/Extract Desired Bits' */
  uint8_T ExtractDesiredBits_o;        /* '<S21>/Extract Desired Bits' */
  uint8_T ModifyScalingOnly;           /* '<S21>/Modify Scaling Only' */
  uint8_T ModifyScalingOnly_d;         /* '<S22>/Modify Scaling Only' */
  boolean_T FIFOwrite1_o2;             /* '<S24>/FIFO write 1' */
  boolean_T FIFOwrite2_o2;             /* '<S24>/FIFO write 2' */
  boolean_T FIFOwrite1_o2_b;           /* '<S23>/FIFO write 1' */
  boolean_T FIFOwrite2_o2_o;           /* '<S23>/FIFO write 2' */
} B_RITM_test_RT1007_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T lastSin;                      /* '<S7>/Sine Wave' */
  real_T lastCos;                      /* '<S7>/Sine Wave' */
  real_T lastSin_d;                    /* '<S6>/Sine Wave' */
  real_T lastCos_b;                    /* '<S6>/Sine Wave' */
  void *FIFOread_PWORK[5];             /* '<S7>/FIFO read ' */
  void *ASCIIDecode_PWORK[2];          /* '<S7>/ASCII Decode ' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S7>/Scope' */

  void *FIFOwrite1_PWORK[4];           /* '<S24>/FIFO write 1' */
  void *FIFOwrite2_PWORK[4];           /* '<S24>/FIFO write 2' */
  void *ASCIIEncode_PWORK;             /* '<S7>/ASCII Encode ' */
  void *FIFOwrite1_PWORK_p[4];         /* '<S23>/FIFO write 1' */
  void *FIFOwrite2_PWORK_e[4];         /* '<S23>/FIFO write 2' */
  void *FIFOread2_PWORK[5];            /* '<S35>/FIFO read 2' */
  void *FIFOwrite2_PWORK_a[4];         /* '<S33>/FIFO write 2' */
  void *FIFOread1_PWORK[5];            /* '<S34>/FIFO read 1' */
  void *FIFOwrite1_PWORK_b[4];         /* '<S32>/FIFO write 1' */
  void *FIFOread2_PWORK_g[5];          /* '<S30>/FIFO read 2' */
  void *FIFOwrite2_PWORK_k[4];         /* '<S28>/FIFO write 2' */
  void *FIFOread1_PWORK_g[5];          /* '<S29>/FIFO read 1' */
  void *FIFOwrite1_PWORK_j[4];         /* '<S27>/FIFO write 1' */
  struct {
    void *LoggedData;
  } Scope_PWORK_l;                     /* '<S6>/Scope' */

  int32_T systemEnable;                /* '<S7>/Sine Wave' */
  int32_T systemEnable_i;              /* '<S6>/Sine Wave' */
  int32_T clockTickCounter;            /* '<S1>/Twice a second' */
  int_T FIFOread_IWORK[5];             /* '<S7>/FIFO read ' */
  int_T ASCIIDecode_IWORK[4];          /* '<S7>/ASCII Decode ' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S25>/S-Function' */

  int_T FIFOwrite1_IWORK[3];           /* '<S24>/FIFO write 1' */
  int_T EnableTX1_IWORK;               /* '<S24>/Enable TX 1' */
  int_T FIFOwrite2_IWORK[3];           /* '<S24>/FIFO write 2' */
  int_T EnableTX2_IWORK;               /* '<S24>/Enable TX 2' */
  int_T Setup1_IWORK[3];               /* '<S24>/Setup1' */
  int_T Setup2_IWORK[3];               /* '<S24>/Setup2' */
  int_T FIFOwrite1_IWORK_f[3];         /* '<S23>/FIFO write 1' */
  int_T EnableTX1_IWORK_m;             /* '<S23>/Enable TX 1' */
  int_T FIFOwrite2_IWORK_n[3];         /* '<S23>/FIFO write 2' */
  int_T EnableTX2_IWORK_f;             /* '<S23>/Enable TX 2' */
  int_T Setup1_IWORK_e[3];             /* '<S23>/Setup1' */
  int_T Setup2_IWORK_i[3];             /* '<S23>/Setup2' */
  int_T FIFOread2_IWORK[5];            /* '<S35>/FIFO read 2' */
  int_T WriteHWFIFO2_IWORK;            /* '<S35>/Write HW FIFO2' */
  int_T ReadHWFIFO2_IWORK;             /* '<S33>/Read HW FIFO2' */
  int_T FIFOwrite2_IWORK_d[3];         /* '<S33>/FIFO write 2' */
  int_T FIFOread1_IWORK[5];            /* '<S34>/FIFO read 1' */
  int_T WriteHWFIFO1_IWORK;            /* '<S34>/Write HW FIFO1' */
  int_T ReadHWFIFO1_IWORK;             /* '<S32>/Read HW FIFO1' */
  int_T FIFOwrite1_IWORK_o[3];         /* '<S32>/FIFO write 1' */
  int_T FIFOread2_IWORK_o[5];          /* '<S30>/FIFO read 2' */
  int_T WriteHWFIFO2_IWORK_a;          /* '<S30>/Write HW FIFO2' */
  int_T ReadHWFIFO2_IWORK_n;           /* '<S28>/Read HW FIFO2' */
  int_T FIFOwrite2_IWORK_a[3];         /* '<S28>/FIFO write 2' */
  int_T FIFOread1_IWORK_a[5];          /* '<S29>/FIFO read 1' */
  int_T WriteHWFIFO1_IWORK_l;          /* '<S29>/Write HW FIFO1' */
  int_T ReadHWFIFO1_IWORK_o;           /* '<S27>/Read HW FIFO1' */
  int_T FIFOwrite1_IWORK_n[3];         /* '<S27>/FIFO write 1' */
  int_T CANUnpack_ModeSignalID;        /* '<S6>/CAN Unpack' */
  int_T CANUnpack_StatusPortID;        /* '<S6>/CAN Unpack' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_g;                 /* '<S20>/S-Function' */

  int_T CANPack_ModeSignalID;          /* '<S6>/CAN Pack' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_h;                 /* '<S16>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_c;                 /* '<S12>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_o;                 /* '<S10>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_l;                 /* '<S9>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_k;                 /* '<S8>/S-Function' */

  uint8_T Output_DSTATE;               /* '<S15>/Output' */
  uint8_T Output_DSTATE_e;             /* '<S11>/Output' */
  int8_T RS232ISR_SubsysRanBC;         /* '<S24>/RS232 ISR' */
  int8_T Transmit2_SubsysRanBC;        /* '<S31>/Transmit 2' */
  int8_T Receive2_SubsysRanBC;         /* '<S31>/Receive 2' */
  int8_T Transmit1_SubsysRanBC;        /* '<S31>/Transmit 1' */
  int8_T Receive1_SubsysRanBC;         /* '<S31>/Receive 1' */
  int8_T RS232ISR_SubsysRanBC_l;       /* '<S23>/RS232 ISR' */
  int8_T Transmit2_SubsysRanBC_f;      /* '<S26>/Transmit 2' */
  int8_T Receive2_SubsysRanBC_l;       /* '<S26>/Receive 2' */
  int8_T Transmit1_SubsysRanBC_o;      /* '<S26>/Transmit 1' */
  int8_T Receive1_SubsysRanBC_c;       /* '<S26>/Receive 1' */
} DW_RITM_test_RT1007_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint32_T Width;                /* '<S5>/Width' */
} ConstB_RITM_test_RT1007_T;

/* Backward compatible GRT Identifiers */
#define rtB                            RITM_test_RT1007_B
#define BlockIO                        B_RITM_test_RT1007_T
#define rtP                            RITM_test_RT1007_P
#define Parameters                     P_RITM_test_RT1007_T
#define rtDWork                        RITM_test_RT1007_DW
#define D_Work                         DW_RITM_test_RT1007_T
#define tConstBlockIOType              ConstB_RITM_test_RT1007_T
#define rtC                            RITM_test_RT1007_ConstB

/* Parameters (default storage) */
struct P_RITM_test_RT1007_T_ {
  uint8_T CounterLimited1_uplimit;    /* Mask Parameter: CounterLimited1_uplimit
                                       * Referenced by: '<S14>/FixPt Switch'
                                       */
  uint8_T CounterLimited_uplimit;      /* Mask Parameter: CounterLimited_uplimit
                                        * Referenced by: '<S18>/FixPt Switch'
                                        */
  real_T BA_IS_gpio_di_P1_Size[2];  /* Computed Parameter: BA_IS_gpio_di_P1_Size
                                     * Referenced by: '<S1>/BA_IS_gpio_di'
                                     */
  real_T BA_IS_gpio_di_P1;             /* Expression: boardId-1
                                        * Referenced by: '<S1>/BA_IS_gpio_di'
                                        */
  real_T BA_IS_gpio_di_P2_Size[2];  /* Computed Parameter: BA_IS_gpio_di_P2_Size
                                     * Referenced by: '<S1>/BA_IS_gpio_di'
                                     */
  real_T BA_IS_gpio_di_P2[13];         /* Expression: channels-1
                                        * Referenced by: '<S1>/BA_IS_gpio_di'
                                        */
  real_T BA_IS_gpio_di_P3_Size[2];  /* Computed Parameter: BA_IS_gpio_di_P3_Size
                                     * Referenced by: '<S1>/BA_IS_gpio_di'
                                     */
  real_T BA_IS_gpio_di_P3;             /* Expression: voltage
                                        * Referenced by: '<S1>/BA_IS_gpio_di'
                                        */
  real_T BA_IS_gpio_di_P4_Size[2];  /* Computed Parameter: BA_IS_gpio_di_P4_Size
                                     * Referenced by: '<S1>/BA_IS_gpio_di'
                                     */
  real_T BA_IS_gpio_di_P4;             /* Expression: sampleTime
                                        * Referenced by: '<S1>/BA_IS_gpio_di'
                                        */
  real_T Twiceasecond_Amp;             /* Expression: 1
                                        * Referenced by: '<S1>/Twice a second'
                                        */
  real_T Twiceasecond_Period;          /* Expression: 1000
                                        * Referenced by: '<S1>/Twice a second'
                                        */
  real_T Twiceasecond_Duty;            /* Expression: 500
                                        * Referenced by: '<S1>/Twice a second'
                                        */
  real_T Twiceasecond_PhaseDelay;      /* Expression: 0
                                        * Referenced by: '<S1>/Twice a second'
                                        */
  real_T BA_IS_gpio_do_P1_Size[2];  /* Computed Parameter: BA_IS_gpio_do_P1_Size
                                     * Referenced by: '<S1>/BA_IS_gpio_do'
                                     */
  real_T BA_IS_gpio_do_P1;             /* Expression: boardId-1
                                        * Referenced by: '<S1>/BA_IS_gpio_do'
                                        */
  real_T BA_IS_gpio_do_P2_Size[2];  /* Computed Parameter: BA_IS_gpio_do_P2_Size
                                     * Referenced by: '<S1>/BA_IS_gpio_do'
                                     */
  real_T BA_IS_gpio_do_P2[13];         /* Expression: channels-1
                                        * Referenced by: '<S1>/BA_IS_gpio_do'
                                        */
  real_T BA_IS_gpio_do_P3_Size[2];  /* Computed Parameter: BA_IS_gpio_do_P3_Size
                                     * Referenced by: '<S1>/BA_IS_gpio_do'
                                     */
  real_T BA_IS_gpio_do_P3;             /* Expression: voltage
                                        * Referenced by: '<S1>/BA_IS_gpio_do'
                                        */
  real_T BA_IS_gpio_do_P4_Size[2];  /* Computed Parameter: BA_IS_gpio_do_P4_Size
                                     * Referenced by: '<S1>/BA_IS_gpio_do'
                                     */
  real_T BA_IS_gpio_do_P4;             /* Expression: sampleTime
                                        * Referenced by: '<S1>/BA_IS_gpio_do'
                                        */
  real_T BAISI2C_read_P1_Size[2];    /* Computed Parameter: BAISI2C_read_P1_Size
                                      * Referenced by: '<S2>/BA-IS-I2C_read'
                                      */
  real_T BAISI2C_read_P1;              /* Expression: boardId
                                        * Referenced by: '<S2>/BA-IS-I2C_read'
                                        */
  real_T BAISI2C_read_P2_Size[2];    /* Computed Parameter: BAISI2C_read_P2_Size
                                      * Referenced by: '<S2>/BA-IS-I2C_read'
                                      */
  real_T BAISI2C_read_P2;              /* Expression: channel-1
                                        * Referenced by: '<S2>/BA-IS-I2C_read'
                                        */
  real_T BAISI2C_read_P3_Size[2];    /* Computed Parameter: BAISI2C_read_P3_Size
                                      * Referenced by: '<S2>/BA-IS-I2C_read'
                                      */
  real_T BAISI2C_read_P3;              /* Expression: 2-mode
                                        * Referenced by: '<S2>/BA-IS-I2C_read'
                                        */
  real_T BAISI2C_read_P4_Size[2];    /* Computed Parameter: BAISI2C_read_P4_Size
                                      * Referenced by: '<S2>/BA-IS-I2C_read'
                                      */
  real_T BAISI2C_read_P4;              /* Expression: address
                                        * Referenced by: '<S2>/BA-IS-I2C_read'
                                        */
  real_T BAISI2C_read_P5_Size[2];    /* Computed Parameter: BAISI2C_read_P5_Size
                                      * Referenced by: '<S2>/BA-IS-I2C_read'
                                      */
  real_T BAISI2C_read_P5;              /* Expression: numwords
                                        * Referenced by: '<S2>/BA-IS-I2C_read'
                                        */
  real_T BAISI2C_read_P6_Size[2];    /* Computed Parameter: BAISI2C_read_P6_Size
                                      * Referenced by: '<S2>/BA-IS-I2C_read'
                                      */
  real_T BAISI2C_read_P6;              /* Expression: sampleTime
                                        * Referenced by: '<S2>/BA-IS-I2C_read'
                                        */
  real_T BAISCAP_P1_Size[2];           /* Computed Parameter: BAISCAP_P1_Size
                                        * Referenced by: '<S3>/BA-IS-CAP'
                                        */
  real_T BAISCAP_P1;                   /* Expression: boardId
                                        * Referenced by: '<S3>/BA-IS-CAP'
                                        */
  real_T BAISCAP_P2_Size[2];           /* Computed Parameter: BAISCAP_P2_Size
                                        * Referenced by: '<S3>/BA-IS-CAP'
                                        */
  real_T BAISCAP_P2;                   /* Expression: channel-1
                                        * Referenced by: '<S3>/BA-IS-CAP'
                                        */
  real_T BAISCAP_P3_Size[2];           /* Computed Parameter: BAISCAP_P3_Size
                                        * Referenced by: '<S3>/BA-IS-CAP'
                                        */
  real_T BAISCAP_P3;                   /* Expression: sampleTime
                                        * Referenced by: '<S3>/BA-IS-CAP'
                                        */
  real_T BAISCAP1_P1_Size[2];          /* Computed Parameter: BAISCAP1_P1_Size
                                        * Referenced by: '<S3>/BA-IS-CAP1'
                                        */
  real_T BAISCAP1_P1;                  /* Expression: boardId
                                        * Referenced by: '<S3>/BA-IS-CAP1'
                                        */
  real_T BAISCAP1_P2_Size[2];          /* Computed Parameter: BAISCAP1_P2_Size
                                        * Referenced by: '<S3>/BA-IS-CAP1'
                                        */
  real_T BAISCAP1_P2;                  /* Expression: channel-1
                                        * Referenced by: '<S3>/BA-IS-CAP1'
                                        */
  real_T BAISCAP1_P3_Size[2];          /* Computed Parameter: BAISCAP1_P3_Size
                                        * Referenced by: '<S3>/BA-IS-CAP1'
                                        */
  real_T BAISCAP1_P3;                  /* Expression: sampleTime
                                        * Referenced by: '<S3>/BA-IS-CAP1'
                                        */
  real_T BAISCAP2_P1_Size[2];          /* Computed Parameter: BAISCAP2_P1_Size
                                        * Referenced by: '<S3>/BA-IS-CAP2'
                                        */
  real_T BAISCAP2_P1;                  /* Expression: boardId
                                        * Referenced by: '<S3>/BA-IS-CAP2'
                                        */
  real_T BAISCAP2_P2_Size[2];          /* Computed Parameter: BAISCAP2_P2_Size
                                        * Referenced by: '<S3>/BA-IS-CAP2'
                                        */
  real_T BAISCAP2_P2;                  /* Expression: channel-1
                                        * Referenced by: '<S3>/BA-IS-CAP2'
                                        */
  real_T BAISCAP2_P3_Size[2];          /* Computed Parameter: BAISCAP2_P3_Size
                                        * Referenced by: '<S3>/BA-IS-CAP2'
                                        */
  real_T BAISCAP2_P3;                  /* Expression: sampleTime
                                        * Referenced by: '<S3>/BA-IS-CAP2'
                                        */
  real_T BAISCAP3_P1_Size[2];          /* Computed Parameter: BAISCAP3_P1_Size
                                        * Referenced by: '<S3>/BA-IS-CAP3'
                                        */
  real_T BAISCAP3_P1;                  /* Expression: boardId
                                        * Referenced by: '<S3>/BA-IS-CAP3'
                                        */
  real_T BAISCAP3_P2_Size[2];          /* Computed Parameter: BAISCAP3_P2_Size
                                        * Referenced by: '<S3>/BA-IS-CAP3'
                                        */
  real_T BAISCAP3_P2;                  /* Expression: channel-1
                                        * Referenced by: '<S3>/BA-IS-CAP3'
                                        */
  real_T BAISCAP3_P3_Size[2];          /* Computed Parameter: BAISCAP3_P3_Size
                                        * Referenced by: '<S3>/BA-IS-CAP3'
                                        */
  real_T BAISCAP3_P3;                  /* Expression: sampleTime
                                        * Referenced by: '<S3>/BA-IS-CAP3'
                                        */
  real_T Constant1_Value;              /* Expression: 0.01
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant8_Value;              /* Expression: 50
                                        * Referenced by: '<S3>/Constant8'
                                        */
  real_T BAISPWM_P1_Size[2];           /* Computed Parameter: BAISPWM_P1_Size
                                        * Referenced by: '<S3>/BA-IS-PWM'
                                        */
  real_T BAISPWM_P1;                   /* Expression: boardId
                                        * Referenced by: '<S3>/BA-IS-PWM'
                                        */
  real_T BAISPWM_P2_Size[2];           /* Computed Parameter: BAISPWM_P2_Size
                                        * Referenced by: '<S3>/BA-IS-PWM'
                                        */
  real_T BAISPWM_P2;                   /* Expression: channel-1
                                        * Referenced by: '<S3>/BA-IS-PWM'
                                        */
  real_T BAISPWM_P3_Size[2];           /* Computed Parameter: BAISPWM_P3_Size
                                        * Referenced by: '<S3>/BA-IS-PWM'
                                        */
  real_T BAISPWM_P3;                   /* Expression: sampleTime
                                        * Referenced by: '<S3>/BA-IS-PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 0.001
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 25
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T BAISPWM1_P1_Size[2];          /* Computed Parameter: BAISPWM1_P1_Size
                                        * Referenced by: '<S3>/BA-IS-PWM1'
                                        */
  real_T BAISPWM1_P1;                  /* Expression: boardId
                                        * Referenced by: '<S3>/BA-IS-PWM1'
                                        */
  real_T BAISPWM1_P2_Size[2];          /* Computed Parameter: BAISPWM1_P2_Size
                                        * Referenced by: '<S3>/BA-IS-PWM1'
                                        */
  real_T BAISPWM1_P2;                  /* Expression: channel-1
                                        * Referenced by: '<S3>/BA-IS-PWM1'
                                        */
  real_T BAISPWM1_P3_Size[2];          /* Computed Parameter: BAISPWM1_P3_Size
                                        * Referenced by: '<S3>/BA-IS-PWM1'
                                        */
  real_T BAISPWM1_P3;                  /* Expression: sampleTime
                                        * Referenced by: '<S3>/BA-IS-PWM1'
                                        */
  real_T BAISSPI1_P1_Size[2];          /* Computed Parameter: BAISSPI1_P1_Size
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P1;                  /* Expression: boardId
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P2_Size[2];          /* Computed Parameter: BAISSPI1_P2_Size
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P2;                  /* Expression: channel-1
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P3_Size[2];          /* Computed Parameter: BAISSPI1_P3_Size
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P3;                  /* Expression: 2-mode
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P4_Size[2];          /* Computed Parameter: BAISSPI1_P4_Size
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P4;                  /* Expression: polarity-1
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P5_Size[2];          /* Computed Parameter: BAISSPI1_P5_Size
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P5;                  /* Expression: phase-1
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P6_Size[2];          /* Computed Parameter: BAISSPI1_P6_Size
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P6;                  /* Expression: numwords
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P7_Size[2];          /* Computed Parameter: BAISSPI1_P7_Size
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P7;                  /* Expression: divider-1
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P8_Size[2];          /* Computed Parameter: BAISSPI1_P8_Size
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISSPI1_P8;                  /* Expression: sampleTime
                                        * Referenced by: '<S4>/BA-IS-SPI1'
                                        */
  real_T BAISUART_setup_P1_Size[2];/* Computed Parameter: BAISUART_setup_P1_Size
                                    * Referenced by: '<S5>/BA-IS-UART_setup'
                                    */
  real_T BAISUART_setup_P1;            /* Expression: boardId-1
                                        * Referenced by: '<S5>/BA-IS-UART_setup'
                                        */
  real_T BAISUART_setup_P2_Size[2];/* Computed Parameter: BAISUART_setup_P2_Size
                                    * Referenced by: '<S5>/BA-IS-UART_setup'
                                    */
  real_T BAISUART_setup_P2;            /* Expression: channel-1
                                        * Referenced by: '<S5>/BA-IS-UART_setup'
                                        */
  real_T BAISUART_setup_P3_Size[2];/* Computed Parameter: BAISUART_setup_P3_Size
                                    * Referenced by: '<S5>/BA-IS-UART_setup'
                                    */
  real_T BAISUART_setup_P3;            /* Expression: baudRate-1
                                        * Referenced by: '<S5>/BA-IS-UART_setup'
                                        */
  real_T BAISUART_setup_P4_Size[2];/* Computed Parameter: BAISUART_setup_P4_Size
                                    * Referenced by: '<S5>/BA-IS-UART_setup'
                                    */
  real_T BAISUART_setup_P4;            /* Expression: dataLen-1
                                        * Referenced by: '<S5>/BA-IS-UART_setup'
                                        */
  real_T BAISUART_setup_P5_Size[2];/* Computed Parameter: BAISUART_setup_P5_Size
                                    * Referenced by: '<S5>/BA-IS-UART_setup'
                                    */
  real_T BAISUART_setup_P5;            /* Expression: stopBit-1
                                        * Referenced by: '<S5>/BA-IS-UART_setup'
                                        */
  real_T BAISUART_setup_P6_Size[2];/* Computed Parameter: BAISUART_setup_P6_Size
                                    * Referenced by: '<S5>/BA-IS-UART_setup'
                                    */
  real_T BAISUART_setup_P6;            /* Expression: parityType-1
                                        * Referenced by: '<S5>/BA-IS-UART_setup'
                                        */
  real_T BAISUART_rx_P1_Size[2];      /* Computed Parameter: BAISUART_rx_P1_Size
                                       * Referenced by: '<S5>/BA-IS-UART_rx'
                                       */
  real_T BAISUART_rx_P1;               /* Expression: boardId-1
                                        * Referenced by: '<S5>/BA-IS-UART_rx'
                                        */
  real_T BAISUART_rx_P2_Size[2];      /* Computed Parameter: BAISUART_rx_P2_Size
                                       * Referenced by: '<S5>/BA-IS-UART_rx'
                                       */
  real_T BAISUART_rx_P2;               /* Expression: channel-1
                                        * Referenced by: '<S5>/BA-IS-UART_rx'
                                        */
  real_T BAISUART_rx_P3_Size[2];      /* Computed Parameter: BAISUART_rx_P3_Size
                                       * Referenced by: '<S5>/BA-IS-UART_rx'
                                       */
  real_T BAISUART_rx_P3;               /* Expression: baudRate
                                        * Referenced by: '<S5>/BA-IS-UART_rx'
                                        */
  real_T BAISUART_rx_P4_Size[2];      /* Computed Parameter: BAISUART_rx_P4_Size
                                       * Referenced by: '<S5>/BA-IS-UART_rx'
                                       */
  real_T BAISUART_rx_P4;               /* Expression: sampleTime
                                        * Referenced by: '<S5>/BA-IS-UART_rx'
                                        */
  real_T BAISUART_tx_P1_Size[2];      /* Computed Parameter: BAISUART_tx_P1_Size
                                       * Referenced by: '<S5>/BA-IS-UART_tx'
                                       */
  real_T BAISUART_tx_P1;               /* Expression: boardId-1
                                        * Referenced by: '<S5>/BA-IS-UART_tx'
                                        */
  real_T BAISUART_tx_P2_Size[2];      /* Computed Parameter: BAISUART_tx_P2_Size
                                       * Referenced by: '<S5>/BA-IS-UART_tx'
                                       */
  real_T BAISUART_tx_P2;               /* Expression: channel-1
                                        * Referenced by: '<S5>/BA-IS-UART_tx'
                                        */
  real_T BAISUART_tx_P3_Size[2];      /* Computed Parameter: BAISUART_tx_P3_Size
                                       * Referenced by: '<S5>/BA-IS-UART_tx'
                                       */
  real_T BAISUART_tx_P3;               /* Expression: baudRate
                                        * Referenced by: '<S5>/BA-IS-UART_tx'
                                        */
  real_T BAISUART_tx_P4_Size[2];      /* Computed Parameter: BAISUART_tx_P4_Size
                                       * Referenced by: '<S5>/BA-IS-UART_tx'
                                       */
  real_T BAISUART_tx_P4;               /* Expression: sampleTime
                                        * Referenced by: '<S5>/BA-IS-UART_tx'
                                        */
  real_T CA_MA_rx_P1_Size[2];          /* Computed Parameter: CA_MA_rx_P1_Size
                                        * Referenced by: '<S6>/CA_MA_rx'
                                        */
  real_T CA_MA_rx_P1;                  /* Expression: boardId
                                        * Referenced by: '<S6>/CA_MA_rx'
                                        */
  real_T CA_MA_rx_P2_Size[2];          /* Computed Parameter: CA_MA_rx_P2_Size
                                        * Referenced by: '<S6>/CA_MA_rx'
                                        */
  real_T CA_MA_rx_P2;                  /* Expression: channel
                                        * Referenced by: '<S6>/CA_MA_rx'
                                        */
  real_T CA_MA_rx_P3_Size[2];          /* Computed Parameter: CA_MA_rx_P3_Size
                                        * Referenced by: '<S6>/CA_MA_rx'
                                        */
  real_T CA_MA_rx_P3;                  /* Expression: sampleTime
                                        * Referenced by: '<S6>/CA_MA_rx'
                                        */
  real_T CA_MA_status_P1_Size[2];    /* Computed Parameter: CA_MA_status_P1_Size
                                      * Referenced by: '<S19>/CA_MA_status'
                                      */
  real_T CA_MA_status_P1;              /* Expression: boardId
                                        * Referenced by: '<S19>/CA_MA_status'
                                        */
  real_T CA_MA_status_P2_Size[2];    /* Computed Parameter: CA_MA_status_P2_Size
                                      * Referenced by: '<S19>/CA_MA_status'
                                      */
  real_T CA_MA_status_P2;              /* Expression: channel
                                        * Referenced by: '<S19>/CA_MA_status'
                                        */
  real_T CA_MA_status_P3_Size[2];    /* Computed Parameter: CA_MA_status_P3_Size
                                      * Referenced by: '<S19>/CA_MA_status'
                                      */
  real_T CA_MA_status_P3;              /* Expression: sampleTime
                                        * Referenced by: '<S19>/CA_MA_status'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<S6>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S6>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 5*pi
                                        * Referenced by: '<S6>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<S6>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<S6>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<S6>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<S6>/Sine Wave'
                                        */
  real_T CA_MA_tx_P1_Size[2];          /* Computed Parameter: CA_MA_tx_P1_Size
                                        * Referenced by: '<S6>/CA_MA_tx'
                                        */
  real_T CA_MA_tx_P1;                  /* Expression: boardId
                                        * Referenced by: '<S6>/CA_MA_tx'
                                        */
  real_T CA_MA_tx_P2_Size[2];          /* Computed Parameter: CA_MA_tx_P2_Size
                                        * Referenced by: '<S6>/CA_MA_tx'
                                        */
  real_T CA_MA_tx_P2;                  /* Expression: channel
                                        * Referenced by: '<S6>/CA_MA_tx'
                                        */
  real_T CA_MA_tx_P3_Size[2];          /* Computed Parameter: CA_MA_tx_P3_Size
                                        * Referenced by: '<S6>/CA_MA_tx'
                                        */
  real_T CA_MA_tx_P3;                  /* Expression: sampleTime
                                        * Referenced by: '<S6>/CA_MA_tx'
                                        */
  real_T CA_MA_rx1_P1_Size[2];         /* Computed Parameter: CA_MA_rx1_P1_Size
                                        * Referenced by: '<S6>/CA_MA_rx1'
                                        */
  real_T CA_MA_rx1_P1;                 /* Expression: boardId
                                        * Referenced by: '<S6>/CA_MA_rx1'
                                        */
  real_T CA_MA_rx1_P2_Size[2];         /* Computed Parameter: CA_MA_rx1_P2_Size
                                        * Referenced by: '<S6>/CA_MA_rx1'
                                        */
  real_T CA_MA_rx1_P2;                 /* Expression: channel
                                        * Referenced by: '<S6>/CA_MA_rx1'
                                        */
  real_T CA_MA_rx1_P3_Size[2];         /* Computed Parameter: CA_MA_rx1_P3_Size
                                        * Referenced by: '<S6>/CA_MA_rx1'
                                        */
  real_T CA_MA_rx1_P3;                 /* Expression: sampleTime
                                        * Referenced by: '<S6>/CA_MA_rx1'
                                        */
  real_T CA_MA_setup_P1_Size[2];      /* Computed Parameter: CA_MA_setup_P1_Size
                                       * Referenced by: '<S6>/CA_MA_setup'
                                       */
  real_T CA_MA_setup_P1;               /* Expression: boardId
                                        * Referenced by: '<S6>/CA_MA_setup'
                                        */
  real_T CA_MA_setup_P2_Size[2];      /* Computed Parameter: CA_MA_setup_P2_Size
                                       * Referenced by: '<S6>/CA_MA_setup'
                                       */
  real_T CA_MA_setup_P2;               /* Expression: baudRate1
                                        * Referenced by: '<S6>/CA_MA_setup'
                                        */
  real_T CA_MA_setup_P3_Size[2];      /* Computed Parameter: CA_MA_setup_P3_Size
                                       * Referenced by: '<S6>/CA_MA_setup'
                                       */
  real_T CA_MA_setup_P3;               /* Expression: baudRate2
                                        * Referenced by: '<S6>/CA_MA_setup'
                                        */
  real_T CA_MA_setup_P4_Size[2];      /* Computed Parameter: CA_MA_setup_P4_Size
                                       * Referenced by: '<S6>/CA_MA_setup'
                                       */
  real_T CA_MA_setup_P4[3];            /* Expression: filter1
                                        * Referenced by: '<S6>/CA_MA_setup'
                                        */
  real_T CA_MA_setup_P5_Size[2];      /* Computed Parameter: CA_MA_setup_P5_Size
                                       * Referenced by: '<S6>/CA_MA_setup'
                                       */
  real_T CA_MA_setup_P5[3];            /* Expression: filter2
                                        * Referenced by: '<S6>/CA_MA_setup'
                                        */
  real_T CA_MA_setup_P6_Size[2];      /* Computed Parameter: CA_MA_setup_P6_Size
                                       * Referenced by: '<S6>/CA_MA_setup'
                                       */
  real_T CA_MA_setup_P6;               /* Expression: boffRecover1
                                        * Referenced by: '<S6>/CA_MA_setup'
                                        */
  real_T CA_MA_setup_P7_Size[2];      /* Computed Parameter: CA_MA_setup_P7_Size
                                       * Referenced by: '<S6>/CA_MA_setup'
                                       */
  real_T CA_MA_setup_P7;               /* Expression: boffRecover2
                                        * Referenced by: '<S6>/CA_MA_setup'
                                        */
  real_T ASCIIDecode_P1_Size[2];      /* Computed Parameter: ASCIIDecode_P1_Size
                                       * Referenced by: '<S7>/ASCII Decode '
                                       */
  real_T ASCIIDecode_P1[3];            /* Computed Parameter: ASCIIDecode_P1
                                        * Referenced by: '<S7>/ASCII Decode '
                                        */
  real_T ASCIIDecode_P2_Size[2];      /* Computed Parameter: ASCIIDecode_P2_Size
                                       * Referenced by: '<S7>/ASCII Decode '
                                       */
  real_T ASCIIDecode_P2;               /* Expression: nvars
                                        * Referenced by: '<S7>/ASCII Decode '
                                        */
  real_T ASCIIDecode_P3_Size[2];      /* Computed Parameter: ASCIIDecode_P3_Size
                                       * Referenced by: '<S7>/ASCII Decode '
                                       */
  real_T ASCIIDecode_P3;               /* Expression: varids
                                        * Referenced by: '<S7>/ASCII Decode '
                                        */
  real_T Setup1_P1_Size[2];            /* Computed Parameter: Setup1_P1_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P1;                    /* Expression: addr
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P2_Size[2];            /* Computed Parameter: Setup1_P2_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P2;                    /* Expression: baud
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P3_Size[2];            /* Computed Parameter: Setup1_P3_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P3;                    /* Expression: width
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P4_Size[2];            /* Computed Parameter: Setup1_P4_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P4;                    /* Expression: nstop
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P5_Size[2];            /* Computed Parameter: Setup1_P5_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P5;                    /* Expression: parity
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P6_Size[2];            /* Computed Parameter: Setup1_P6_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P6;                    /* Expression: fmode
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P7_Size[2];            /* Computed Parameter: Setup1_P7_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P7;                    /* Expression: ctsmode
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P8_Size[2];            /* Computed Parameter: Setup1_P8_Size
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup1_P8;                    /* Expression: rlevel
                                        * Referenced by: '<S24>/Setup1'
                                        */
  real_T Setup2_P1_Size[2];            /* Computed Parameter: Setup2_P1_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P1;                    /* Expression: addr
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P2_Size[2];            /* Computed Parameter: Setup2_P2_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P2;                    /* Expression: baud
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P3_Size[2];            /* Computed Parameter: Setup2_P3_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P3;                    /* Expression: width
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P4_Size[2];            /* Computed Parameter: Setup2_P4_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P4;                    /* Expression: nstop
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P5_Size[2];            /* Computed Parameter: Setup2_P5_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P5;                    /* Expression: parity
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P6_Size[2];            /* Computed Parameter: Setup2_P6_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P6;                    /* Expression: fmode
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P7_Size[2];            /* Computed Parameter: Setup2_P7_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P7;                    /* Expression: ctsmode
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P8_Size[2];            /* Computed Parameter: Setup2_P8_Size
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T Setup2_P8;                    /* Expression: rlevel
                                        * Referenced by: '<S24>/Setup2'
                                        */
  real_T SineWave_Amp_o;               /* Expression: 2
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_Bias_n;              /* Expression: 1
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_Freq_p;              /* Expression: 4*pi
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_Hsin_j;              /* Computed Parameter: SineWave_Hsin_j
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_HCos_f;              /* Computed Parameter: SineWave_HCos_f
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_PSin_p;              /* Computed Parameter: SineWave_PSin_p
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_PCos_d;              /* Computed Parameter: SineWave_PCos_d
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T ASCIIEncode_P1_Size[2];      /* Computed Parameter: ASCIIEncode_P1_Size
                                       * Referenced by: '<S7>/ASCII Encode '
                                       */
  real_T ASCIIEncode_P1[3];            /* Computed Parameter: ASCIIEncode_P1
                                        * Referenced by: '<S7>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P2_Size[2];      /* Computed Parameter: ASCIIEncode_P2_Size
                                       * Referenced by: '<S7>/ASCII Encode '
                                       */
  real_T ASCIIEncode_P2;               /* Expression: maxlength
                                        * Referenced by: '<S7>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P3_Size[2];      /* Computed Parameter: ASCIIEncode_P3_Size
                                       * Referenced by: '<S7>/ASCII Encode '
                                       */
  real_T ASCIIEncode_P3;               /* Expression: nvars
                                        * Referenced by: '<S7>/ASCII Encode '
                                        */
  real_T ASCIIEncode_P4_Size[2];      /* Computed Parameter: ASCIIEncode_P4_Size
                                       * Referenced by: '<S7>/ASCII Encode '
                                       */
  real_T ASCIIEncode_P4;               /* Expression: varids
                                        * Referenced by: '<S7>/ASCII Encode '
                                        */
  real_T Setup1_P1_Size_o[2];          /* Computed Parameter: Setup1_P1_Size_o
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P1_c;                  /* Expression: addr
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P2_Size_l[2];          /* Computed Parameter: Setup1_P2_Size_l
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P2_n;                  /* Expression: baud
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P3_Size_j[2];          /* Computed Parameter: Setup1_P3_Size_j
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P3_j;                  /* Expression: width
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P4_Size_b[2];          /* Computed Parameter: Setup1_P4_Size_b
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P4_o;                  /* Expression: nstop
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P5_Size_a[2];          /* Computed Parameter: Setup1_P5_Size_a
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P5_h;                  /* Expression: parity
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P6_Size_i[2];          /* Computed Parameter: Setup1_P6_Size_i
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P6_i;                  /* Expression: fmode
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P7_Size_p[2];          /* Computed Parameter: Setup1_P7_Size_p
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P7_l;                  /* Expression: ctsmode
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P8_Size_k[2];          /* Computed Parameter: Setup1_P8_Size_k
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup1_P8_i;                  /* Expression: rlevel
                                        * Referenced by: '<S23>/Setup1'
                                        */
  real_T Setup2_P1_Size_a[2];          /* Computed Parameter: Setup2_P1_Size_a
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P1_p;                  /* Expression: addr
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P2_Size_h[2];          /* Computed Parameter: Setup2_P2_Size_h
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P2_l;                  /* Expression: baud
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P3_Size_h[2];          /* Computed Parameter: Setup2_P3_Size_h
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P3_d;                  /* Expression: width
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P4_Size_m[2];          /* Computed Parameter: Setup2_P4_Size_m
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P4_c;                  /* Expression: nstop
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P5_Size_e[2];          /* Computed Parameter: Setup2_P5_Size_e
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P5_o;                  /* Expression: parity
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P6_Size_b[2];          /* Computed Parameter: Setup2_P6_Size_b
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P6_n;                  /* Expression: fmode
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P7_Size_h[2];          /* Computed Parameter: Setup2_P7_Size_h
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P7_i;                  /* Expression: ctsmode
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P8_Size_l[2];          /* Computed Parameter: Setup2_P8_Size_l
                                        * Referenced by: '<S23>/Setup2'
                                        */
  real_T Setup2_P8_j;                  /* Expression: rlevel
                                        * Referenced by: '<S23>/Setup2'
                                        */
  uint32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S27>/Constant'
                                        */
  uint32_T Constant1_Value_h;          /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S29>/Constant1'
                                        */
  uint32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S28>/Constant'
                                        */
  uint32_T Constant2_Value_d;          /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S30>/Constant2'
                                        */
  uint32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S32>/Constant'
                                        */
  uint32_T Constant1_Value_he;         /* Computed Parameter: Constant1_Value_he
                                        * Referenced by: '<S34>/Constant1'
                                        */
  uint32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S33>/Constant'
                                        */
  uint32_T Constant2_Value_p;          /* Computed Parameter: Constant2_Value_p
                                        * Referenced by: '<S35>/Constant2'
                                        */
  uint8_T Bias1_Bias[4];               /* Computed Parameter: Bias1_Bias
                                        * Referenced by: '<S4>/Bias1'
                                        */
  uint8_T Generatesomedata_Value[4];
                                   /* Computed Parameter: Generatesomedata_Value
                                    * Referenced by: '<S4>/Generate some data'
                                    */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S11>/Output'
                                   */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S4>/Manual Switch'
                               */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S13>/FixPt Constant'
                                       */
  uint8_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S14>/Constant'
                                        */
  uint8_T Generatesomedata_Value_l[4];
                                 /* Computed Parameter: Generatesomedata_Value_l
                                  * Referenced by: '<S5>/Generate some data'
                                  */
  uint8_T Output_InitialCondition_b;
                                /* Computed Parameter: Output_InitialCondition_b
                                 * Referenced by: '<S15>/Output'
                                 */
  uint8_T ManualSwitch_CurrentSetting_m;
                            /* Computed Parameter: ManualSwitch_CurrentSetting_m
                             * Referenced by: '<S5>/Manual Switch'
                             */
  uint8_T FixPtConstant_Value_k;    /* Computed Parameter: FixPtConstant_Value_k
                                     * Referenced by: '<S17>/FixPt Constant'
                                     */
  uint8_T Constant_Value_h;            /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S18>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_RITM_test_RT1007_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[5];
    SimStruct childSFunctions[24];
    SimStruct *childSFunctionPtrs[24];
    struct _ssBlkInfo2 blkInfo2[24];
    struct _ssSFcnModelMethods2 methods2[24];
    struct _ssSFcnModelMethods3 methods3[24];
    struct _ssSFcnModelMethods4 methods4[24];
    struct _ssStatesInfo2 statesInfo2[24];
    ssPeriodicStatesInfo periodicStatesInfo[24];
    struct _ssPortInfo2 inputOutputPortInfo2[24];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[13];
      struct _ssOutPortUnit outputPortUnits[13];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[13];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[13];
      struct _ssInPortUnit inputPortUnits[13];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[13];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[6];
      mxArray *params[6];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[8];
      mxArray *params[8];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[6];
      mxArray *params[6];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[3];
      mxArray *params[3];
    } Sfcn16;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[7];
      mxArray *params[7];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn19;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn20;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn21;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn22;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn23;
  } NonInlinedSFcns;

  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  void *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    uint32_T clockTick3;
    uint32_T clockTickH3;
    void *semIdForTask3;
    uint32_T rtmClockTickBuf3;
    uint32_T rtmBufClockTickBufH3;
    uint32_T clockTick4;
    uint32_T clockTickH4;
    void *semIdForTask4;
    uint32_T rtmClockTickBuf4;
    uint32_T rtmBufClockTickBufH4;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[5];
  } Timing;
};

/* Block parameters (default storage) */
extern P_RITM_test_RT1007_T RITM_test_RT1007_P;

/* Block signals (default storage) */
extern B_RITM_test_RT1007_T RITM_test_RT1007_B;

/* Block states (default storage) */
extern DW_RITM_test_RT1007_T RITM_test_RT1007_DW;

/* External data declarations for dependent source files */
extern const uint8_T RITM_test_RT1007_U8GND;/* uint8_T ground */
extern const ConstB_RITM_test_RT1007_T RITM_test_RT1007_ConstB;/* constant block i/o */

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;
extern void rate_scheduler(void);      /*====================*
                                        * External functions *
                                        *====================*/
extern RITM_test_RT1007_rtModel *RITM_test_RT1007(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  RITM_test_RT1007_GetCAPIStaticMap(void);

/* Real-time Model object */
extern RT_MODEL_RITM_test_RT1007_T *const RITM_test_RT1007_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RITM_test_RT1007'
 * '<S1>'   : 'RITM_test_RT1007/BA-IS-GPIO'
 * '<S2>'   : 'RITM_test_RT1007/BA-IS-I2C'
 * '<S3>'   : 'RITM_test_RT1007/BA-IS-PWM-CAP'
 * '<S4>'   : 'RITM_test_RT1007/BA-IS-SPI'
 * '<S5>'   : 'RITM_test_RT1007/BA-IS-UART'
 * '<S6>'   : 'RITM_test_RT1007/CA-MA-45'
 * '<S7>'   : 'RITM_test_RT1007/RS-232'
 * '<S8>'   : 'RITM_test_RT1007/BA-IS-GPIO/Scope '
 * '<S9>'   : 'RITM_test_RT1007/BA-IS-I2C/Scope 3'
 * '<S10>'  : 'RITM_test_RT1007/BA-IS-PWM-CAP/Scope '
 * '<S11>'  : 'RITM_test_RT1007/BA-IS-SPI/Counter Limited1'
 * '<S12>'  : 'RITM_test_RT1007/BA-IS-SPI/Scope 1'
 * '<S13>'  : 'RITM_test_RT1007/BA-IS-SPI/Counter Limited1/Increment Real World'
 * '<S14>'  : 'RITM_test_RT1007/BA-IS-SPI/Counter Limited1/Wrap To Zero'
 * '<S15>'  : 'RITM_test_RT1007/BA-IS-UART/Counter Limited'
 * '<S16>'  : 'RITM_test_RT1007/BA-IS-UART/Scope '
 * '<S17>'  : 'RITM_test_RT1007/BA-IS-UART/Counter Limited/Increment Real World'
 * '<S18>'  : 'RITM_test_RT1007/BA-IS-UART/Counter Limited/Wrap To Zero'
 * '<S19>'  : 'RITM_test_RT1007/CA-MA-45/CA_MA_status'
 * '<S20>'  : 'RITM_test_RT1007/CA-MA-45/Scope '
 * '<S21>'  : 'RITM_test_RT1007/CA-MA-45/CA_MA_status/Extract Bits'
 * '<S22>'  : 'RITM_test_RT1007/CA-MA-45/CA_MA_status/Extract Bits1'
 * '<S23>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F'
 * '<S24>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F1'
 * '<S25>'  : 'RITM_test_RT1007/RS-232/Target Scope'
 * '<S26>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F/RS232 ISR'
 * '<S27>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F/RS232 ISR/Receive 1'
 * '<S28>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F/RS232 ISR/Receive 2'
 * '<S29>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F/RS232 ISR/Transmit 1'
 * '<S30>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F/RS232 ISR/Transmit 2'
 * '<S31>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F1/RS232 ISR'
 * '<S32>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F1/RS232 ISR/Receive 1'
 * '<S33>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F1/RS232 ISR/Receive 2'
 * '<S34>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F1/RS232 ISR/Transmit 1'
 * '<S35>'  : 'RITM_test_RT1007/RS-232/Baseboard Serial F1/RS232 ISR/Transmit 2'
 */
#endif                                 /* RTW_HEADER_RITM_test_RT1007_h_ */
