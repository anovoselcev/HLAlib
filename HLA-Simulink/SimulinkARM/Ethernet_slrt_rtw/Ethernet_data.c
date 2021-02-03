/*
 * Ethernet_data.c
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

#include "Ethernet.h"
#include "Ethernet_private.h"

/* Block parameters (default storage) */
P_Ethernet_T Ethernet_P = {
  /* Computed Parameter: UDPConfigure_P1_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 1.0, 4.0 },

  /* Expression: ipAdd
   * Referenced by: '<S1>/UDP Configure'
   */
  { 10.0, 10.0, 11.0, 1.0 },

  /* Computed Parameter: UDPConfigure_P2_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 1.0, 4.0 },

  /* Expression: snMask
   * Referenced by: '<S1>/UDP Configure'
   */
  { 255.0, 255.0, 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P3_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 1.0, 4.0 },

  /* Expression: gwAdd
   * Referenced by: '<S1>/UDP Configure'
   */
  { 10.0, 10.0, 10.0, 4.0 },

  /* Computed Parameter: UDPConfigure_P4_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P5_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: enableMulticast
   * Referenced by: '<S1>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P6_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P7_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: UDPConfigure_P8_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: PciBus
   * Referenced by: '<S1>/UDP Configure'
   */
  3.0,

  /* Computed Parameter: UDPConfigure_P9_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: PciSlot
   * Referenced by: '<S1>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P10_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: PciFunction
   * Referenced by: '<S1>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P11_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: tune
   * Referenced by: '<S1>/UDP Configure'
   */
  0.0,

  /* Computed Parameter: UDPConfigure_P12_Size
   * Referenced by: '<S1>/UDP Configure'
   */
  { 1.0, 1.0 },

  /* Expression: disable
   * Referenced by: '<S1>/UDP Configure'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S1>/Sine Wave1'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S1>/Sine Wave1'
   */
  10.0,

  /* Computed Parameter: SineWave1_Hsin
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.0099998333341666645,

  /* Computed Parameter: SineWave1_HCos
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.99995000041666526,

  /* Computed Parameter: SineWave1_PSin
   * Referenced by: '<S1>/Sine Wave1'
   */
  -0.0099998333341666645,

  /* Computed Parameter: SineWave1_PCos
   * Referenced by: '<S1>/Sine Wave1'
   */
  0.99995000041666526,

  /* Expression: 100
   * Referenced by: '<S1>/Sine Wave5'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave5'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S1>/Sine Wave5'
   */
  100.0,

  /* Computed Parameter: SineWave5_Hsin
   * Referenced by: '<S1>/Sine Wave5'
   */
  0.099833416646828155,

  /* Computed Parameter: SineWave5_HCos
   * Referenced by: '<S1>/Sine Wave5'
   */
  0.99500416527802571,

  /* Computed Parameter: SineWave5_PSin
   * Referenced by: '<S1>/Sine Wave5'
   */
  -0.099833416646828155,

  /* Computed Parameter: SineWave5_PCos
   * Referenced by: '<S1>/Sine Wave5'
   */
  0.99500416527802571,

  /* Expression: 1000
   * Referenced by: '<S1>/Sine Wave6'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S1>/Sine Wave6'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Sine Wave6'
   */
  1000.0,

  /* Computed Parameter: SineWave6_Hsin
   * Referenced by: '<S1>/Sine Wave6'
   */
  0.8414709848078965,

  /* Computed Parameter: SineWave6_HCos
   * Referenced by: '<S1>/Sine Wave6'
   */
  0.54030230586813977,

  /* Computed Parameter: SineWave6_PSin
   * Referenced by: '<S1>/Sine Wave6'
   */
  -0.8414709848078965,

  /* Computed Parameter: SineWave6_PCos
   * Referenced by: '<S1>/Sine Wave6'
   */
  0.54030230586813977,

  /* Computed Parameter: UDPSend1_P1_Size
   * Referenced by: '<S1>/UDP Send1'
   */
  { 1.0, 10.0 },

  /* Computed Parameter: UDPSend1_P1
   * Referenced by: '<S1>/UDP Send1'
   */
  { 49.0, 48.0, 46.0, 49.0, 48.0, 46.0, 49.0, 49.0, 46.0, 49.0 },

  /* Computed Parameter: UDPSend1_P2_Size
   * Referenced by: '<S1>/UDP Send1'
   */
  { 1.0, 1.0 },

  /* Expression: localPort
   * Referenced by: '<S1>/UDP Send1'
   */
  25002.0,

  /* Computed Parameter: UDPSend1_P3_Size
   * Referenced by: '<S1>/UDP Send1'
   */
  { 1.0, 10.0 },

  /* Computed Parameter: UDPSend1_P3
   * Referenced by: '<S1>/UDP Send1'
   */
  { 49.0, 48.0, 46.0, 49.0, 48.0, 46.0, 49.0, 48.0, 46.0, 52.0 },

  /* Computed Parameter: UDPSend1_P4_Size
   * Referenced by: '<S1>/UDP Send1'
   */
  { 1.0, 1.0 },

  /* Expression: toPort
   * Referenced by: '<S1>/UDP Send1'
   */
  20009.0,

  /* Computed Parameter: UDPSend1_P5_Size
   * Referenced by: '<S1>/UDP Send1'
   */
  { 1.0, 1.0 },

  /* Expression: useHostTargetComm
   * Referenced by: '<S1>/UDP Send1'
   */
  0.0,

  /* Computed Parameter: UDPSend1_P6_Size
   * Referenced by: '<S1>/UDP Send1'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S1>/UDP Send1'
   */
  -1.0
};
