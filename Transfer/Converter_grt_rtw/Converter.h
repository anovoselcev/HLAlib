/*
 * Converter.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Converter".
 *
 * Model version              : 1.72
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C++ source code generated on : Wed Mar 25 15:58:19 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Converter_h_
#define RTW_HEADER_Converter_h_
#include <cstring>
#ifndef Converter_COMMON_INCLUDES_
# define Converter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Converter_COMMON_INCLUDES_ */

#include "Converter_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Add;                          /* '<Root>/Add' */
  real_T CCCodeBlock;                  /* '<Root>/C//C++ Code Block' */
} B_Converter_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
} DW_Converter_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: 1)
   * Referenced by:
   *   '<Root>/Constant'
   *   '<Root>/C//C++ Code Block'
   */
  real_T pooled2;
} ConstP_Converter_T;

/* Real-time Model Data Structure */
struct tag_RTM_Converter_T {
  const char_T *errorStatus;
};

/* Constant parameters (default storage) */
extern const ConstP_Converter_T Converter_ConstP;

/* Class declaration for model Converter */
class ConverterModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  ConverterModelClass();

  /* Destructor */
  ~ConverterModelClass();

  /* Real-Time Model get method */
  RT_MODEL_Converter_T * getRTM();

  /* private data and function members */
 private:
  /* Block signals */
  B_Converter_T Converter_B;

  /* Block states */
  DW_Converter_T Converter_DW;

  /* Real-Time Model */
  RT_MODEL_Converter_T Converter_M;
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Sum' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 */

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
 * '<Root>' : 'Converter'
 * '<S1>'   : 'Converter/For Iterator Subsystem'
 */
#endif                                 /* RTW_HEADER_Converter_h_ */
