/*
 * ARM_model_2020a.cpp
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

#include "ARM_model_2020a.h"
#include "ARM_model_2020a_private.h"

const real_T ARM_model_2020a_RGND = 0.0;/* real_T ground */

/* Model step function */
void ARM_model_2020aModelClass::step()
{
  /* S-Function (TransferBlock_SimARM): '<Root>/TransferBlock_SimARM' */
  Output_Point_ModelARM((real_T*)((real_T*) &ARM_model_2020a_RGND), (real_T*)
                        ((real_T*) &ARM_model_2020a_RGND));
}

/* Model initialize function */
void ARM_model_2020aModelClass::initialize()
{
  /* Start for S-Function (TransferBlock_SimARM): '<Root>/TransferBlock_SimARM' */
  Start_Point_ModelARM();
}

/* Model terminate function */
void ARM_model_2020aModelClass::terminate()
{
  /* Terminate for S-Function (TransferBlock_SimARM): '<Root>/TransferBlock_SimARM' */
  Terminate_Point();
}

/* Constructor */
ARM_model_2020aModelClass::ARM_model_2020aModelClass() : ARM_model_2020a_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
ARM_model_2020aModelClass::~ARM_model_2020aModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_ARM_model_2020a_T * ARM_model_2020aModelClass::getRTM()
{
  return (&ARM_model_2020a_M);
}
