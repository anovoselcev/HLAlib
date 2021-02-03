/*
 * RITM_test_RT1007_private.h
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

#ifndef RTW_HEADER_RITM_test_RT1007_private_h_
#define RTW_HEADER_RITM_test_RT1007_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "RITM_test_RT1007.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Define interrupt functions for board 1 */
xpcPCIDevice xpcDev_1;

/* Done with interrupt functions for board 1 */

/* Define interrupt functions for board 2 */
xpcPCIDevice xpcDev_2;

/* Done with interrupt functions for board 2 */
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern const char *fifowrite(int32_T *fifo, void *iPtr, void **oPtrs,
  int *settings);
extern void fiforead(const void *iPorts[], void *oPorts[], int *settings);
extern void BA_IS_gpio_di(SimStruct *rts);
extern void BA_IS_gpio_do(SimStruct *rts);
extern void BA_IS_i2c_read(SimStruct *rts);
extern void BA_IS_cap(SimStruct *rts);
extern void BA_IS_pwm(SimStruct *rts);
extern void BA_IS_spi(SimStruct *rts);
extern void BA_IS_uart_setup(SimStruct *rts);
extern void BA_IS_uart_rx(SimStruct *rts);
extern void BA_IS_uart_tx(SimStruct *rts);
extern void CA_MA_rx(SimStruct *rts);
extern void CA_MA_status(SimStruct *rts);
extern void CA_MA_tx(SimStruct *rts);
extern void CA_MA_setup(SimStruct *rts);
extern void asciidecode(SimStruct *rts);
extern void sersetupbase(SimStruct *rts);
extern void asciiencode(SimStruct *rts);
extern void RITM_test_RT_RS232ISR_Start(void);
extern void RITM_test_RT1007_RS232ISR(void);
extern void RITM_test__RS232ISR_k_Start(void);
extern void RITM_test_RT1007_RS232ISR_j(void);
extern void RITM_test_RT1_RS232ISR_Term(void);
extern void RITM_test_R_RS232ISR_j_Term(void);

#endif                              /* RTW_HEADER_RITM_test_RT1007_private_h_ */
