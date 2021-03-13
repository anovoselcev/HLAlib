/*
 * ARM_model_2020a.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ARM_model_2020a".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Fri Jan 29 13:13:21 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ARM_model_2020a_h_
#define RTW_HEADER_ARM_model_2020a_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Wrapper.hpp"
#include "SimFederate.hpp"
#include "ARM_model_2020a_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_ARM_model_2020a_T {
  const char_T *errorStatus;
};

/* External data declarations for dependent source files */
extern const real_T ARM_model_2020a_RGND;/* real_T ground */

/* Class declaration for model ARM_model_2020a */
class ARM_model_2020aModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  ARM_model_2020aModelClass();

  /* Destructor */
  ~ARM_model_2020aModelClass();

  /* Real-Time Model get method */
  RT_MODEL_ARM_model_2020a_T * getRTM();

  /* private data and function members */
 private:
  /* Real-Time Model */
  RT_MODEL_ARM_model_2020a_T ARM_model_2020a_M;
};

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
 * '<Root>' : 'ARM_model_2020a'
 */
#endif                                 /* RTW_HEADER_ARM_model_2020a_h_ */
