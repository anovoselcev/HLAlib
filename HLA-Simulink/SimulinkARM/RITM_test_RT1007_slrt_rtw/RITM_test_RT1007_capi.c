/*
 * RITM_test_RT1007_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "RITM_test_RT1007_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "RITM_test_RT1007.h"
#include "RITM_test_RT1007_capi.h"
#include "RITM_test_RT1007_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 1, TARGET_STRING("BA-IS-GPIO/Twice a second"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 3, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 0 },

  { 4, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p4"),
    TARGET_STRING(""), 3, 0, 0, 0, 0 },

  { 5, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p5"),
    TARGET_STRING(""), 4, 0, 0, 0, 0 },

  { 6, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p6"),
    TARGET_STRING(""), 5, 0, 0, 0, 0 },

  { 7, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p7"),
    TARGET_STRING(""), 6, 0, 0, 0, 0 },

  { 8, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p8"),
    TARGET_STRING(""), 7, 0, 0, 0, 0 },

  { 9, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p9"),
    TARGET_STRING(""), 8, 0, 0, 0, 0 },

  { 10, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p10"),
    TARGET_STRING(""), 9, 0, 0, 0, 0 },

  { 11, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p11"),
    TARGET_STRING(""), 10, 0, 0, 0, 0 },

  { 12, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p12"),
    TARGET_STRING(""), 11, 0, 0, 0, 0 },

  { 13, 1, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di/p13"),
    TARGET_STRING(""), 12, 0, 0, 0, 0 },

  { 14, 2, TARGET_STRING("BA-IS-I2C/BA-IS-I2C_read/p1"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 15, 2, TARGET_STRING("BA-IS-I2C/BA-IS-I2C_read/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 1 },

  { 16, 3, TARGET_STRING("BA-IS-PWM-CAP/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 3, TARGET_STRING("BA-IS-PWM-CAP/Constant2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 18, 3, TARGET_STRING("BA-IS-PWM-CAP/Constant3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 19, 3, TARGET_STRING("BA-IS-PWM-CAP/Constant8"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 20, 3, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 21, 3, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 22, 3, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP1/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 23, 3, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP1/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 24, 3, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP2/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 25, 3, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP2/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 26, 3, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP3/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 27, 3, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP3/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 28, 4, TARGET_STRING("BA-IS-SPI/Bias1"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 29, 6, TARGET_STRING("BA-IS-SPI/BA-IS-SPI1"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 30, 6, TARGET_STRING("BA-IS-SPI/Manual Switch"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 31, 7, TARGET_STRING("BA-IS-UART/BA-IS-UART_rx/p1"),
    TARGET_STRING(""), 0, 1, 2, 0, 0 },

  { 32, 7, TARGET_STRING("BA-IS-UART/BA-IS-UART_rx/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 0 },

  { 33, 7, TARGET_STRING("BA-IS-UART/BA-IS-UART_rx/p3"),
    TARGET_STRING(""), 2, 2, 0, 0, 0 },

  { 34, 7, TARGET_STRING("BA-IS-UART/Manual Switch"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 35, 7, TARGET_STRING("BA-IS-UART/Width"),
    TARGET_STRING(""), 0, 2, 0, 0, 2 },

  { 36, 8, TARGET_STRING("CA-MA-45/CAN Pack"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 37, 8, TARGET_STRING("CA-MA-45/CAN Unpack/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 38, 8, TARGET_STRING("CA-MA-45/CAN Unpack/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 0 },

  { 39, 8, TARGET_STRING("CA-MA-45/CAN Unpack/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 0 },

  { 40, 8, TARGET_STRING("CA-MA-45/CAN Unpack/p4"),
    TARGET_STRING(""), 3, 1, 0, 0, 0 },

  { 41, 8, TARGET_STRING("CA-MA-45/CAN Unpack/p5"),
    TARGET_STRING(""), 4, 1, 0, 0, 0 },

  { 42, 8, TARGET_STRING("CA-MA-45/CAN Unpack/p6"),
    TARGET_STRING(""), 5, 1, 0, 0, 0 },

  { 43, 8, TARGET_STRING("CA-MA-45/CAN Unpack/p7"),
    TARGET_STRING(""), 6, 1, 0, 0, 0 },

  { 44, 8, TARGET_STRING("CA-MA-45/CA_MA_rx/p1"),
    TARGET_STRING(""), 0, 4, 0, 0, 0 },

  { 45, 8, TARGET_STRING("CA-MA-45/CA_MA_rx/p2"),
    TARGET_STRING(""), 1, 3, 0, 0, 0 },

  { 46, 8, TARGET_STRING("CA-MA-45/CA_MA_rx1/p1"),
    TARGET_STRING(""), 0, 4, 0, 0, 0 },

  { 47, 8, TARGET_STRING("CA-MA-45/CA_MA_rx1/p2"),
    TARGET_STRING(""), 1, 3, 0, 0, 0 },

  { 48, 8, TARGET_STRING("CA-MA-45/CA_MA_tx"),
    TARGET_STRING(""), 0, 4, 0, 0, 0 },

  { 49, 8, TARGET_STRING("CA-MA-45/Sine Wave"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 50, 19, TARGET_STRING("RS-232/ASCII Decode "),
    TARGET_STRING(""), 0, 0, 0, 0, 3 },

  { 51, 19, TARGET_STRING("RS-232/ASCII Encode "),
    TARGET_STRING(""), 0, 1, 3, 0, 3 },

  { 52, 19, TARGET_STRING("RS-232/FIFO read "),
    TARGET_STRING(""), 0, 1, 4, 0, 3 },

  { 53, 19, TARGET_STRING("RS-232/Sine Wave"),
    TARGET_STRING(""), 0, 0, 0, 0, 3 },

  { 54, 6, TARGET_STRING("BA-IS-SPI/Counter Limited1/Output"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 55, 7, TARGET_STRING("BA-IS-UART/Counter Limited/Output"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 56, 8, TARGET_STRING("CA-MA-45/CA_MA_status/Signal Conversion"),
    TARGET_STRING("RxErrorCounter"), 0, 1, 0, 0, 0 },

  { 57, 8, TARGET_STRING("CA-MA-45/CA_MA_status/Signal Conversion1"),
    TARGET_STRING("TxErrorCounter"), 0, 1, 0, 0, 0 },

  { 58, 8, TARGET_STRING("CA-MA-45/CA_MA_status/CA_MA_status"),
    TARGET_STRING(""), 0, 1, 5, 0, 0 },

  { 59, 19, TARGET_STRING("RS-232/Baseboard Serial F/Rate Transition"),
    TARGET_STRING(""), 0, 5, 0, 0, 4 },

  { 60, 19, TARGET_STRING("RS-232/Baseboard Serial F/Rate Transition1"),
    TARGET_STRING(""), 0, 5, 0, 0, 3 },

  { 61, 19, TARGET_STRING("RS-232/Baseboard Serial F/Rate Transition2"),
    TARGET_STRING(""), 0, 5, 0, 0, 4 },

  { 62, 19, TARGET_STRING("RS-232/Baseboard Serial F/Rate Transition3"),
    TARGET_STRING(""), 0, 5, 0, 0, 3 },

  { 63, 19, TARGET_STRING("RS-232/Baseboard Serial F/FIFO write 1/p1"),
    TARGET_STRING(""), 0, 5, 0, 0, 3 },

  { 64, 19, TARGET_STRING("RS-232/Baseboard Serial F/FIFO write 1/p2"),
    TARGET_STRING(""), 1, 6, 0, 0, 3 },

  { 65, 19, TARGET_STRING("RS-232/Baseboard Serial F/FIFO write 2/p1"),
    TARGET_STRING(""), 0, 5, 0, 0, 3 },

  { 66, 19, TARGET_STRING("RS-232/Baseboard Serial F/FIFO write 2/p2"),
    TARGET_STRING(""), 1, 6, 0, 0, 3 },

  { 67, 19, TARGET_STRING("RS-232/Baseboard Serial F1/Rate Transition"),
    TARGET_STRING(""), 0, 5, 0, 0, 5 },

  { 68, 19, TARGET_STRING("RS-232/Baseboard Serial F1/Rate Transition1"),
    TARGET_STRING(""), 0, 5, 0, 0, 3 },

  { 69, 19, TARGET_STRING("RS-232/Baseboard Serial F1/Rate Transition2"),
    TARGET_STRING(""), 0, 5, 0, 0, 5 },

  { 70, 19, TARGET_STRING("RS-232/Baseboard Serial F1/Rate Transition3"),
    TARGET_STRING(""), 0, 5, 0, 0, 3 },

  { 71, 19, TARGET_STRING("RS-232/Baseboard Serial F1/FIFO write 1/p1"),
    TARGET_STRING(""), 0, 5, 0, 0, 3 },

  { 72, 19, TARGET_STRING("RS-232/Baseboard Serial F1/FIFO write 1/p2"),
    TARGET_STRING(""), 1, 6, 0, 0, 3 },

  { 73, 19, TARGET_STRING("RS-232/Baseboard Serial F1/FIFO write 2/p1"),
    TARGET_STRING(""), 0, 5, 0, 0, 3 },

  { 74, 19, TARGET_STRING("RS-232/Baseboard Serial F1/FIFO write 2/p2"),
    TARGET_STRING(""), 1, 6, 0, 0, 3 },

  { 75, 6, TARGET_STRING(
    "BA-IS-SPI/Counter Limited1/Increment Real World/FixPt Sum1"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 76, 6, TARGET_STRING("BA-IS-SPI/Counter Limited1/Wrap To Zero/FixPt Switch"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 77, 7, TARGET_STRING(
    "BA-IS-UART/Counter Limited/Increment Real World/FixPt Sum1"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 78, 7, TARGET_STRING("BA-IS-UART/Counter Limited/Wrap To Zero/FixPt Switch"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 79, 8, TARGET_STRING(
    "CA-MA-45/CA_MA_status/Extract Bits/Extract Desired Bits"),
    TARGET_STRING(""), 0, 1, 0, 1, 0 },

  { 80, 8, TARGET_STRING(
    "CA-MA-45/CA_MA_status/Extract Bits/Modify Scaling Only"),
    TARGET_STRING(""), 0, 1, 0, 1, 0 },

  { 81, 8, TARGET_STRING(
    "CA-MA-45/CA_MA_status/Extract Bits1/Extract Desired Bits"),
    TARGET_STRING(""), 0, 1, 0, 2, 0 },

  { 82, 8, TARGET_STRING(
    "CA-MA-45/CA_MA_status/Extract Bits1/Modify Scaling Only"),
    TARGET_STRING(""), 0, 1, 0, 1, 0 },

  { 83, 13, TARGET_STRING(
    "RS-232/Baseboard Serial F/RS232 ISR/Read Int Status FC1"),
    TARGET_STRING(""), 0, 2, 0, 0, 4 },

  { 84, 18, TARGET_STRING(
    "RS-232/Baseboard Serial F1/RS232 ISR/Read Int Status FC1"),
    TARGET_STRING(""), 0, 2, 0, 0, 5 },

  { 85, 9, TARGET_STRING(
    "RS-232/Baseboard Serial F/RS232 ISR/Receive 1/FIFO write 1"),
    TARGET_STRING(""), 0, 5, 0, 0, 4 },

  { 86, 9, TARGET_STRING(
    "RS-232/Baseboard Serial F/RS232 ISR/Receive 1/Read HW FIFO1"),
    TARGET_STRING(""), 0, 2, 6, 0, 4 },

  { 87, 10, TARGET_STRING(
    "RS-232/Baseboard Serial F/RS232 ISR/Receive 2/FIFO write 2"),
    TARGET_STRING(""), 0, 5, 0, 0, 4 },

  { 88, 10, TARGET_STRING(
    "RS-232/Baseboard Serial F/RS232 ISR/Receive 2/Read HW FIFO2"),
    TARGET_STRING(""), 0, 2, 6, 0, 4 },

  { 89, 11, TARGET_STRING(
    "RS-232/Baseboard Serial F/RS232 ISR/Transmit 1/FIFO read 1/p1"),
    TARGET_STRING(""), 0, 2, 7, 0, 4 },

  { 90, 11, TARGET_STRING(
    "RS-232/Baseboard Serial F/RS232 ISR/Transmit 1/FIFO read 1/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 4 },

  { 91, 12, TARGET_STRING(
    "RS-232/Baseboard Serial F/RS232 ISR/Transmit 2/FIFO read 2/p1"),
    TARGET_STRING(""), 0, 2, 7, 0, 4 },

  { 92, 12, TARGET_STRING(
    "RS-232/Baseboard Serial F/RS232 ISR/Transmit 2/FIFO read 2/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 4 },

  { 93, 14, TARGET_STRING(
    "RS-232/Baseboard Serial F1/RS232 ISR/Receive 1/FIFO write 1"),
    TARGET_STRING(""), 0, 5, 0, 0, 5 },

  { 94, 14, TARGET_STRING(
    "RS-232/Baseboard Serial F1/RS232 ISR/Receive 1/Read HW FIFO1"),
    TARGET_STRING(""), 0, 2, 6, 0, 5 },

  { 95, 15, TARGET_STRING(
    "RS-232/Baseboard Serial F1/RS232 ISR/Receive 2/FIFO write 2"),
    TARGET_STRING(""), 0, 5, 0, 0, 5 },

  { 96, 15, TARGET_STRING(
    "RS-232/Baseboard Serial F1/RS232 ISR/Receive 2/Read HW FIFO2"),
    TARGET_STRING(""), 0, 2, 6, 0, 5 },

  { 97, 16, TARGET_STRING(
    "RS-232/Baseboard Serial F1/RS232 ISR/Transmit 1/FIFO read 1/p1"),
    TARGET_STRING(""), 0, 2, 7, 0, 5 },

  { 98, 16, TARGET_STRING(
    "RS-232/Baseboard Serial F1/RS232 ISR/Transmit 1/FIFO read 1/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 5 },

  { 99, 17, TARGET_STRING(
    "RS-232/Baseboard Serial F1/RS232 ISR/Transmit 2/FIFO read 2/p1"),
    TARGET_STRING(""), 0, 2, 7, 0, 5 },

  { 100, 17, TARGET_STRING(
    "RS-232/Baseboard Serial F1/RS232 ISR/Transmit 2/FIFO read 2/p2"),
    TARGET_STRING(""), 1, 2, 0, 0, 5 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 101, TARGET_STRING("BA-IS-GPIO/Twice a second"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 102, TARGET_STRING("BA-IS-GPIO/Twice a second"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 103, TARGET_STRING("BA-IS-GPIO/Twice a second"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 104, TARGET_STRING("BA-IS-GPIO/Twice a second"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 105, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 106, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di"),
    TARGET_STRING("P2"), 0, 8, 0 },

  { 107, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 108, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_di"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 109, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_do"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 110, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_do"),
    TARGET_STRING("P2"), 0, 8, 0 },

  { 111, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_do"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 112, TARGET_STRING("BA-IS-GPIO/BA_IS_gpio_do"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 113, TARGET_STRING("BA-IS-I2C/BA-IS-I2C_read"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 114, TARGET_STRING("BA-IS-I2C/BA-IS-I2C_read"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 115, TARGET_STRING("BA-IS-I2C/BA-IS-I2C_read"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 116, TARGET_STRING("BA-IS-I2C/BA-IS-I2C_read"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 117, TARGET_STRING("BA-IS-I2C/BA-IS-I2C_read"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 118, TARGET_STRING("BA-IS-I2C/BA-IS-I2C_read"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 119, TARGET_STRING("BA-IS-PWM-CAP/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 120, TARGET_STRING("BA-IS-PWM-CAP/Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 121, TARGET_STRING("BA-IS-PWM-CAP/Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 122, TARGET_STRING("BA-IS-PWM-CAP/Constant8"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 123, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 124, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 125, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 126, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 127, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 128, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 129, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP2"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 130, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 131, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 132, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP3"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 133, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP3"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 134, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-CAP3"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 135, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-PWM"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 136, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-PWM"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 137, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-PWM"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 138, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-PWM1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 139, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-PWM1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 140, TARGET_STRING("BA-IS-PWM-CAP/BA-IS-PWM1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 141, TARGET_STRING("BA-IS-SPI/Counter Limited1"),
    TARGET_STRING("uplimit"), 1, 0, 0 },

  { 142, TARGET_STRING("BA-IS-SPI/Bias1"),
    TARGET_STRING("Bias"), 1, 9, 0 },

  { 143, TARGET_STRING("BA-IS-SPI/Generate some data"),
    TARGET_STRING("Value"), 1, 9, 0 },

  { 144, TARGET_STRING("BA-IS-SPI/BA-IS-SPI1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 145, TARGET_STRING("BA-IS-SPI/BA-IS-SPI1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 146, TARGET_STRING("BA-IS-SPI/BA-IS-SPI1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 147, TARGET_STRING("BA-IS-SPI/BA-IS-SPI1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 148, TARGET_STRING("BA-IS-SPI/BA-IS-SPI1"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 149, TARGET_STRING("BA-IS-SPI/BA-IS-SPI1"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 150, TARGET_STRING("BA-IS-SPI/BA-IS-SPI1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 151, TARGET_STRING("BA-IS-SPI/BA-IS-SPI1"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 152, TARGET_STRING("BA-IS-SPI/Manual Switch"),
    TARGET_STRING("CurrentSetting"), 1, 0, 0 },

  { 153, TARGET_STRING("BA-IS-UART/Counter Limited"),
    TARGET_STRING("uplimit"), 1, 0, 0 },

  { 154, TARGET_STRING("BA-IS-UART/Generate some data"),
    TARGET_STRING("Value"), 1, 9, 0 },

  { 155, TARGET_STRING("BA-IS-UART/BA-IS-UART_rx"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 156, TARGET_STRING("BA-IS-UART/BA-IS-UART_rx"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 157, TARGET_STRING("BA-IS-UART/BA-IS-UART_rx"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 158, TARGET_STRING("BA-IS-UART/BA-IS-UART_rx"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 159, TARGET_STRING("BA-IS-UART/BA-IS-UART_setup"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 160, TARGET_STRING("BA-IS-UART/BA-IS-UART_setup"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 161, TARGET_STRING("BA-IS-UART/BA-IS-UART_setup"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 162, TARGET_STRING("BA-IS-UART/BA-IS-UART_setup"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 163, TARGET_STRING("BA-IS-UART/BA-IS-UART_setup"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 164, TARGET_STRING("BA-IS-UART/BA-IS-UART_setup"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 165, TARGET_STRING("BA-IS-UART/BA-IS-UART_tx"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 166, TARGET_STRING("BA-IS-UART/BA-IS-UART_tx"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 167, TARGET_STRING("BA-IS-UART/BA-IS-UART_tx"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 168, TARGET_STRING("BA-IS-UART/BA-IS-UART_tx"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 169, TARGET_STRING("BA-IS-UART/Manual Switch"),
    TARGET_STRING("CurrentSetting"), 1, 0, 0 },

  { 170, TARGET_STRING("CA-MA-45/CA_MA_rx"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 171, TARGET_STRING("CA-MA-45/CA_MA_rx"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 172, TARGET_STRING("CA-MA-45/CA_MA_rx"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 173, TARGET_STRING("CA-MA-45/CA_MA_rx1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 174, TARGET_STRING("CA-MA-45/CA_MA_rx1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 175, TARGET_STRING("CA-MA-45/CA_MA_rx1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 176, TARGET_STRING("CA-MA-45/CA_MA_setup"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 177, TARGET_STRING("CA-MA-45/CA_MA_setup"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 178, TARGET_STRING("CA-MA-45/CA_MA_setup"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 179, TARGET_STRING("CA-MA-45/CA_MA_setup"),
    TARGET_STRING("P4"), 0, 10, 0 },

  { 180, TARGET_STRING("CA-MA-45/CA_MA_setup"),
    TARGET_STRING("P5"), 0, 10, 0 },

  { 181, TARGET_STRING("CA-MA-45/CA_MA_setup"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 182, TARGET_STRING("CA-MA-45/CA_MA_setup"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 183, TARGET_STRING("CA-MA-45/CA_MA_tx"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 184, TARGET_STRING("CA-MA-45/CA_MA_tx"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 185, TARGET_STRING("CA-MA-45/CA_MA_tx"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 186, TARGET_STRING("CA-MA-45/Sine Wave"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 187, TARGET_STRING("CA-MA-45/Sine Wave"),
    TARGET_STRING("Bias"), 0, 0, 0 },

  { 188, TARGET_STRING("CA-MA-45/Sine Wave"),
    TARGET_STRING("Frequency"), 0, 0, 0 },

  { 189, TARGET_STRING("CA-MA-45/Sine Wave"),
    TARGET_STRING("SinH"), 0, 0, 0 },

  { 190, TARGET_STRING("CA-MA-45/Sine Wave"),
    TARGET_STRING("CosH"), 0, 0, 0 },

  { 191, TARGET_STRING("CA-MA-45/Sine Wave"),
    TARGET_STRING("SinPhi"), 0, 0, 0 },

  { 192, TARGET_STRING("CA-MA-45/Sine Wave"),
    TARGET_STRING("CosPhi"), 0, 0, 0 },

  { 193, TARGET_STRING("RS-232/ASCII Decode "),
    TARGET_STRING("P1"), 0, 10, 0 },

  { 194, TARGET_STRING("RS-232/ASCII Decode "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 195, TARGET_STRING("RS-232/ASCII Decode "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 196, TARGET_STRING("RS-232/ASCII Encode "),
    TARGET_STRING("P1"), 0, 10, 0 },

  { 197, TARGET_STRING("RS-232/ASCII Encode "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 198, TARGET_STRING("RS-232/ASCII Encode "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 199, TARGET_STRING("RS-232/ASCII Encode "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 200, TARGET_STRING("RS-232/Sine Wave"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 201, TARGET_STRING("RS-232/Sine Wave"),
    TARGET_STRING("Bias"), 0, 0, 0 },

  { 202, TARGET_STRING("RS-232/Sine Wave"),
    TARGET_STRING("Frequency"), 0, 0, 0 },

  { 203, TARGET_STRING("RS-232/Sine Wave"),
    TARGET_STRING("SinH"), 0, 0, 0 },

  { 204, TARGET_STRING("RS-232/Sine Wave"),
    TARGET_STRING("CosH"), 0, 0, 0 },

  { 205, TARGET_STRING("RS-232/Sine Wave"),
    TARGET_STRING("SinPhi"), 0, 0, 0 },

  { 206, TARGET_STRING("RS-232/Sine Wave"),
    TARGET_STRING("CosPhi"), 0, 0, 0 },

  { 207, TARGET_STRING("BA-IS-SPI/Counter Limited1/Output"),
    TARGET_STRING("InitialCondition"), 1, 0, 0 },

  { 208, TARGET_STRING("BA-IS-UART/Counter Limited/Output"),
    TARGET_STRING("InitialCondition"), 1, 0, 0 },

  { 209, TARGET_STRING("CA-MA-45/CA_MA_status/CA_MA_status"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 210, TARGET_STRING("CA-MA-45/CA_MA_status/CA_MA_status"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 211, TARGET_STRING("CA-MA-45/CA_MA_status/CA_MA_status"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 212, TARGET_STRING("RS-232/Baseboard Serial F/Setup1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 213, TARGET_STRING("RS-232/Baseboard Serial F/Setup1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 214, TARGET_STRING("RS-232/Baseboard Serial F/Setup1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 215, TARGET_STRING("RS-232/Baseboard Serial F/Setup1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 216, TARGET_STRING("RS-232/Baseboard Serial F/Setup1"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 217, TARGET_STRING("RS-232/Baseboard Serial F/Setup1"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 218, TARGET_STRING("RS-232/Baseboard Serial F/Setup1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 219, TARGET_STRING("RS-232/Baseboard Serial F/Setup1"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 220, TARGET_STRING("RS-232/Baseboard Serial F/Setup2"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 221, TARGET_STRING("RS-232/Baseboard Serial F/Setup2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 222, TARGET_STRING("RS-232/Baseboard Serial F/Setup2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 223, TARGET_STRING("RS-232/Baseboard Serial F/Setup2"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 224, TARGET_STRING("RS-232/Baseboard Serial F/Setup2"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 225, TARGET_STRING("RS-232/Baseboard Serial F/Setup2"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 226, TARGET_STRING("RS-232/Baseboard Serial F/Setup2"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 227, TARGET_STRING("RS-232/Baseboard Serial F/Setup2"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 228, TARGET_STRING("RS-232/Baseboard Serial F1/Setup1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 229, TARGET_STRING("RS-232/Baseboard Serial F1/Setup1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 230, TARGET_STRING("RS-232/Baseboard Serial F1/Setup1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 231, TARGET_STRING("RS-232/Baseboard Serial F1/Setup1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 232, TARGET_STRING("RS-232/Baseboard Serial F1/Setup1"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 233, TARGET_STRING("RS-232/Baseboard Serial F1/Setup1"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 234, TARGET_STRING("RS-232/Baseboard Serial F1/Setup1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 235, TARGET_STRING("RS-232/Baseboard Serial F1/Setup1"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 236, TARGET_STRING("RS-232/Baseboard Serial F1/Setup2"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 237, TARGET_STRING("RS-232/Baseboard Serial F1/Setup2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 238, TARGET_STRING("RS-232/Baseboard Serial F1/Setup2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 239, TARGET_STRING("RS-232/Baseboard Serial F1/Setup2"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 240, TARGET_STRING("RS-232/Baseboard Serial F1/Setup2"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 241, TARGET_STRING("RS-232/Baseboard Serial F1/Setup2"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 242, TARGET_STRING("RS-232/Baseboard Serial F1/Setup2"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 243, TARGET_STRING("RS-232/Baseboard Serial F1/Setup2"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 244, TARGET_STRING("BA-IS-SPI/Counter Limited1/Increment Real World/FixPt Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 245, TARGET_STRING("BA-IS-SPI/Counter Limited1/Wrap To Zero/Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 246, TARGET_STRING("BA-IS-UART/Counter Limited/Increment Real World/FixPt Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 247, TARGET_STRING("BA-IS-UART/Counter Limited/Wrap To Zero/Constant"),
    TARGET_STRING("Value"), 1, 0, 0 },

  { 248, TARGET_STRING("RS-232/Baseboard Serial F/RS232 ISR/Receive 1/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 249, TARGET_STRING("RS-232/Baseboard Serial F/RS232 ISR/Receive 2/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 250, TARGET_STRING("RS-232/Baseboard Serial F/RS232 ISR/Transmit 1/Constant1"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 251, TARGET_STRING("RS-232/Baseboard Serial F/RS232 ISR/Transmit 2/Constant2"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 252, TARGET_STRING("RS-232/Baseboard Serial F1/RS232 ISR/Receive 1/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 253, TARGET_STRING("RS-232/Baseboard Serial F1/RS232 ISR/Receive 2/Constant"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 254, TARGET_STRING("RS-232/Baseboard Serial F1/RS232 ISR/Transmit 1/Constant1"),
    TARGET_STRING("Value"), 2, 0, 0 },

  { 255, TARGET_STRING("RS-232/Baseboard Serial F1/RS232 ISR/Transmit 2/Constant2"),
    TARGET_STRING("Value"), 2, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &RITM_test_RT1007_B.Twiceasecond,    /* 0: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o1,/* 1: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o2,/* 2: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o3,/* 3: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o4,/* 4: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o5,/* 5: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o6,/* 6: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o7,/* 7: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o8,/* 8: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o9,/* 9: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o10,/* 10: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o11,/* 11: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o12,/* 12: Signal */
  &RITM_test_RT1007_B.BA_IS_gpio_di_o13,/* 13: Signal */
  &RITM_test_RT1007_B.BAISI2C_read_o1[0],/* 14: Signal */
  &RITM_test_RT1007_B.BAISI2C_read_o2, /* 15: Signal */
  &RITM_test_RT1007_B.Constant1,       /* 16: Signal */
  &RITM_test_RT1007_B.Constant2,       /* 17: Signal */
  &RITM_test_RT1007_B.Constant3,       /* 18: Signal */
  &RITM_test_RT1007_B.Constant8,       /* 19: Signal */
  &RITM_test_RT1007_B.BAISCAP_o1,      /* 20: Signal */
  &RITM_test_RT1007_B.BAISCAP_o2,      /* 21: Signal */
  &RITM_test_RT1007_B.BAISCAP1_o1,     /* 22: Signal */
  &RITM_test_RT1007_B.BAISCAP1_o2,     /* 23: Signal */
  &RITM_test_RT1007_B.BAISCAP2_o1,     /* 24: Signal */
  &RITM_test_RT1007_B.BAISCAP2_o2,     /* 25: Signal */
  &RITM_test_RT1007_B.BAISCAP3_o1,     /* 26: Signal */
  &RITM_test_RT1007_B.BAISCAP3_o2,     /* 27: Signal */
  &RITM_test_RT1007_B.Bias1[0],        /* 28: Signal */
  &RITM_test_RT1007_B.BAISSPI1[0],     /* 29: Signal */
  &RITM_test_RT1007_B.ManualSwitch_g[0],/* 30: Signal */
  &RITM_test_RT1007_B.BAISUART_rx_o1[0],/* 31: Signal */
  &RITM_test_RT1007_B.BAISUART_rx_o2,  /* 32: Signal */
  &RITM_test_RT1007_B.BAISUART_rx_o3,  /* 33: Signal */
  &RITM_test_RT1007_B.ManualSwitch[0], /* 34: Signal */
  (void *) &RITM_test_RT1007_ConstB.Width,/* 35: Signal */
  &RITM_test_RT1007_B.CANPack,         /* 36: Signal */
  &RITM_test_RT1007_B.CANUnpack_o1,    /* 37: Signal */
  &RITM_test_RT1007_B.CANUnpack_o2,    /* 38: Signal */
  &RITM_test_RT1007_B.CANUnpack_o3,    /* 39: Signal */
  &RITM_test_RT1007_B.CANUnpack_o4,    /* 40: Signal */
  &RITM_test_RT1007_B.CANUnpack_o5,    /* 41: Signal */
  &RITM_test_RT1007_B.CANUnpack_o6,    /* 42: Signal */
  &RITM_test_RT1007_B.CANUnpack_o7,    /* 43: Signal */
  &RITM_test_RT1007_B.CA_MA_rx_o1,     /* 44: Signal */
  &RITM_test_RT1007_B.CA_MA_rx_o2,     /* 45: Signal */
  &RITM_test_RT1007_B.CA_MA_rx1_o1,    /* 46: Signal */
  &RITM_test_RT1007_B.CA_MA_rx1_o2,    /* 47: Signal */
  &RITM_test_RT1007_B.CA_MA_tx_p,      /* 48: Signal */
  &RITM_test_RT1007_B.SineWave_k,      /* 49: Signal */
  &RITM_test_RT1007_B.ASCIIDecode,     /* 50: Signal */
  &RITM_test_RT1007_B.ASCIIEncode[0],  /* 51: Signal */
  &RITM_test_RT1007_B.FIFOread[0],     /* 52: Signal */
  &RITM_test_RT1007_B.SineWave,        /* 53: Signal */
  &RITM_test_RT1007_B.Output_b,        /* 54: Signal */
  &RITM_test_RT1007_B.Output,          /* 55: Signal */
  &RITM_test_RT1007_B.RxErrorCounter,  /* 56: Signal */
  &RITM_test_RT1007_B.TxErrorCounter,  /* 57: Signal */
  &RITM_test_RT1007_B.CA_MA_status_e[0],/* 58: Signal */
  &RITM_test_RT1007_B.RateTransition,  /* 59: Signal */
  &RITM_test_RT1007_B.RateTransition1_j,/* 60: Signal */
  &RITM_test_RT1007_B.RateTransition2, /* 61: Signal */
  &RITM_test_RT1007_B.RateTransition3_e,/* 62: Signal */
  &RITM_test_RT1007_B.FIFOwrite1_o1_o, /* 63: Signal */
  &RITM_test_RT1007_B.FIFOwrite1_o2_b, /* 64: Signal */
  &RITM_test_RT1007_B.FIFOwrite2_o1_f, /* 65: Signal */
  &RITM_test_RT1007_B.FIFOwrite2_o2_o, /* 66: Signal */
  &RITM_test_RT1007_B.RateTransition_d,/* 67: Signal */
  &RITM_test_RT1007_B.RateTransition1, /* 68: Signal */
  &RITM_test_RT1007_B.RateTransition2_p,/* 69: Signal */
  &RITM_test_RT1007_B.RateTransition3, /* 70: Signal */
  &RITM_test_RT1007_B.FIFOwrite1_o1,   /* 71: Signal */
  &RITM_test_RT1007_B.FIFOwrite1_o2,   /* 72: Signal */
  &RITM_test_RT1007_B.FIFOwrite2_o1,   /* 73: Signal */
  &RITM_test_RT1007_B.FIFOwrite2_o2,   /* 74: Signal */
  &RITM_test_RT1007_B.FixPtSum1_b,     /* 75: Signal */
  &RITM_test_RT1007_B.FixPtSwitch_f,   /* 76: Signal */
  &RITM_test_RT1007_B.FixPtSum1,       /* 77: Signal */
  &RITM_test_RT1007_B.FixPtSwitch,     /* 78: Signal */
  &RITM_test_RT1007_B.ExtractDesiredBits_o,/* 79: Signal */
  &RITM_test_RT1007_B.ModifyScalingOnly,/* 80: Signal */
  &RITM_test_RT1007_B.ExtractDesiredBits,/* 81: Signal */
  &RITM_test_RT1007_B.ModifyScalingOnly_d,/* 82: Signal */
  &RITM_test_RT1007_B.ReadIntStatusFC1_o2_o,/* 83: Signal */
  &RITM_test_RT1007_B.ReadIntStatusFC1_o2,/* 84: Signal */
  &RITM_test_RT1007_B.FIFOwrite1_e,    /* 85: Signal */
  &RITM_test_RT1007_B.ReadHWFIFO1_b[0],/* 86: Signal */
  &RITM_test_RT1007_B.FIFOwrite2_e,    /* 87: Signal */
  &RITM_test_RT1007_B.ReadHWFIFO2_e[0],/* 88: Signal */
  &RITM_test_RT1007_B.FIFOread1_o1_e[0],/* 89: Signal */
  &RITM_test_RT1007_B.FIFOread1_o2_k,  /* 90: Signal */
  &RITM_test_RT1007_B.FIFOread2_o1_h[0],/* 91: Signal */
  &RITM_test_RT1007_B.FIFOread2_o2_g,  /* 92: Signal */
  &RITM_test_RT1007_B.FIFOwrite1,      /* 93: Signal */
  &RITM_test_RT1007_B.ReadHWFIFO1[0],  /* 94: Signal */
  &RITM_test_RT1007_B.FIFOwrite2,      /* 95: Signal */
  &RITM_test_RT1007_B.ReadHWFIFO2[0],  /* 96: Signal */
  &RITM_test_RT1007_B.FIFOread1_o1[0], /* 97: Signal */
  &RITM_test_RT1007_B.FIFOread1_o2,    /* 98: Signal */
  &RITM_test_RT1007_B.FIFOread2_o1[0], /* 99: Signal */
  &RITM_test_RT1007_B.FIFOread2_o2,    /* 100: Signal */
  &RITM_test_RT1007_P.Twiceasecond_Amp,/* 101: Block Parameter */
  &RITM_test_RT1007_P.Twiceasecond_Period,/* 102: Block Parameter */
  &RITM_test_RT1007_P.Twiceasecond_Duty,/* 103: Block Parameter */
  &RITM_test_RT1007_P.Twiceasecond_PhaseDelay,/* 104: Block Parameter */
  &RITM_test_RT1007_P.BA_IS_gpio_di_P1,/* 105: Block Parameter */
  &RITM_test_RT1007_P.BA_IS_gpio_di_P2[0],/* 106: Block Parameter */
  &RITM_test_RT1007_P.BA_IS_gpio_di_P3,/* 107: Block Parameter */
  &RITM_test_RT1007_P.BA_IS_gpio_di_P4,/* 108: Block Parameter */
  &RITM_test_RT1007_P.BA_IS_gpio_do_P1,/* 109: Block Parameter */
  &RITM_test_RT1007_P.BA_IS_gpio_do_P2[0],/* 110: Block Parameter */
  &RITM_test_RT1007_P.BA_IS_gpio_do_P3,/* 111: Block Parameter */
  &RITM_test_RT1007_P.BA_IS_gpio_do_P4,/* 112: Block Parameter */
  &RITM_test_RT1007_P.BAISI2C_read_P1, /* 113: Block Parameter */
  &RITM_test_RT1007_P.BAISI2C_read_P2, /* 114: Block Parameter */
  &RITM_test_RT1007_P.BAISI2C_read_P3, /* 115: Block Parameter */
  &RITM_test_RT1007_P.BAISI2C_read_P4, /* 116: Block Parameter */
  &RITM_test_RT1007_P.BAISI2C_read_P5, /* 117: Block Parameter */
  &RITM_test_RT1007_P.BAISI2C_read_P6, /* 118: Block Parameter */
  &RITM_test_RT1007_P.Constant1_Value, /* 119: Block Parameter */
  &RITM_test_RT1007_P.Constant2_Value, /* 120: Block Parameter */
  &RITM_test_RT1007_P.Constant3_Value, /* 121: Block Parameter */
  &RITM_test_RT1007_P.Constant8_Value, /* 122: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP_P1,      /* 123: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP_P2,      /* 124: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP_P3,      /* 125: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP1_P1,     /* 126: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP1_P2,     /* 127: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP1_P3,     /* 128: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP2_P1,     /* 129: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP2_P2,     /* 130: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP2_P3,     /* 131: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP3_P1,     /* 132: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP3_P2,     /* 133: Block Parameter */
  &RITM_test_RT1007_P.BAISCAP3_P3,     /* 134: Block Parameter */
  &RITM_test_RT1007_P.BAISPWM_P1,      /* 135: Block Parameter */
  &RITM_test_RT1007_P.BAISPWM_P2,      /* 136: Block Parameter */
  &RITM_test_RT1007_P.BAISPWM_P3,      /* 137: Block Parameter */
  &RITM_test_RT1007_P.BAISPWM1_P1,     /* 138: Block Parameter */
  &RITM_test_RT1007_P.BAISPWM1_P2,     /* 139: Block Parameter */
  &RITM_test_RT1007_P.BAISPWM1_P3,     /* 140: Block Parameter */
  &RITM_test_RT1007_P.CounterLimited1_uplimit,/* 141: Mask Parameter */
  &RITM_test_RT1007_P.Bias1_Bias[0],   /* 142: Block Parameter */
  &RITM_test_RT1007_P.Generatesomedata_Value[0],/* 143: Block Parameter */
  &RITM_test_RT1007_P.BAISSPI1_P1,     /* 144: Block Parameter */
  &RITM_test_RT1007_P.BAISSPI1_P2,     /* 145: Block Parameter */
  &RITM_test_RT1007_P.BAISSPI1_P3,     /* 146: Block Parameter */
  &RITM_test_RT1007_P.BAISSPI1_P4,     /* 147: Block Parameter */
  &RITM_test_RT1007_P.BAISSPI1_P5,     /* 148: Block Parameter */
  &RITM_test_RT1007_P.BAISSPI1_P6,     /* 149: Block Parameter */
  &RITM_test_RT1007_P.BAISSPI1_P7,     /* 150: Block Parameter */
  &RITM_test_RT1007_P.BAISSPI1_P8,     /* 151: Block Parameter */
  &RITM_test_RT1007_P.ManualSwitch_CurrentSetting,/* 152: Block Parameter */
  &RITM_test_RT1007_P.CounterLimited_uplimit,/* 153: Mask Parameter */
  &RITM_test_RT1007_P.Generatesomedata_Value_l[0],/* 154: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_rx_P1,  /* 155: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_rx_P2,  /* 156: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_rx_P3,  /* 157: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_rx_P4,  /* 158: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_setup_P1,/* 159: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_setup_P2,/* 160: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_setup_P3,/* 161: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_setup_P4,/* 162: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_setup_P5,/* 163: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_setup_P6,/* 164: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_tx_P1,  /* 165: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_tx_P2,  /* 166: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_tx_P3,  /* 167: Block Parameter */
  &RITM_test_RT1007_P.BAISUART_tx_P4,  /* 168: Block Parameter */
  &RITM_test_RT1007_P.ManualSwitch_CurrentSetting_m,/* 169: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_rx_P1,     /* 170: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_rx_P2,     /* 171: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_rx_P3,     /* 172: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_rx1_P1,    /* 173: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_rx1_P2,    /* 174: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_rx1_P3,    /* 175: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_setup_P1,  /* 176: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_setup_P2,  /* 177: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_setup_P3,  /* 178: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_setup_P4[0],/* 179: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_setup_P5[0],/* 180: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_setup_P6,  /* 181: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_setup_P7,  /* 182: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_tx_P1,     /* 183: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_tx_P2,     /* 184: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_tx_P3,     /* 185: Block Parameter */
  &RITM_test_RT1007_P.SineWave_Amp,    /* 186: Block Parameter */
  &RITM_test_RT1007_P.SineWave_Bias,   /* 187: Block Parameter */
  &RITM_test_RT1007_P.SineWave_Freq,   /* 188: Block Parameter */
  &RITM_test_RT1007_P.SineWave_Hsin,   /* 189: Block Parameter */
  &RITM_test_RT1007_P.SineWave_HCos,   /* 190: Block Parameter */
  &RITM_test_RT1007_P.SineWave_PSin,   /* 191: Block Parameter */
  &RITM_test_RT1007_P.SineWave_PCos,   /* 192: Block Parameter */
  &RITM_test_RT1007_P.ASCIIDecode_P1[0],/* 193: Block Parameter */
  &RITM_test_RT1007_P.ASCIIDecode_P2,  /* 194: Block Parameter */
  &RITM_test_RT1007_P.ASCIIDecode_P3,  /* 195: Block Parameter */
  &RITM_test_RT1007_P.ASCIIEncode_P1[0],/* 196: Block Parameter */
  &RITM_test_RT1007_P.ASCIIEncode_P2,  /* 197: Block Parameter */
  &RITM_test_RT1007_P.ASCIIEncode_P3,  /* 198: Block Parameter */
  &RITM_test_RT1007_P.ASCIIEncode_P4,  /* 199: Block Parameter */
  &RITM_test_RT1007_P.SineWave_Amp_o,  /* 200: Block Parameter */
  &RITM_test_RT1007_P.SineWave_Bias_n, /* 201: Block Parameter */
  &RITM_test_RT1007_P.SineWave_Freq_p, /* 202: Block Parameter */
  &RITM_test_RT1007_P.SineWave_Hsin_j, /* 203: Block Parameter */
  &RITM_test_RT1007_P.SineWave_HCos_f, /* 204: Block Parameter */
  &RITM_test_RT1007_P.SineWave_PSin_p, /* 205: Block Parameter */
  &RITM_test_RT1007_P.SineWave_PCos_d, /* 206: Block Parameter */
  &RITM_test_RT1007_P.Output_InitialCondition,/* 207: Block Parameter */
  &RITM_test_RT1007_P.Output_InitialCondition_b,/* 208: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_status_P1, /* 209: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_status_P2, /* 210: Block Parameter */
  &RITM_test_RT1007_P.CA_MA_status_P3, /* 211: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P1_c,     /* 212: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P2_n,     /* 213: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P3_j,     /* 214: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P4_o,     /* 215: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P5_h,     /* 216: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P6_i,     /* 217: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P7_l,     /* 218: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P8_i,     /* 219: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P1_p,     /* 220: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P2_l,     /* 221: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P3_d,     /* 222: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P4_c,     /* 223: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P5_o,     /* 224: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P6_n,     /* 225: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P7_i,     /* 226: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P8_j,     /* 227: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P1,       /* 228: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P2,       /* 229: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P3,       /* 230: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P4,       /* 231: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P5,       /* 232: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P6,       /* 233: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P7,       /* 234: Block Parameter */
  &RITM_test_RT1007_P.Setup1_P8,       /* 235: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P1,       /* 236: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P2,       /* 237: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P3,       /* 238: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P4,       /* 239: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P5,       /* 240: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P6,       /* 241: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P7,       /* 242: Block Parameter */
  &RITM_test_RT1007_P.Setup2_P8,       /* 243: Block Parameter */
  &RITM_test_RT1007_P.FixPtConstant_Value,/* 244: Block Parameter */
  &RITM_test_RT1007_P.Constant_Value_i,/* 245: Block Parameter */
  &RITM_test_RT1007_P.FixPtConstant_Value_k,/* 246: Block Parameter */
  &RITM_test_RT1007_P.Constant_Value_h,/* 247: Block Parameter */
  &RITM_test_RT1007_P.Constant_Value,  /* 248: Block Parameter */
  &RITM_test_RT1007_P.Constant_Value_a,/* 249: Block Parameter */
  &RITM_test_RT1007_P.Constant1_Value_h,/* 250: Block Parameter */
  &RITM_test_RT1007_P.Constant2_Value_d,/* 251: Block Parameter */
  &RITM_test_RT1007_P.Constant_Value_c,/* 252: Block Parameter */
  &RITM_test_RT1007_P.Constant_Value_m,/* 253: Block Parameter */
  &RITM_test_RT1007_P.Constant1_Value_he,/* 254: Block Parameter */
  &RITM_test_RT1007_P.Constant2_Value_p,/* 255: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0, 0 },

  { "numeric", "CAN_DATATYPE", 0, 0, sizeof(CAN_DATATYPE), SS_STRUCT, 0, 0, 0 },

  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0, 0 },

  { "numeric", "serialfifoptr", 0, 0, sizeof(serialfifoptr), SS_STRUCT, 0, 0, 0
  },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_VECTOR, 16, 2, 0 },

  { rtwCAPI_VECTOR, 18, 2, 0 },

  { rtwCAPI_VECTOR, 20, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  4,                                   /* 2 */
  1,                                   /* 3 */
  16,                                  /* 4 */
  1,                                   /* 5 */
  128,                                 /* 6 */
  1,                                   /* 7 */
  1025,                                /* 8 */
  1,                                   /* 9 */
  5,                                   /* 10 */
  1,                                   /* 11 */
  65,                                  /* 12 */
  1,                                   /* 13 */
  61,                                  /* 14 */
  1,                                   /* 15 */
  1,                                   /* 16 */
  13,                                  /* 17 */
  1,                                   /* 18 */
  4,                                   /* 19 */
  1,                                   /* 20 */
  3                                    /* 21 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0, 0.1, 0.01, -1.0, -2.0, -3.0, 1.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },

  { (const void *) &rtcapiStoredFloats[7], (const void *) &rtcapiStoredFloats[1],
    rtwCAPI_FIX_UNIFORM_SCALING, 1, 0, 0 },

  { (const void *) &rtcapiStoredFloats[7], (const void *) &rtcapiStoredFloats[1],
    rtwCAPI_FIX_UNIFORM_SCALING, 1, 7, 0 }
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    2, 0 },

  { (NULL), (NULL), -2, 0 },

  { (const void *) &rtcapiStoredFloats[3], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[4], (const void *) &rtcapiStoredFloats[5],
    3, 0 },

  { (const void *) &rtcapiStoredFloats[4], (const void *) &rtcapiStoredFloats[6],
    4, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 101,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 155,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1229701883U,
    492905286U,
    3327049207U,
    2871608858U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  RITM_test_RT1007_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void RITM_test_RT1007_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(RITM_test_RT1007_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(RITM_test_RT1007_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(RITM_test_RT1007_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(RITM_test_RT1007_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(RITM_test_RT1007_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  RITM_test_RT1007_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(RITM_test_RT1007_M);
  RITM_test_RT1007_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_RITM_test_RT1007_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(RITM_test_RT1007_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(RITM_test_RT1007_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(RITM_test_RT1007_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void RITM_test_RT1007_host_InitializeDataMapInfo
    (RITM_test_RT1007_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: RITM_test_RT1007_capi.c */
