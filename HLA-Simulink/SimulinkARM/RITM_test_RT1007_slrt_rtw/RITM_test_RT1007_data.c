/*
 * RITM_test_RT1007_data.c
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

#include "RITM_test_RT1007.h"
#include "RITM_test_RT1007_private.h"

/* Invariant block signals (default storage) */
const ConstB_RITM_test_RT1007_T RITM_test_RT1007_ConstB = {
  4U                                   /* '<S5>/Width' */
};

/* Block parameters (default storage) */
P_RITM_test_RT1007_T RITM_test_RT1007_P = {
  /* Mask Parameter: CounterLimited1_uplimit
   * Referenced by: '<S14>/FixPt Switch'
   */
  20U,

  /* Mask Parameter: CounterLimited_uplimit
   * Referenced by: '<S18>/FixPt Switch'
   */
  255U,

  /* Computed Parameter: BA_IS_gpio_di_P1_Size
   * Referenced by: '<S1>/BA_IS_gpio_di'
   */
  { 1.0, 1.0 },

  /* Expression: boardId-1
   * Referenced by: '<S1>/BA_IS_gpio_di'
   */
  0.0,

  /* Computed Parameter: BA_IS_gpio_di_P2_Size
   * Referenced by: '<S1>/BA_IS_gpio_di'
   */
  { 1.0, 13.0 },

  /* Expression: channels-1
   * Referenced by: '<S1>/BA_IS_gpio_di'
   */
  { 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0
  },

  /* Computed Parameter: BA_IS_gpio_di_P3_Size
   * Referenced by: '<S1>/BA_IS_gpio_di'
   */
  { 1.0, 1.0 },

  /* Expression: voltage
   * Referenced by: '<S1>/BA_IS_gpio_di'
   */
  1.0,

  /* Computed Parameter: BA_IS_gpio_di_P4_Size
   * Referenced by: '<S1>/BA_IS_gpio_di'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S1>/BA_IS_gpio_di'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Twice a second'
   */
  1.0,

  /* Expression: 1000
   * Referenced by: '<S1>/Twice a second'
   */
  1000.0,

  /* Expression: 500
   * Referenced by: '<S1>/Twice a second'
   */
  500.0,

  /* Expression: 0
   * Referenced by: '<S1>/Twice a second'
   */
  0.0,

  /* Computed Parameter: BA_IS_gpio_do_P1_Size
   * Referenced by: '<S1>/BA_IS_gpio_do'
   */
  { 1.0, 1.0 },

  /* Expression: boardId-1
   * Referenced by: '<S1>/BA_IS_gpio_do'
   */
  0.0,

  /* Computed Parameter: BA_IS_gpio_do_P2_Size
   * Referenced by: '<S1>/BA_IS_gpio_do'
   */
  { 1.0, 13.0 },

  /* Expression: channels-1
   * Referenced by: '<S1>/BA_IS_gpio_do'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0 },

  /* Computed Parameter: BA_IS_gpio_do_P3_Size
   * Referenced by: '<S1>/BA_IS_gpio_do'
   */
  { 1.0, 1.0 },

  /* Expression: voltage
   * Referenced by: '<S1>/BA_IS_gpio_do'
   */
  1.0,

  /* Computed Parameter: BA_IS_gpio_do_P4_Size
   * Referenced by: '<S1>/BA_IS_gpio_do'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S1>/BA_IS_gpio_do'
   */
  -1.0,

  /* Computed Parameter: BAISI2C_read_P1_Size
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  1.0,

  /* Computed Parameter: BAISI2C_read_P2_Size
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  0.0,

  /* Computed Parameter: BAISI2C_read_P3_Size
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  { 1.0, 1.0 },

  /* Expression: 2-mode
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  0.0,

  /* Computed Parameter: BAISI2C_read_P4_Size
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  { 1.0, 1.0 },

  /* Expression: address
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  52.0,

  /* Computed Parameter: BAISI2C_read_P5_Size
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  { 1.0, 1.0 },

  /* Expression: numwords
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  4.0,

  /* Computed Parameter: BAISI2C_read_P6_Size
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S2>/BA-IS-I2C_read'
   */
  -1.0,

  /* Computed Parameter: BAISCAP_P1_Size
   * Referenced by: '<S3>/BA-IS-CAP'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S3>/BA-IS-CAP'
   */
  1.0,

  /* Computed Parameter: BAISCAP_P2_Size
   * Referenced by: '<S3>/BA-IS-CAP'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S3>/BA-IS-CAP'
   */
  0.0,

  /* Computed Parameter: BAISCAP_P3_Size
   * Referenced by: '<S3>/BA-IS-CAP'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S3>/BA-IS-CAP'
   */
  -1.0,

  /* Computed Parameter: BAISCAP1_P1_Size
   * Referenced by: '<S3>/BA-IS-CAP1'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S3>/BA-IS-CAP1'
   */
  1.0,

  /* Computed Parameter: BAISCAP1_P2_Size
   * Referenced by: '<S3>/BA-IS-CAP1'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S3>/BA-IS-CAP1'
   */
  1.0,

  /* Computed Parameter: BAISCAP1_P3_Size
   * Referenced by: '<S3>/BA-IS-CAP1'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S3>/BA-IS-CAP1'
   */
  -1.0,

  /* Computed Parameter: BAISCAP2_P1_Size
   * Referenced by: '<S3>/BA-IS-CAP2'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S3>/BA-IS-CAP2'
   */
  1.0,

  /* Computed Parameter: BAISCAP2_P2_Size
   * Referenced by: '<S3>/BA-IS-CAP2'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S3>/BA-IS-CAP2'
   */
  2.0,

  /* Computed Parameter: BAISCAP2_P3_Size
   * Referenced by: '<S3>/BA-IS-CAP2'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S3>/BA-IS-CAP2'
   */
  -1.0,

  /* Computed Parameter: BAISCAP3_P1_Size
   * Referenced by: '<S3>/BA-IS-CAP3'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S3>/BA-IS-CAP3'
   */
  1.0,

  /* Computed Parameter: BAISCAP3_P2_Size
   * Referenced by: '<S3>/BA-IS-CAP3'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S3>/BA-IS-CAP3'
   */
  9.0,

  /* Computed Parameter: BAISCAP3_P3_Size
   * Referenced by: '<S3>/BA-IS-CAP3'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S3>/BA-IS-CAP3'
   */
  -1.0,

  /* Expression: 0.01
   * Referenced by: '<S3>/Constant1'
   */
  0.01,

  /* Expression: 50
   * Referenced by: '<S3>/Constant8'
   */
  50.0,

  /* Computed Parameter: BAISPWM_P1_Size
   * Referenced by: '<S3>/BA-IS-PWM'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S3>/BA-IS-PWM'
   */
  1.0,

  /* Computed Parameter: BAISPWM_P2_Size
   * Referenced by: '<S3>/BA-IS-PWM'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S3>/BA-IS-PWM'
   */
  0.0,

  /* Computed Parameter: BAISPWM_P3_Size
   * Referenced by: '<S3>/BA-IS-PWM'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S3>/BA-IS-PWM'
   */
  -1.0,

  /* Expression: 0.001
   * Referenced by: '<S3>/Constant2'
   */
  0.001,

  /* Expression: 25
   * Referenced by: '<S3>/Constant3'
   */
  25.0,

  /* Computed Parameter: BAISPWM1_P1_Size
   * Referenced by: '<S3>/BA-IS-PWM1'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S3>/BA-IS-PWM1'
   */
  1.0,

  /* Computed Parameter: BAISPWM1_P2_Size
   * Referenced by: '<S3>/BA-IS-PWM1'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S3>/BA-IS-PWM1'
   */
  1.0,

  /* Computed Parameter: BAISPWM1_P3_Size
   * Referenced by: '<S3>/BA-IS-PWM1'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S3>/BA-IS-PWM1'
   */
  -1.0,

  /* Computed Parameter: BAISSPI1_P1_Size
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  1.0,

  /* Computed Parameter: BAISSPI1_P2_Size
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  1.0,

  /* Computed Parameter: BAISSPI1_P3_Size
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  { 1.0, 1.0 },

  /* Expression: 2-mode
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  0.0,

  /* Computed Parameter: BAISSPI1_P4_Size
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  { 1.0, 1.0 },

  /* Expression: polarity-1
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  0.0,

  /* Computed Parameter: BAISSPI1_P5_Size
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  { 1.0, 1.0 },

  /* Expression: phase-1
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  0.0,

  /* Computed Parameter: BAISSPI1_P6_Size
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  { 1.0, 1.0 },

  /* Expression: numwords
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  4.0,

  /* Computed Parameter: BAISSPI1_P7_Size
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  { 1.0, 1.0 },

  /* Expression: divider-1
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  4.0,

  /* Computed Parameter: BAISSPI1_P8_Size
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S4>/BA-IS-SPI1'
   */
  -1.0,

  /* Computed Parameter: BAISUART_setup_P1_Size
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  { 1.0, 1.0 },

  /* Expression: boardId-1
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  0.0,

  /* Computed Parameter: BAISUART_setup_P2_Size
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  0.0,

  /* Computed Parameter: BAISUART_setup_P3_Size
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  { 1.0, 1.0 },

  /* Expression: baudRate-1
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  8.0,

  /* Computed Parameter: BAISUART_setup_P4_Size
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  { 1.0, 1.0 },

  /* Expression: dataLen-1
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  3.0,

  /* Computed Parameter: BAISUART_setup_P5_Size
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  { 1.0, 1.0 },

  /* Expression: stopBit-1
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  0.0,

  /* Computed Parameter: BAISUART_setup_P6_Size
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  { 1.0, 1.0 },

  /* Expression: parityType-1
   * Referenced by: '<S5>/BA-IS-UART_setup'
   */
  0.0,

  /* Computed Parameter: BAISUART_rx_P1_Size
   * Referenced by: '<S5>/BA-IS-UART_rx'
   */
  { 1.0, 1.0 },

  /* Expression: boardId-1
   * Referenced by: '<S5>/BA-IS-UART_rx'
   */
  0.0,

  /* Computed Parameter: BAISUART_rx_P2_Size
   * Referenced by: '<S5>/BA-IS-UART_rx'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S5>/BA-IS-UART_rx'
   */
  0.0,

  /* Computed Parameter: BAISUART_rx_P3_Size
   * Referenced by: '<S5>/BA-IS-UART_rx'
   */
  { 1.0, 1.0 },

  /* Expression: baudRate
   * Referenced by: '<S5>/BA-IS-UART_rx'
   */
  115200.0,

  /* Computed Parameter: BAISUART_rx_P4_Size
   * Referenced by: '<S5>/BA-IS-UART_rx'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S5>/BA-IS-UART_rx'
   */
  0.001,

  /* Computed Parameter: BAISUART_tx_P1_Size
   * Referenced by: '<S5>/BA-IS-UART_tx'
   */
  { 1.0, 1.0 },

  /* Expression: boardId-1
   * Referenced by: '<S5>/BA-IS-UART_tx'
   */
  0.0,

  /* Computed Parameter: BAISUART_tx_P2_Size
   * Referenced by: '<S5>/BA-IS-UART_tx'
   */
  { 1.0, 1.0 },

  /* Expression: channel-1
   * Referenced by: '<S5>/BA-IS-UART_tx'
   */
  0.0,

  /* Computed Parameter: BAISUART_tx_P3_Size
   * Referenced by: '<S5>/BA-IS-UART_tx'
   */
  { 1.0, 1.0 },

  /* Expression: baudRate
   * Referenced by: '<S5>/BA-IS-UART_tx'
   */
  115200.0,

  /* Computed Parameter: BAISUART_tx_P4_Size
   * Referenced by: '<S5>/BA-IS-UART_tx'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S5>/BA-IS-UART_tx'
   */
  -1.0,

  /* Computed Parameter: CA_MA_rx_P1_Size
   * Referenced by: '<S6>/CA_MA_rx'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S6>/CA_MA_rx'
   */
  1.0,

  /* Computed Parameter: CA_MA_rx_P2_Size
   * Referenced by: '<S6>/CA_MA_rx'
   */
  { 1.0, 1.0 },

  /* Expression: channel
   * Referenced by: '<S6>/CA_MA_rx'
   */
  2.0,

  /* Computed Parameter: CA_MA_rx_P3_Size
   * Referenced by: '<S6>/CA_MA_rx'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S6>/CA_MA_rx'
   */
  -1.0,

  /* Computed Parameter: CA_MA_status_P1_Size
   * Referenced by: '<S19>/CA_MA_status'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S19>/CA_MA_status'
   */
  1.0,

  /* Computed Parameter: CA_MA_status_P2_Size
   * Referenced by: '<S19>/CA_MA_status'
   */
  { 1.0, 1.0 },

  /* Expression: channel
   * Referenced by: '<S19>/CA_MA_status'
   */
  1.0,

  /* Computed Parameter: CA_MA_status_P3_Size
   * Referenced by: '<S19>/CA_MA_status'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S19>/CA_MA_status'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S6>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Sine Wave'
   */
  0.0,

  /* Expression: 5*pi
   * Referenced by: '<S6>/Sine Wave'
   */
  15.707963267948966,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<S6>/Sine Wave'
   */
  0.015707317311820675,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<S6>/Sine Wave'
   */
  0.99987663248166059,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<S6>/Sine Wave'
   */
  -0.015707317311820675,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<S6>/Sine Wave'
   */
  0.99987663248166059,

  /* Computed Parameter: CA_MA_tx_P1_Size
   * Referenced by: '<S6>/CA_MA_tx'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S6>/CA_MA_tx'
   */
  1.0,

  /* Computed Parameter: CA_MA_tx_P2_Size
   * Referenced by: '<S6>/CA_MA_tx'
   */
  { 1.0, 1.0 },

  /* Expression: channel
   * Referenced by: '<S6>/CA_MA_tx'
   */
  1.0,

  /* Computed Parameter: CA_MA_tx_P3_Size
   * Referenced by: '<S6>/CA_MA_tx'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S6>/CA_MA_tx'
   */
  -1.0,

  /* Computed Parameter: CA_MA_rx1_P1_Size
   * Referenced by: '<S6>/CA_MA_rx1'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S6>/CA_MA_rx1'
   */
  1.0,

  /* Computed Parameter: CA_MA_rx1_P2_Size
   * Referenced by: '<S6>/CA_MA_rx1'
   */
  { 1.0, 1.0 },

  /* Expression: channel
   * Referenced by: '<S6>/CA_MA_rx1'
   */
  1.0,

  /* Computed Parameter: CA_MA_rx1_P3_Size
   * Referenced by: '<S6>/CA_MA_rx1'
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<S6>/CA_MA_rx1'
   */
  -1.0,

  /* Computed Parameter: CA_MA_setup_P1_Size
   * Referenced by: '<S6>/CA_MA_setup'
   */
  { 1.0, 1.0 },

  /* Expression: boardId
   * Referenced by: '<S6>/CA_MA_setup'
   */
  1.0,

  /* Computed Parameter: CA_MA_setup_P2_Size
   * Referenced by: '<S6>/CA_MA_setup'
   */
  { 1.0, 1.0 },

  /* Expression: baudRate1
   * Referenced by: '<S6>/CA_MA_setup'
   */
  7.0,

  /* Computed Parameter: CA_MA_setup_P3_Size
   * Referenced by: '<S6>/CA_MA_setup'
   */
  { 1.0, 1.0 },

  /* Expression: baudRate2
   * Referenced by: '<S6>/CA_MA_setup'
   */
  7.0,

  /* Computed Parameter: CA_MA_setup_P4_Size
   * Referenced by: '<S6>/CA_MA_setup'
   */
  { 1.0, 3.0 },

  /* Expression: filter1
   * Referenced by: '<S6>/CA_MA_setup'
   */
  { 1.0, 0.0, 0.0 },

  /* Computed Parameter: CA_MA_setup_P5_Size
   * Referenced by: '<S6>/CA_MA_setup'
   */
  { 1.0, 3.0 },

  /* Expression: filter2
   * Referenced by: '<S6>/CA_MA_setup'
   */
  { 1.0, 0.0, 0.0 },

  /* Computed Parameter: CA_MA_setup_P6_Size
   * Referenced by: '<S6>/CA_MA_setup'
   */
  { 1.0, 1.0 },

  /* Expression: boffRecover1
   * Referenced by: '<S6>/CA_MA_setup'
   */
  1.0,

  /* Computed Parameter: CA_MA_setup_P7_Size
   * Referenced by: '<S6>/CA_MA_setup'
   */
  { 1.0, 1.0 },

  /* Expression: boffRecover2
   * Referenced by: '<S6>/CA_MA_setup'
   */
  1.0,

  /* Computed Parameter: ASCIIDecode_P1_Size
   * Referenced by: '<S7>/ASCII Decode '
   */
  { 1.0, 3.0 },

  /* Computed Parameter: ASCIIDecode_P1
   * Referenced by: '<S7>/ASCII Decode '
   */
  { 37.0, 102.0, 13.0 },

  /* Computed Parameter: ASCIIDecode_P2_Size
   * Referenced by: '<S7>/ASCII Decode '
   */
  { 1.0, 1.0 },

  /* Expression: nvars
   * Referenced by: '<S7>/ASCII Decode '
   */
  1.0,

  /* Computed Parameter: ASCIIDecode_P3_Size
   * Referenced by: '<S7>/ASCII Decode '
   */
  { 1.0, 1.0 },

  /* Expression: varids
   * Referenced by: '<S7>/ASCII Decode '
   */
  0.0,

  /* Computed Parameter: Setup1_P1_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: addr
   * Referenced by: '<S24>/Setup1'
   */
  760.0,

  /* Computed Parameter: Setup1_P2_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: baud
   * Referenced by: '<S24>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P3_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: width
   * Referenced by: '<S24>/Setup1'
   */
  4.0,

  /* Computed Parameter: Setup1_P4_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: nstop
   * Referenced by: '<S24>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P5_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: parity
   * Referenced by: '<S24>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P6_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: fmode
   * Referenced by: '<S24>/Setup1'
   */
  2.0,

  /* Computed Parameter: Setup1_P7_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: ctsmode
   * Referenced by: '<S24>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P8_Size
   * Referenced by: '<S24>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: rlevel
   * Referenced by: '<S24>/Setup1'
   */
  3.0,

  /* Computed Parameter: Setup2_P1_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: addr
   * Referenced by: '<S24>/Setup2'
   */
  0.0,

  /* Computed Parameter: Setup2_P2_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: baud
   * Referenced by: '<S24>/Setup2'
   */
  1.0,

  /* Computed Parameter: Setup2_P3_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: width
   * Referenced by: '<S24>/Setup2'
   */
  4.0,

  /* Computed Parameter: Setup2_P4_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: nstop
   * Referenced by: '<S24>/Setup2'
   */
  1.0,

  /* Computed Parameter: Setup2_P5_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: parity
   * Referenced by: '<S24>/Setup2'
   */
  1.0,

  /* Computed Parameter: Setup2_P6_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: fmode
   * Referenced by: '<S24>/Setup2'
   */
  2.0,

  /* Computed Parameter: Setup2_P7_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: ctsmode
   * Referenced by: '<S24>/Setup2'
   */
  0.0,

  /* Computed Parameter: Setup2_P8_Size
   * Referenced by: '<S24>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: rlevel
   * Referenced by: '<S24>/Setup2'
   */
  3.0,

  /* Expression: 2
   * Referenced by: '<S7>/Sine Wave'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S7>/Sine Wave'
   */
  1.0,

  /* Expression: 4*pi
   * Referenced by: '<S7>/Sine Wave'
   */
  12.566370614359172,

  /* Computed Parameter: SineWave_Hsin_j
   * Referenced by: '<S7>/Sine Wave'
   */
  0.12533323356430426,

  /* Computed Parameter: SineWave_HCos_f
   * Referenced by: '<S7>/Sine Wave'
   */
  0.99211470131447788,

  /* Computed Parameter: SineWave_PSin_p
   * Referenced by: '<S7>/Sine Wave'
   */
  -0.12533323356430426,

  /* Computed Parameter: SineWave_PCos_d
   * Referenced by: '<S7>/Sine Wave'
   */
  0.99211470131447788,

  /* Computed Parameter: ASCIIEncode_P1_Size
   * Referenced by: '<S7>/ASCII Encode '
   */
  { 1.0, 3.0 },

  /* Computed Parameter: ASCIIEncode_P1
   * Referenced by: '<S7>/ASCII Encode '
   */
  { 37.0, 102.0, 13.0 },

  /* Computed Parameter: ASCIIEncode_P2_Size
   * Referenced by: '<S7>/ASCII Encode '
   */
  { 1.0, 1.0 },

  /* Expression: maxlength
   * Referenced by: '<S7>/ASCII Encode '
   */
  128.0,

  /* Computed Parameter: ASCIIEncode_P3_Size
   * Referenced by: '<S7>/ASCII Encode '
   */
  { 1.0, 1.0 },

  /* Expression: nvars
   * Referenced by: '<S7>/ASCII Encode '
   */
  1.0,

  /* Computed Parameter: ASCIIEncode_P4_Size
   * Referenced by: '<S7>/ASCII Encode '
   */
  { 1.0, 1.0 },

  /* Expression: varids
   * Referenced by: '<S7>/ASCII Encode '
   */
  0.0,

  /* Computed Parameter: Setup1_P1_Size_o
   * Referenced by: '<S23>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: addr
   * Referenced by: '<S23>/Setup1'
   */
  1016.0,

  /* Computed Parameter: Setup1_P2_Size_l
   * Referenced by: '<S23>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: baud
   * Referenced by: '<S23>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P3_Size_j
   * Referenced by: '<S23>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: width
   * Referenced by: '<S23>/Setup1'
   */
  4.0,

  /* Computed Parameter: Setup1_P4_Size_b
   * Referenced by: '<S23>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: nstop
   * Referenced by: '<S23>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P5_Size_a
   * Referenced by: '<S23>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: parity
   * Referenced by: '<S23>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P6_Size_i
   * Referenced by: '<S23>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: fmode
   * Referenced by: '<S23>/Setup1'
   */
  2.0,

  /* Computed Parameter: Setup1_P7_Size_p
   * Referenced by: '<S23>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: ctsmode
   * Referenced by: '<S23>/Setup1'
   */
  1.0,

  /* Computed Parameter: Setup1_P8_Size_k
   * Referenced by: '<S23>/Setup1'
   */
  { 1.0, 1.0 },

  /* Expression: rlevel
   * Referenced by: '<S23>/Setup1'
   */
  3.0,

  /* Computed Parameter: Setup2_P1_Size_a
   * Referenced by: '<S23>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: addr
   * Referenced by: '<S23>/Setup2'
   */
  0.0,

  /* Computed Parameter: Setup2_P2_Size_h
   * Referenced by: '<S23>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: baud
   * Referenced by: '<S23>/Setup2'
   */
  1.0,

  /* Computed Parameter: Setup2_P3_Size_h
   * Referenced by: '<S23>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: width
   * Referenced by: '<S23>/Setup2'
   */
  4.0,

  /* Computed Parameter: Setup2_P4_Size_m
   * Referenced by: '<S23>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: nstop
   * Referenced by: '<S23>/Setup2'
   */
  1.0,

  /* Computed Parameter: Setup2_P5_Size_e
   * Referenced by: '<S23>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: parity
   * Referenced by: '<S23>/Setup2'
   */
  1.0,

  /* Computed Parameter: Setup2_P6_Size_b
   * Referenced by: '<S23>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: fmode
   * Referenced by: '<S23>/Setup2'
   */
  2.0,

  /* Computed Parameter: Setup2_P7_Size_h
   * Referenced by: '<S23>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: ctsmode
   * Referenced by: '<S23>/Setup2'
   */
  0.0,

  /* Computed Parameter: Setup2_P8_Size_l
   * Referenced by: '<S23>/Setup2'
   */
  { 1.0, 1.0 },

  /* Expression: rlevel
   * Referenced by: '<S23>/Setup2'
   */
  3.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S27>/Constant'
   */
  1U,

  /* Computed Parameter: Constant1_Value_h
   * Referenced by: '<S29>/Constant1'
   */
  1U,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S28>/Constant'
   */
  1U,

  /* Computed Parameter: Constant2_Value_d
   * Referenced by: '<S30>/Constant2'
   */
  1U,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S32>/Constant'
   */
  1U,

  /* Computed Parameter: Constant1_Value_he
   * Referenced by: '<S34>/Constant1'
   */
  1U,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S33>/Constant'
   */
  1U,

  /* Computed Parameter: Constant2_Value_p
   * Referenced by: '<S35>/Constant2'
   */
  1U,

  /* Computed Parameter: Bias1_Bias
   * Referenced by: '<S4>/Bias1'
   */
  { 128U, 129U, 130U, 131U },

  /* Computed Parameter: Generatesomedata_Value
   * Referenced by: '<S4>/Generate some data'
   */
  { 8U, 6U, 4U, 1U },

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S11>/Output'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S4>/Manual Switch'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S13>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S14>/Constant'
   */
  0U,

  /* Computed Parameter: Generatesomedata_Value_l
   * Referenced by: '<S5>/Generate some data'
   */
  { 1U, 2U, 3U, 4U },

  /* Computed Parameter: Output_InitialCondition_b
   * Referenced by: '<S15>/Output'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting_m
   * Referenced by: '<S5>/Manual Switch'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_k
   * Referenced by: '<S17>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S18>/Constant'
   */
  0U
};
