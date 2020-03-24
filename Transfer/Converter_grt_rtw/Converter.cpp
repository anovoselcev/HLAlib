/*
 * Converter.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Converter".
 *
 * Model version              : 1.47
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C++ source code generated on : Tue Mar 24 19:04:58 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Converter.h"
#include "Converter_private.h"

/* Model step function */
void ConverterModelClass::step()
{
  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  Delay: '<Root>/Delay'
   */
  Converter_B.Add = Converter_DW.Delay_DSTATE + 1.0;

  /* S-Function (ConverterNew): '<Root>/C//C++ Code Block' */
  ConverterNew_Outputs_wrapper(&Converter_B.Add, &Converter_B.CCCodeBlock);

  /* Update for Delay: '<Root>/Delay' */
  Converter_DW.Delay_DSTATE = Converter_B.CCCodeBlock;
}

/* Model initialize function */
void ConverterModelClass::initialize()
{
  /* Registration code */

  /* block I/O */
  (void) std::memset((static_cast<void *>(&Converter_B)), 0,
                     sizeof(B_Converter_T));

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&Converter_DW), 0,
                     sizeof(DW_Converter_T));

  /* Start for S-Function (ConverterNew): '<Root>/C//C++ Code Block' */

  /* S-Function Block: <Root>/C//C++ Code Block */
  ConverterNew_Start_wrapper();

  /* InitializeConditions for Delay: '<Root>/Delay' */
  Converter_DW.Delay_DSTATE = 0.0;
}

/* Model terminate function */
void ConverterModelClass::terminate()
{
  /* Terminate for S-Function (ConverterNew): '<Root>/C//C++ Code Block' */

  /* S-Function Block: <Root>/C//C++ Code Block */
  ConverterNew_Terminate_wrapper();
}

/* Constructor */
ConverterModelClass::ConverterModelClass() : Converter_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
ConverterModelClass::~ConverterModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Converter_T * ConverterModelClass::getRTM()
{
  return (&Converter_M);
}
