/*
 * HLAblock_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "HLAblock".
 *
 * Model version              : 1.95
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C++ source code generated on : Sun Jul  5 16:12:06 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_HLAblock_private_h_
#define RTW_HEADER_HLAblock_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

extern void TransferBlock_Start_wrapper(const real_T *Param1, const int_T
  p_width0);
extern void TransferBlock_Outputs_wrapper(const real_T *X,
  real_T *Y,
  const real_T *Param1, const int_T p_width0);
extern void TransferBlock_Terminate_wrapper(const real_T *Param1, const int_T
  p_width0);

#endif                                 /* RTW_HEADER_HLAblock_private_h_ */
