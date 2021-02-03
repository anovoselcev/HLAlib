/*
 * Ethernet_private.h
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

#ifndef RTW_HEADER_Ethernet_private_h_
#define RTW_HEADER_Ethernet_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern void slrtIPConfig(SimStruct *rts);
extern void slrtUDPSend(SimStruct *rts);

#endif                                 /* RTW_HEADER_Ethernet_private_h_ */
