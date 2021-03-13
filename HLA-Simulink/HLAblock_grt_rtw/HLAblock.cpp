/*
 * HLAblock.cpp
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

#include "HLAblock.h"
#include "HLAblock_private.h"

/* Model step function */
void HLAblockModelClass::step()
{
  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  Delay: '<Root>/Delay'
   */
  HLAblock_B.Add = HLAblock_DW.Delay_DSTATE + 1.0;

  /* S-Function (TransferBlock): '<Root>/C//C++ Code Block' */
  TransferBlock_Outputs_wrapper(&HLAblock_B.Add, &HLAblock_B.CCCodeBlock,
    &HLAblock_ConstP.pooled2, 1);

  /* Update for Delay: '<Root>/Delay' */
  HLAblock_DW.Delay_DSTATE = HLAblock_B.CCCodeBlock;
}

/* Model initialize function */
void HLAblockModelClass::initialize()
{
  /* Registration code */

  /* block I/O */
  (void) std::memset((static_cast<void *>(&HLAblock_B)), 0,
                     sizeof(B_HLAblock_T));

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&HLAblock_DW), 0,
                     sizeof(DW_HLAblock_T));

  /* Start for S-Function (TransferBlock): '<Root>/C//C++ Code Block' */

  /* S-Function Block: <Root>/C//C++ Code Block */
  TransferBlock_Start_wrapper(&HLAblock_ConstP.pooled2, 1);

  /* InitializeConditions for Delay: '<Root>/Delay' */
  HLAblock_DW.Delay_DSTATE = 0.0;
}

/* Model terminate function */
void HLAblockModelClass::terminate()
{
  /* Terminate for S-Function (TransferBlock): '<Root>/C//C++ Code Block' */

  /* S-Function Block: <Root>/C//C++ Code Block */
  TransferBlock_Terminate_wrapper(&HLAblock_ConstP.pooled2, 1);
}

/* Constructor */
HLAblockModelClass::HLAblockModelClass() : HLAblock_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
HLAblockModelClass::~HLAblockModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_HLAblock_T * HLAblockModelClass::getRTM()
{
  return (&HLAblock_M);
}
