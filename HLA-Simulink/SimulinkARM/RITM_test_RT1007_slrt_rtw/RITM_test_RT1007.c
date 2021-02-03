/*
 * RITM_test_RT1007.c
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

#include "rt_logging_mmi.h"
#include "RITM_test_RT1007_capi.h"
#include "RITM_test_RT1007.h"
#include "RITM_test_RT1007_private.h"

const uint8_T RITM_test_RT1007_U8GND = 0U;/* uint8_T ground */

/* Block signals (default storage) */
B_RITM_test_RT1007_T RITM_test_RT1007_B;

/* Block states (default storage) */
DW_RITM_test_RT1007_T RITM_test_RT1007_DW;

/* Real-time model */
RT_MODEL_RITM_test_RT1007_T RITM_test_RT1007_M_;
RT_MODEL_RITM_test_RT1007_T *const RITM_test_RT1007_M = &RITM_test_RT1007_M_;

/* xPC Target Async Interrupt Block '<S23>/IRQ Source' */
void xPCISR2(void)
{
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.Receive1_SubsysRanBC_c);

    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.Transmit1_SubsysRanBC_o);

    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.Receive2_SubsysRanBC_l);

    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.Transmit2_SubsysRanBC_f);

    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.RS232ISR_SubsysRanBC_l);

    /* Outputs for Atomic SubSystem: '<Root>/RS-232' */
    /* RateTransition: '<S23>/Rate Transition' */
    RITM_test_RT1007_B.RateTransition = RITM_test_RT1007_B.FIFOwrite1_o1_o;

    /* RateTransition: '<S23>/Rate Transition2' */
    RITM_test_RT1007_B.RateTransition2 = RITM_test_RT1007_B.FIFOwrite2_o1_f;

    /* S-Function (xpcinterrupt): '<S23>/IRQ Source' */
    RITM_test_RT1007_RS232ISR();

    /* End of Outputs for S-Function (xpcinterrupt): '<S23>/IRQ Source' */
    /* End of Outputs for SubSystem: '<Root>/RS-232' */
  }

  xpceDAQUpdateTimeStamp(3, (((RITM_test_RT1007_M->Timing.clockTick3+
    RITM_test_RT1007_M->Timing.clockTickH3* 4294967296.0)) * 0.001));
  xpceDAQPostEvent(3);
}

/* xPC Target Async Interrupt Block '<S24>/IRQ Source' */
void xPCISR1(void)
{
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.Receive1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.Transmit1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.Receive2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.Transmit2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(RITM_test_RT1007_DW.RS232ISR_SubsysRanBC);

    /* Outputs for Atomic SubSystem: '<Root>/RS-232' */
    /* RateTransition: '<S24>/Rate Transition' */
    RITM_test_RT1007_B.RateTransition_d = RITM_test_RT1007_B.FIFOwrite1_o1;

    /* RateTransition: '<S24>/Rate Transition2' */
    RITM_test_RT1007_B.RateTransition2_p = RITM_test_RT1007_B.FIFOwrite2_o1;

    /* S-Function (xpcinterrupt): '<S24>/IRQ Source' */
    RITM_test_RT1007_RS232ISR_j();

    /* End of Outputs for S-Function (xpcinterrupt): '<S24>/IRQ Source' */
    /* End of Outputs for SubSystem: '<Root>/RS-232' */
  }

  xpceDAQUpdateTimeStamp(4, (((RITM_test_RT1007_M->Timing.clockTick4+
    RITM_test_RT1007_M->Timing.clockTickH4* 4294967296.0)) * 0.001));
  xpceDAQPostEvent(4);
}

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(RITM_test_RT1007_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(RITM_test_RT1007_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called in the model base rate function.
 * It maintains SampleHit information to allow scheduling
 * of the subrates from the base rate function.
 */
void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (RITM_test_RT1007_M->Timing.TaskCounters.TID[1])++;
  if ((RITM_test_RT1007_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    RITM_test_RT1007_M->Timing.TaskCounters.TID[1] = 0;
  }

  (RITM_test_RT1007_M->Timing.TaskCounters.TID[2])++;
  if ((RITM_test_RT1007_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    RITM_test_RT1007_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Start for function-call system: '<S23>/RS232 ISR' */
void RITM_test_RT_RS232ISR_Start(void)
{
  /* Start for S-Function (iquerybase): '<S26>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S26>/Receive 1'
   */
  /* Start for function-call system: '<S26>/Receive 1' */

  /* Start for S-Function (serreadbase): '<S27>/Read HW FIFO1' incorporates:
   *  Constant: '<S27>/Constant'
   */

  /* S-Function Block: <S27>/Read HW FIFO1 (serreadbase) */
  {
    int count = 0;

    // Flush the hardware fifo on startup.
    while (xpcInpB( (unsigned short)(1016 + slrtLSR) ) & LSRDR ) {
      // Read and discard the data.
      xpcInpB( (unsigned short)(1016 + slrtDATA) );
      if (count++ > 1000 ) {
        static char msg[50];
        sprintf( msg, "A UART at address 0x%x is not responding", 1016 );

        // No baseboard UART has that large a hardware fifo!
        rtmSetErrorStatus(RITM_test_RT1007_M, msg);
        return;
      }
    }
  }

  /* Start for S-Function (fifowrite): '<S27>/FIFO write 1' */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK_n[0] = 1024;/* fifo size */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK_n[1] = 2;/* fifo type */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK_n[2] = 65;/* inport width */

  /* allocate memory for FIFO */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[0] = malloc(4 * (1024 + 3));
  if (RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[0] == NULL) {
    rtmSetErrorStatus(RITM_test_RT1007_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[1] = &RITM_test_RT1007_B.ReadHWFIFO1_b
    [0];

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[2] = &RITM_test_RT1007_B.FIFOwrite1_e;
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[3] = NULL;

  {
    /* Initialize the fifo */
    int *fifo = RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &RITM_test_RT1007_B.FIFOwrite1_e;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (iquerybase): '<S26>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S26>/Transmit 1'
   */
  /* Start for function-call system: '<S26>/Transmit 1' */

  /* Start for S-Function (fiforead): '<S29>/FIFO read 1' incorporates:
   *  Constant: '<S29>/Constant1'
   */
  RITM_test_RT1007_DW.FIFOread1_IWORK_a[0] = 60;/* Max to read */
  RITM_test_RT1007_DW.FIFOread1_IWORK_a[1] = 1;/* Min to read */
  RITM_test_RT1007_DW.FIFOread1_IWORK_a[2] = 0;/* Use delimiter? */
  RITM_test_RT1007_DW.FIFOread1_IWORK_a[3] = 13;/* delimiter */
  RITM_test_RT1007_DW.FIFOread1_IWORK_a[4] = 2;/* FIFO type */

  /* Input pointer(s) */
  RITM_test_RT1007_DW.FIFOread1_PWORK_g[0] = &RITM_test_RT1007_B.RateTransition;
  RITM_test_RT1007_DW.FIFOread1_PWORK_g[1] =
    &RITM_test_RT1007_B.ReadIntStatusFC1_o2_o;
  RITM_test_RT1007_DW.FIFOread1_PWORK_g[2] =
    &RITM_test_RT1007_P.Constant1_Value_h;

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOread1_PWORK_g[3] = &RITM_test_RT1007_B.FIFOread1_o1_e
    [0];
  RITM_test_RT1007_DW.FIFOread1_PWORK_g[4] = &RITM_test_RT1007_B.FIFOread1_o2_k;

  /* Start for S-Function (iquerybase): '<S26>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S26>/Receive 2'
   */
  /* Start for function-call system: '<S26>/Receive 2' */

  /* Start for S-Function (fifowrite): '<S28>/FIFO write 2' */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK_a[0] = 1024;/* fifo size */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK_a[1] = 2;/* fifo type */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK_a[2] = 65;/* inport width */

  /* allocate memory for FIFO */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_k[0] = malloc(4 * (1024 + 3));
  if (RITM_test_RT1007_DW.FIFOwrite2_PWORK_k[0] == NULL) {
    rtmSetErrorStatus(RITM_test_RT1007_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_k[1] = &RITM_test_RT1007_B.ReadHWFIFO2_e
    [0];

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_k[2] = &RITM_test_RT1007_B.FIFOwrite2_e;
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_k[3] = NULL;

  {
    /* Initialize the fifo */
    int *fifo = RITM_test_RT1007_DW.FIFOwrite2_PWORK_k[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &RITM_test_RT1007_B.FIFOwrite2_e;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (iquerybase): '<S26>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S26>/Transmit 2'
   */

  /* Start for function-call system: '<S26>/Transmit 2' */

  /* Start for S-Function (fiforead): '<S30>/FIFO read 2' incorporates:
   *  Constant: '<S30>/Constant2'
   */
  RITM_test_RT1007_DW.FIFOread2_IWORK_o[0] = 60;/* Max to read */
  RITM_test_RT1007_DW.FIFOread2_IWORK_o[1] = 1;/* Min to read */
  RITM_test_RT1007_DW.FIFOread2_IWORK_o[2] = 0;/* Use delimiter? */
  RITM_test_RT1007_DW.FIFOread2_IWORK_o[3] = 13;/* delimiter */
  RITM_test_RT1007_DW.FIFOread2_IWORK_o[4] = 2;/* FIFO type */

  /* Input pointer(s) */
  RITM_test_RT1007_DW.FIFOread2_PWORK_g[0] = &RITM_test_RT1007_B.RateTransition2;
  RITM_test_RT1007_DW.FIFOread2_PWORK_g[1] =
    &RITM_test_RT1007_B.ReadIntStatusFC1_o2_o;
  RITM_test_RT1007_DW.FIFOread2_PWORK_g[2] =
    &RITM_test_RT1007_P.Constant2_Value_d;

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOread2_PWORK_g[3] = &RITM_test_RT1007_B.FIFOread2_o1_h
    [0];
  RITM_test_RT1007_DW.FIFOread2_PWORK_g[4] = &RITM_test_RT1007_B.FIFOread2_o2_g;

  /* End of Start for S-Function (iquerybase): '<S26>/Read Int Status FC1' */
}

/* Output and update for function-call system: '<S23>/RS232 ISR' */
void RITM_test_RT1007_RS232ISR(void)
{
  rtw_xpc_mutex_take(RITM_test_RT1007_M->Timing.semIdForTask3);
  RITM_test_RT1007_M->Timing.clockTick3 =
    RITM_test_RT1007_M->Timing.rtmClockTickBuf3;
  RITM_test_RT1007_M->Timing.clockTickH3 =
    RITM_test_RT1007_M->Timing.rtmBufClockTickBufH3;
  rtw_xpc_mutex_give(RITM_test_RT1007_M->Timing.semIdForTask3);

  /* S-Function (iquerybase): '<S26>/Read Int Status FC1' */
  {
    /* S-Function Block: <S26>/Read Int Status FC1 (iquerybase) */
    int base[2] = { (int)1016, (int)0 };

    uint32_T port, max;
    volatile int iir;                  // local interrupt register, per uart
    for (port = 0 ; port < 2 ; port++ ) {
      if (base[port] == 0 ) {
        continue;
      }

      iir = xpcInpB( (unsigned short)(base[port] + slrtIIR) ) & 0xff;

      //printf("lint = 0x%x\n", iir );
      if ((iir & (IIRFEBL | IIR64) ) == (IIRFEBL | IIR64) )
        max = 60;
      else if ((iir & (IIRFEBL | IIR64) ) == IIRFEBL )
        max = 15;
      else
        max = 1;
      *(&RITM_test_RT1007_B.ReadIntStatusFC1_o2_o) = max;
      iir &= IIRREASON;
      while (iir != 1 )                // Service all reasons
      {
        switch ( iir )
        {
         case 1:                       // No interrupt on this UART
          break;

         case 4:                       // received data available
         case 6:                       // receiver line status, overrun etc.
         case 0xc:                     // character timeout
          //printf("%1xa", base[i]>>8);
          // All three are receive interrupts
          switch (port)
          {
           case 0:
            /* Output and update for function-call system: '<S26>/Receive 1' */

            /* S-Function (serreadbase): '<S27>/Read HW FIFO1' incorporates:
             *  Constant: '<S27>/Constant'
             */
            {
              /* S-Function Block: <S27>/Read HW FIFO1 (serreadbase) */
              int status = 0;
              int count = 0;

              // While there is data in the fifo, read it, also read error status.
              // Cap the read length to the interrupt point in 64 byte fifo mode.
              while (((status = xpcInpB( (unsigned short)(1016 + slrtLSR) ) &
                       0xff ) & LSRDR) && (count < 56) ) {
                int c;
                int masked;
                count++;
                c = xpcInpB( (unsigned short)(1016 + slrtDATA) ) & 0xff;// read character
                masked = status & (LSROE | LSRPE | LSRFE | LSRBI);
                ((int_T *)&RITM_test_RT1007_B.ReadHWFIFO1_b[0])[count] = (masked
                  << 8) | c;
              }

              ((int_T *)&RITM_test_RT1007_B.ReadHWFIFO1_b[0])[0] = count;
            }

            /* S-Function (fifowrite): '<S27>/FIFO write 1' */
            {
              const char *err;
              static char msg[100];
              err = fifowrite(RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[0],
                              RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[1],
                              &RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[2],
                              &RITM_test_RT1007_DW.FIFOwrite1_IWORK_n[0]);
              if (err) {
                if (strncmp("FIFO", err, 4)) {
                  rtmSetErrorStatus(RITM_test_RT1007_M, err);
                } else {
                  int n = strlen(err);
                  strcpy(msg, err);
                  strncpy(msg + n, "RCV channel 1, IRQ 4", 99 - n);
                  rtmSetErrorStatus(RITM_test_RT1007_M, msg);
                }
              }
            }

            RITM_test_RT1007_DW.Receive1_SubsysRanBC_c = 4;
            break;
          }
          break;

         case 2:                       // Transmitter holding register empty
          //printf("%1xb", base[i]>>8);
          switch (port)
          {
           case 0:
            /* Output and update for function-call system: '<S26>/Transmit 1' */

            /* S-Function (fiforead): '<S29>/FIFO read 1' incorporates:
             *  Constant: '<S29>/Constant1'
             */
            {
              void **iPtrs = &RITM_test_RT1007_DW.FIFOread1_PWORK_g[0];
              void **oPtrs = &RITM_test_RT1007_DW.FIFOread1_PWORK_g[3];
              fiforead(iPtrs, oPtrs, &RITM_test_RT1007_DW.FIFOread1_IWORK_a[0]);
            }

            /* S-Function (serwritebase): '<S29>/Write HW FIFO1' */
            {
              /* S-Function Block: <S29>/Write HW FIFO1 (serwritebase) */
              int_T *IPtr = (int_T *)&RITM_test_RT1007_B.FIFOread1_o1_e[0];
              if (RITM_test_RT1007_B.FIFOread1_o2_k > 0 ) {
                // On entry, verify that the transmitter holding register is empty
                // so we can stuff all that came from the software fifo into the
                // hardware fifo.  Assume that the software fifo has a max read
                // parameter that fits with the hardware fifo mode setting.
                if (IPtr[0] == 0 ) {
                  // No data, turn off the transmitter empty interrupt and leave
                  TBTakeSpinFast( slrtSerialLock );
                  int ier = xpcInpB( (unsigned short)(1016 + slrtIER) ) & 0xff;
                  xpcOutpB( (unsigned short)(1016 + slrtIER), (uint8_T)(ier &
                            ~IERXMT) );
                  TBGiveSpinFast( slrtSerialLock );
                } else if (xpcInpB( (unsigned short)(1016 + slrtLSR) ) & LSRTHRE
                           ) {
                  int i;

                  // Copy all the data from the input vector to the HW fifo.
                  // The fifo read block MUST have the correct max read value
                  // for the fifo mode.
                  for (i = 0 ; i < IPtr[0] ; i++ ) {
                    xpcOutpB( (ushort_T)(1016 + slrtDATA), (uint8_T)(IPtr[i+1] &
                              0xff) );
                  }
                } else {
                  rtmSetErrorStatus(RITM_test_RT1007_M,
                                    "Attempted write to hardware fifo that isn't empty");
                  return;
                }
              }
            }

            RITM_test_RT1007_DW.Transmit1_SubsysRanBC_o = 4;
            break;
          }
          break;

         case 0:
          // Modem status change
          break;
        }

        // Read IIR again to see if we're done with this UART
        iir = xpcInpB( (unsigned short)(base[port] + slrtIIR) ) & IIRREASON;
      }
    }
  }

  /* End of Outputs for S-Function (iquerybase): '<S26>/Read Int Status FC1' */
  RITM_test_RT1007_DW.RS232ISR_SubsysRanBC_l = 4;
}

/* Termination for function-call system: '<S23>/RS232 ISR' */
void RITM_test_RT1_RS232ISR_Term(void)
{
  /* Terminate for S-Function (iquerybase): '<S26>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S26>/Receive 1'
   */
  /* Termination for function-call system: '<S26>/Receive 1' */

  /* Terminate for S-Function (fifowrite): '<S27>/FIFO write 1' */

  /* Free fifo memory */
  if (RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[0]) {
    free(RITM_test_RT1007_DW.FIFOwrite1_PWORK_j[0]);
  }

  /* Terminate for S-Function (iquerybase): '<S26>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S26>/Receive 2'
   */

  /* Termination for function-call system: '<S26>/Receive 2' */

  /* Terminate for S-Function (fifowrite): '<S28>/FIFO write 2' */

  /* Free fifo memory */
  if (RITM_test_RT1007_DW.FIFOwrite2_PWORK_k[0]) {
    free(RITM_test_RT1007_DW.FIFOwrite2_PWORK_k[0]);
  }

  /* End of Terminate for S-Function (iquerybase): '<S26>/Read Int Status FC1' */
}

/* Start for function-call system: '<S24>/RS232 ISR' */
void RITM_test__RS232ISR_k_Start(void)
{
  /* Start for S-Function (iquerybase): '<S31>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S31>/Receive 1'
   */
  /* Start for function-call system: '<S31>/Receive 1' */

  /* Start for S-Function (serreadbase): '<S32>/Read HW FIFO1' incorporates:
   *  Constant: '<S32>/Constant'
   */

  /* S-Function Block: <S32>/Read HW FIFO1 (serreadbase) */
  {
    int count = 0;

    // Flush the hardware fifo on startup.
    while (xpcInpB( (unsigned short)(760 + slrtLSR) ) & LSRDR ) {
      // Read and discard the data.
      xpcInpB( (unsigned short)(760 + slrtDATA) );
      if (count++ > 1000 ) {
        static char msg[50];
        sprintf( msg, "A UART at address 0x%x is not responding", 760 );

        // No baseboard UART has that large a hardware fifo!
        rtmSetErrorStatus(RITM_test_RT1007_M, msg);
        return;
      }
    }
  }

  /* Start for S-Function (fifowrite): '<S32>/FIFO write 1' */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK_o[0] = 1024;/* fifo size */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK_o[1] = 2;/* fifo type */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK_o[2] = 65;/* inport width */

  /* allocate memory for FIFO */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[0] = malloc(4 * (1024 + 3));
  if (RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[0] == NULL) {
    rtmSetErrorStatus(RITM_test_RT1007_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[1] = &RITM_test_RT1007_B.ReadHWFIFO1[0];

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[2] = &RITM_test_RT1007_B.FIFOwrite1;
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[3] = NULL;

  {
    /* Initialize the fifo */
    int *fifo = RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &RITM_test_RT1007_B.FIFOwrite1;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (iquerybase): '<S31>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S31>/Transmit 1'
   */
  /* Start for function-call system: '<S31>/Transmit 1' */

  /* Start for S-Function (fiforead): '<S34>/FIFO read 1' incorporates:
   *  Constant: '<S34>/Constant1'
   */
  RITM_test_RT1007_DW.FIFOread1_IWORK[0] = 60;/* Max to read */
  RITM_test_RT1007_DW.FIFOread1_IWORK[1] = 1;/* Min to read */
  RITM_test_RT1007_DW.FIFOread1_IWORK[2] = 0;/* Use delimiter? */
  RITM_test_RT1007_DW.FIFOread1_IWORK[3] = 13;/* delimiter */
  RITM_test_RT1007_DW.FIFOread1_IWORK[4] = 2;/* FIFO type */

  /* Input pointer(s) */
  RITM_test_RT1007_DW.FIFOread1_PWORK[0] = &RITM_test_RT1007_B.RateTransition_d;
  RITM_test_RT1007_DW.FIFOread1_PWORK[1] =
    &RITM_test_RT1007_B.ReadIntStatusFC1_o2;
  RITM_test_RT1007_DW.FIFOread1_PWORK[2] =
    &RITM_test_RT1007_P.Constant1_Value_he;

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOread1_PWORK[3] = &RITM_test_RT1007_B.FIFOread1_o1[0];
  RITM_test_RT1007_DW.FIFOread1_PWORK[4] = &RITM_test_RT1007_B.FIFOread1_o2;

  /* Start for S-Function (iquerybase): '<S31>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S31>/Receive 2'
   */
  /* Start for function-call system: '<S31>/Receive 2' */

  /* Start for S-Function (fifowrite): '<S33>/FIFO write 2' */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK_d[0] = 1024;/* fifo size */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK_d[1] = 2;/* fifo type */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK_d[2] = 65;/* inport width */

  /* allocate memory for FIFO */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_a[0] = malloc(4 * (1024 + 3));
  if (RITM_test_RT1007_DW.FIFOwrite2_PWORK_a[0] == NULL) {
    rtmSetErrorStatus(RITM_test_RT1007_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_a[1] = &RITM_test_RT1007_B.ReadHWFIFO2[0];

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_a[2] = &RITM_test_RT1007_B.FIFOwrite2;
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_a[3] = NULL;

  {
    /* Initialize the fifo */
    int *fifo = RITM_test_RT1007_DW.FIFOwrite2_PWORK_a[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &RITM_test_RT1007_B.FIFOwrite2;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (iquerybase): '<S31>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S31>/Transmit 2'
   */

  /* Start for function-call system: '<S31>/Transmit 2' */

  /* Start for S-Function (fiforead): '<S35>/FIFO read 2' incorporates:
   *  Constant: '<S35>/Constant2'
   */
  RITM_test_RT1007_DW.FIFOread2_IWORK[0] = 60;/* Max to read */
  RITM_test_RT1007_DW.FIFOread2_IWORK[1] = 1;/* Min to read */
  RITM_test_RT1007_DW.FIFOread2_IWORK[2] = 0;/* Use delimiter? */
  RITM_test_RT1007_DW.FIFOread2_IWORK[3] = 13;/* delimiter */
  RITM_test_RT1007_DW.FIFOread2_IWORK[4] = 2;/* FIFO type */

  /* Input pointer(s) */
  RITM_test_RT1007_DW.FIFOread2_PWORK[0] = &RITM_test_RT1007_B.RateTransition2_p;
  RITM_test_RT1007_DW.FIFOread2_PWORK[1] =
    &RITM_test_RT1007_B.ReadIntStatusFC1_o2;
  RITM_test_RT1007_DW.FIFOread2_PWORK[2] = &RITM_test_RT1007_P.Constant2_Value_p;

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOread2_PWORK[3] = &RITM_test_RT1007_B.FIFOread2_o1[0];
  RITM_test_RT1007_DW.FIFOread2_PWORK[4] = &RITM_test_RT1007_B.FIFOread2_o2;

  /* End of Start for S-Function (iquerybase): '<S31>/Read Int Status FC1' */
}

/* Output and update for function-call system: '<S24>/RS232 ISR' */
void RITM_test_RT1007_RS232ISR_j(void)
{
  rtw_xpc_mutex_take(RITM_test_RT1007_M->Timing.semIdForTask4);
  RITM_test_RT1007_M->Timing.clockTick4 =
    RITM_test_RT1007_M->Timing.rtmClockTickBuf4;
  RITM_test_RT1007_M->Timing.clockTickH4 =
    RITM_test_RT1007_M->Timing.rtmBufClockTickBufH4;
  rtw_xpc_mutex_give(RITM_test_RT1007_M->Timing.semIdForTask4);

  /* S-Function (iquerybase): '<S31>/Read Int Status FC1' */
  {
    /* S-Function Block: <S31>/Read Int Status FC1 (iquerybase) */
    int base[2] = { (int)760, (int)0 };

    uint32_T port, max;
    volatile int iir;                  // local interrupt register, per uart
    for (port = 0 ; port < 2 ; port++ ) {
      if (base[port] == 0 ) {
        continue;
      }

      iir = xpcInpB( (unsigned short)(base[port] + slrtIIR) ) & 0xff;

      //printf("lint = 0x%x\n", iir );
      if ((iir & (IIRFEBL | IIR64) ) == (IIRFEBL | IIR64) )
        max = 60;
      else if ((iir & (IIRFEBL | IIR64) ) == IIRFEBL )
        max = 15;
      else
        max = 1;
      *(&RITM_test_RT1007_B.ReadIntStatusFC1_o2) = max;
      iir &= IIRREASON;
      while (iir != 1 )                // Service all reasons
      {
        switch ( iir )
        {
         case 1:                       // No interrupt on this UART
          break;

         case 4:                       // received data available
         case 6:                       // receiver line status, overrun etc.
         case 0xc:                     // character timeout
          //printf("%1xa", base[i]>>8);
          // All three are receive interrupts
          switch (port)
          {
           case 0:
            /* Output and update for function-call system: '<S31>/Receive 1' */

            /* S-Function (serreadbase): '<S32>/Read HW FIFO1' incorporates:
             *  Constant: '<S32>/Constant'
             */
            {
              /* S-Function Block: <S32>/Read HW FIFO1 (serreadbase) */
              int status = 0;
              int count = 0;

              // While there is data in the fifo, read it, also read error status.
              // Cap the read length to the interrupt point in 64 byte fifo mode.
              while (((status = xpcInpB( (unsigned short)(760 + slrtLSR) ) &
                       0xff ) & LSRDR) && (count < 56) ) {
                int c;
                int masked;
                count++;
                c = xpcInpB( (unsigned short)(760 + slrtDATA) ) & 0xff;// read character
                masked = status & (LSROE | LSRPE | LSRFE | LSRBI);
                ((int_T *)&RITM_test_RT1007_B.ReadHWFIFO1[0])[count] = (masked <<
                  8) | c;
              }

              ((int_T *)&RITM_test_RT1007_B.ReadHWFIFO1[0])[0] = count;
            }

            /* S-Function (fifowrite): '<S32>/FIFO write 1' */
            {
              const char *err;
              static char msg[100];
              err = fifowrite(RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[0],
                              RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[1],
                              &RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[2],
                              &RITM_test_RT1007_DW.FIFOwrite1_IWORK_o[0]);
              if (err) {
                if (strncmp("FIFO", err, 4)) {
                  rtmSetErrorStatus(RITM_test_RT1007_M, err);
                } else {
                  int n = strlen(err);
                  strcpy(msg, err);
                  strncpy(msg + n, "RCV channel 1, IRQ 3", 99 - n);
                  rtmSetErrorStatus(RITM_test_RT1007_M, msg);
                }
              }
            }

            RITM_test_RT1007_DW.Receive1_SubsysRanBC = 4;
            break;
          }
          break;

         case 2:                       // Transmitter holding register empty
          //printf("%1xb", base[i]>>8);
          switch (port)
          {
           case 0:
            /* Output and update for function-call system: '<S31>/Transmit 1' */

            /* S-Function (fiforead): '<S34>/FIFO read 1' incorporates:
             *  Constant: '<S34>/Constant1'
             */
            {
              void **iPtrs = &RITM_test_RT1007_DW.FIFOread1_PWORK[0];
              void **oPtrs = &RITM_test_RT1007_DW.FIFOread1_PWORK[3];
              fiforead(iPtrs, oPtrs, &RITM_test_RT1007_DW.FIFOread1_IWORK[0]);
            }

            /* S-Function (serwritebase): '<S34>/Write HW FIFO1' */
            {
              /* S-Function Block: <S34>/Write HW FIFO1 (serwritebase) */
              int_T *IPtr = (int_T *)&RITM_test_RT1007_B.FIFOread1_o1[0];
              if (RITM_test_RT1007_B.FIFOread1_o2 > 0 ) {
                // On entry, verify that the transmitter holding register is empty
                // so we can stuff all that came from the software fifo into the
                // hardware fifo.  Assume that the software fifo has a max read
                // parameter that fits with the hardware fifo mode setting.
                if (IPtr[0] == 0 ) {
                  // No data, turn off the transmitter empty interrupt and leave
                  TBTakeSpinFast( slrtSerialLock );
                  int ier = xpcInpB( (unsigned short)(760 + slrtIER) ) & 0xff;
                  xpcOutpB( (unsigned short)(760 + slrtIER), (uint8_T)(ier &
                            ~IERXMT) );
                  TBGiveSpinFast( slrtSerialLock );
                } else if (xpcInpB( (unsigned short)(760 + slrtLSR) ) & LSRTHRE )
                {
                  int i;

                  // Copy all the data from the input vector to the HW fifo.
                  // The fifo read block MUST have the correct max read value
                  // for the fifo mode.
                  for (i = 0 ; i < IPtr[0] ; i++ ) {
                    xpcOutpB( (ushort_T)(760 + slrtDATA), (uint8_T)(IPtr[i+1] &
                              0xff) );
                  }
                } else {
                  rtmSetErrorStatus(RITM_test_RT1007_M,
                                    "Attempted write to hardware fifo that isn't empty");
                  return;
                }
              }
            }

            RITM_test_RT1007_DW.Transmit1_SubsysRanBC = 4;
            break;
          }
          break;

         case 0:
          // Modem status change
          break;
        }

        // Read IIR again to see if we're done with this UART
        iir = xpcInpB( (unsigned short)(base[port] + slrtIIR) ) & IIRREASON;
      }
    }
  }

  /* End of Outputs for S-Function (iquerybase): '<S31>/Read Int Status FC1' */
  RITM_test_RT1007_DW.RS232ISR_SubsysRanBC = 4;
}

/* Termination for function-call system: '<S24>/RS232 ISR' */
void RITM_test_R_RS232ISR_j_Term(void)
{
  /* Terminate for S-Function (iquerybase): '<S31>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S31>/Receive 1'
   */
  /* Termination for function-call system: '<S31>/Receive 1' */

  /* Terminate for S-Function (fifowrite): '<S32>/FIFO write 1' */

  /* Free fifo memory */
  if (RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[0]) {
    free(RITM_test_RT1007_DW.FIFOwrite1_PWORK_b[0]);
  }

  /* Terminate for S-Function (iquerybase): '<S31>/Read Int Status FC1' incorporates:
   *  SubSystem: '<S31>/Receive 2'
   */

  /* Termination for function-call system: '<S31>/Receive 2' */

  /* Terminate for S-Function (fifowrite): '<S33>/FIFO write 2' */

  /* Free fifo memory */
  if (RITM_test_RT1007_DW.FIFOwrite2_PWORK_a[0]) {
    free(RITM_test_RT1007_DW.FIFOwrite2_PWORK_a[0]);
  }

  /* End of Terminate for S-Function (iquerybase): '<S31>/Read Int Status FC1' */
}

/* Model output function for TID0 */
static void RITM_test_RT1007_output0(void) /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_scheduler();
  }

  /* Outputs for Atomic SubSystem: '<Root>/BA-IS-GPIO' */
  /* S-Function (BA_IS_gpio_di): '<S1>/BA_IS_gpio_di' */

  /* Level2 S-Function Block: '<S1>/BA_IS_gpio_di' (BA_IS_gpio_di) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (scblock): '<S8>/S-Function' */
  /* ok to acquire for <S8>/S-Function */
  RITM_test_RT1007_DW.SFunction_IWORK_k.AcquireOK = 1;

  /* DiscretePulseGenerator: '<S1>/Twice a second' */
  RITM_test_RT1007_B.Twiceasecond = (RITM_test_RT1007_DW.clockTickCounter <
    RITM_test_RT1007_P.Twiceasecond_Duty) &&
    (RITM_test_RT1007_DW.clockTickCounter >= 0) ?
    RITM_test_RT1007_P.Twiceasecond_Amp : 0.0;
  if (RITM_test_RT1007_DW.clockTickCounter >=
      RITM_test_RT1007_P.Twiceasecond_Period - 1.0) {
    RITM_test_RT1007_DW.clockTickCounter = 0;
  } else {
    RITM_test_RT1007_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Twice a second' */

  /* S-Function (BA_IS_gpio_do): '<S1>/BA_IS_gpio_do' */

  /* Level2 S-Function Block: '<S1>/BA_IS_gpio_do' (BA_IS_gpio_do) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* End of Outputs for SubSystem: '<Root>/BA-IS-GPIO' */

  /* Outputs for Atomic SubSystem: '<Root>/BA-IS-PWM-CAP' */
  /* S-Function (BA_IS_cap): '<S3>/BA-IS-CAP' */

  /* Level2 S-Function Block: '<S3>/BA-IS-CAP' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (scblock): '<S10>/S-Function' */
  /* ok to acquire for <S10>/S-Function */
  RITM_test_RT1007_DW.SFunction_IWORK_o.AcquireOK = 1;

  /* S-Function (BA_IS_cap): '<S3>/BA-IS-CAP1' */

  /* Level2 S-Function Block: '<S3>/BA-IS-CAP1' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (BA_IS_cap): '<S3>/BA-IS-CAP2' */

  /* Level2 S-Function Block: '<S3>/BA-IS-CAP2' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* S-Function (BA_IS_cap): '<S3>/BA-IS-CAP3' */

  /* Level2 S-Function Block: '<S3>/BA-IS-CAP3' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S3>/Constant1' */
  RITM_test_RT1007_B.Constant1 = RITM_test_RT1007_P.Constant1_Value;

  /* Constant: '<S3>/Constant8' */
  RITM_test_RT1007_B.Constant8 = RITM_test_RT1007_P.Constant8_Value;

  /* S-Function (BA_IS_pwm): '<S3>/BA-IS-PWM' */

  /* Level2 S-Function Block: '<S3>/BA-IS-PWM' (BA_IS_pwm) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S3>/Constant2' */
  RITM_test_RT1007_B.Constant2 = RITM_test_RT1007_P.Constant2_Value;

  /* Constant: '<S3>/Constant3' */
  RITM_test_RT1007_B.Constant3 = RITM_test_RT1007_P.Constant3_Value;

  /* S-Function (BA_IS_pwm): '<S3>/BA-IS-PWM1' */

  /* Level2 S-Function Block: '<S3>/BA-IS-PWM1' (BA_IS_pwm) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* End of Outputs for SubSystem: '<Root>/BA-IS-PWM-CAP' */

  /* Outputs for Atomic SubSystem: '<Root>/BA-IS-UART' */
  /* S-Function (BA_IS_uart_setup): '<S5>/BA-IS-UART_setup' */

  /* Level2 S-Function Block: '<S5>/BA-IS-UART_setup' (BA_IS_uart_setup) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[10];
    sfcnOutputs(rts,0);
  }

  /* S-Function (BA_IS_uart_rx): '<S5>/BA-IS-UART_rx' */

  /* Level2 S-Function Block: '<S5>/BA-IS-UART_rx' (BA_IS_uart_rx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[11];
    sfcnOutputs(rts,0);
  }

  /* S-Function (scblock): '<S16>/S-Function' */
  /* ok to acquire for <S16>/S-Function */
  RITM_test_RT1007_DW.SFunction_IWORK_h.AcquireOK = 1;

  /* End of Outputs for SubSystem: '<Root>/BA-IS-UART' */

  /* Outputs for Atomic SubSystem: '<Root>/CA-MA-45' */
  /* S-Function (CA_MA_rx): '<S6>/CA_MA_rx' */

  /* Level2 S-Function Block: '<S6>/CA_MA_rx' (CA_MA_rx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[13];
    sfcnOutputs(rts,0);
  }

  /* S-Function (scanunpack): '<S6>/CAN Unpack' */
  {
    /* S-Function (scanunpack): '<S6>/CAN Unpack' */
    uint8_T msgReceived = 0;
    if ((8 == RITM_test_RT1007_B.CA_MA_rx_o2.Length) &&
        (RITM_test_RT1007_B.CA_MA_rx_o2.ID != INVALID_CAN_ID) ) {
      if ((666 == RITM_test_RT1007_B.CA_MA_rx_o2.ID) && (1U ==
           RITM_test_RT1007_B.CA_MA_rx_o2.Extended) ) {
        msgReceived = 1;

        {
          /* --------------- START Unpacking signal 0 ------------------
           *  startBit                = 0
           *  length                  = 64
           *  desiredSignalByteLayout = LITTLEENDIAN
           *  dataType                = DOUBLE
           *  factor                  = 1.0
           *  offset                  = 0.0
           * -----------------------------------------------------------------------*/
          {
            real64_T outValue = 0;

            {
              real64_T typeUnpackedValue = 0;

              {
                (void) memcpy(&typeUnpackedValue,
                              RITM_test_RT1007_B.CA_MA_rx_o2.Data,
                              8);
              }

              outValue = (real64_T) (typeUnpackedValue);
            }

            {
              real64_T result = (real64_T) outValue;
              RITM_test_RT1007_B.CANUnpack_o1 = result;
            }
          }
        }

        /* Extract the ID */
        RITM_test_RT1007_B.CANUnpack_o2 = RITM_test_RT1007_B.CA_MA_rx_o2.ID;

        /* Extract the Timestamp */
        RITM_test_RT1007_B.CANUnpack_o3 =
          RITM_test_RT1007_B.CA_MA_rx_o2.Timestamp;

        /* Extract the Error */
        RITM_test_RT1007_B.CANUnpack_o4 = RITM_test_RT1007_B.CA_MA_rx_o2.Error;

        /* Extract the Remote */
        RITM_test_RT1007_B.CANUnpack_o5 = RITM_test_RT1007_B.CA_MA_rx_o2.Remote;

        /* Extract the length */
        RITM_test_RT1007_B.CANUnpack_o6 = RITM_test_RT1007_B.CA_MA_rx_o2.Length;
      }
    }

    /* Status port */
    RITM_test_RT1007_B.CANUnpack_o7 = msgReceived;
  }

  /* S-Function (scblock): '<S20>/S-Function' */
  /* ok to acquire for <S20>/S-Function */
  RITM_test_RT1007_DW.SFunction_IWORK_g.AcquireOK = 1;

  /* S-Function (CA_MA_status): '<S19>/CA_MA_status' */

  /* Level2 S-Function Block: '<S19>/CA_MA_status' (CA_MA_status) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[14];
    sfcnOutputs(rts,0);
  }

  /* DataTypeConversion: '<S21>/Extract Desired Bits' */
  RITM_test_RT1007_B.ExtractDesiredBits_o = (uint8_T)
    (RITM_test_RT1007_B.CA_MA_status_e[0] & 1);

  /* DataTypeConversion: '<S21>/Modify Scaling Only' */
  RITM_test_RT1007_B.ModifyScalingOnly = RITM_test_RT1007_B.ExtractDesiredBits_o;

  /* DataTypeConversion: '<S22>/Extract Desired Bits' */
  RITM_test_RT1007_B.ExtractDesiredBits = (uint8_T)((uint32_T)
    RITM_test_RT1007_B.CA_MA_status_e[1] >> 7);

  /* DataTypeConversion: '<S22>/Modify Scaling Only' */
  RITM_test_RT1007_B.ModifyScalingOnly_d = RITM_test_RT1007_B.ExtractDesiredBits;

  /* SignalConversion: '<S19>/Signal Conversion' */
  RITM_test_RT1007_B.RxErrorCounter = RITM_test_RT1007_B.CA_MA_status_e[2];

  /* SignalConversion: '<S19>/Signal Conversion1' */
  RITM_test_RT1007_B.TxErrorCounter = RITM_test_RT1007_B.CA_MA_status_e[3];

  /* Sin: '<S6>/Sine Wave' */
  if (RITM_test_RT1007_DW.systemEnable_i != 0) {
    RITM_test_RT1007_DW.lastSin_d = sin(RITM_test_RT1007_P.SineWave_Freq *
      RITM_test_RT1007_M->Timing.t[0]);
    RITM_test_RT1007_DW.lastCos_b = cos(RITM_test_RT1007_P.SineWave_Freq *
      RITM_test_RT1007_M->Timing.t[0]);
    RITM_test_RT1007_DW.systemEnable_i = 0;
  }

  RITM_test_RT1007_B.SineWave_k = ((RITM_test_RT1007_DW.lastSin_d *
    RITM_test_RT1007_P.SineWave_PCos + RITM_test_RT1007_DW.lastCos_b *
    RITM_test_RT1007_P.SineWave_PSin) * RITM_test_RT1007_P.SineWave_HCos +
    (RITM_test_RT1007_DW.lastCos_b * RITM_test_RT1007_P.SineWave_PCos -
     RITM_test_RT1007_DW.lastSin_d * RITM_test_RT1007_P.SineWave_PSin) *
    RITM_test_RT1007_P.SineWave_Hsin) * RITM_test_RT1007_P.SineWave_Amp +
    RITM_test_RT1007_P.SineWave_Bias;

  /* End of Sin: '<S6>/Sine Wave' */

  /* S-Function (scanpack): '<S6>/CAN Pack' */
  /* S-Function (scanpack): '<S6>/CAN Pack' */
  RITM_test_RT1007_B.CANPack.ID = 666U;
  RITM_test_RT1007_B.CANPack.Length = 8U;
  RITM_test_RT1007_B.CANPack.Extended = 1U;
  RITM_test_RT1007_B.CANPack.Remote = 0;
  RITM_test_RT1007_B.CANPack.Data[0] = 0;
  RITM_test_RT1007_B.CANPack.Data[1] = 0;
  RITM_test_RT1007_B.CANPack.Data[2] = 0;
  RITM_test_RT1007_B.CANPack.Data[3] = 0;
  RITM_test_RT1007_B.CANPack.Data[4] = 0;
  RITM_test_RT1007_B.CANPack.Data[5] = 0;
  RITM_test_RT1007_B.CANPack.Data[6] = 0;
  RITM_test_RT1007_B.CANPack.Data[7] = 0;

  {
    /* --------------- START Packing signal 0 ------------------
     *  startBit                = 0
     *  length                  = 64
     *  desiredSignalByteLayout = LITTLEENDIAN
     *  dataType                = DOUBLE
     *  factor                  = 1.0
     *  offset                  = 0.0
     *  minimum                 = 0.0
     *  maximum                 = 0.0
     * -----------------------------------------------------------------------*/
    {
      real64_T outValue = 0;

      {
        real64_T result = RITM_test_RT1007_B.SineWave_k;

        /* no scaling required */
        outValue = result;
      }

      {
        real64_T typedValue = outValue;

        {
          (void) memcpy(RITM_test_RT1007_B.CANPack.Data, &typedValue,
                        8);
        }
      }
    }
  }

  /* S-Function (CA_MA_tx): '<S6>/CA_MA_tx' */

  /* Level2 S-Function Block: '<S6>/CA_MA_tx' (CA_MA_tx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[15];
    sfcnOutputs(rts,0);
  }

  /* S-Function (CA_MA_rx): '<S6>/CA_MA_rx1' */

  /* Level2 S-Function Block: '<S6>/CA_MA_rx1' (CA_MA_rx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[16];
    sfcnOutputs(rts,0);
  }

  /* S-Function (CA_MA_setup): '<S6>/CA_MA_setup' */

  /* Level2 S-Function Block: '<S6>/CA_MA_setup' (CA_MA_setup) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[17];
    sfcnOutputs(rts,0);
  }

  /* End of Outputs for SubSystem: '<Root>/CA-MA-45' */
}

/* Model update function for TID0 */
static void RITM_test_RT1007_update0(void) /* Sample time: [0.001s, 0.0s] */
{
  real_T HoldSine;
  real_T HoldCosine;

  /* Update for Atomic SubSystem: '<Root>/CA-MA-45' */
  /* Update for Sin: '<S6>/Sine Wave' */
  HoldSine = RITM_test_RT1007_DW.lastSin_d;
  HoldCosine = RITM_test_RT1007_DW.lastCos_b;
  RITM_test_RT1007_DW.lastSin_d = HoldSine * RITM_test_RT1007_P.SineWave_HCos +
    HoldCosine * RITM_test_RT1007_P.SineWave_Hsin;
  RITM_test_RT1007_DW.lastCos_b = HoldCosine * RITM_test_RT1007_P.SineWave_HCos
    - HoldSine * RITM_test_RT1007_P.SineWave_Hsin;

  /* End of Update for SubSystem: '<Root>/CA-MA-45' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++RITM_test_RT1007_M->Timing.clockTick0)) {
    ++RITM_test_RT1007_M->Timing.clockTickH0;
  }

  RITM_test_RT1007_M->Timing.t[0] = RITM_test_RT1007_M->Timing.clockTick0 *
    RITM_test_RT1007_M->Timing.stepSize0 +
    RITM_test_RT1007_M->Timing.clockTickH0 *
    RITM_test_RT1007_M->Timing.stepSize0 * 4294967296.0;
  rtw_xpc_mutex_take(RITM_test_RT1007_M->Timing.semIdForTask3);
  RITM_test_RT1007_M->Timing.rtmClockTickBuf3 =
    RITM_test_RT1007_M->Timing.clockTick0;
  RITM_test_RT1007_M->Timing.rtmBufClockTickBufH3 =
    RITM_test_RT1007_M->Timing.clockTickH0;
  rtw_xpc_mutex_give(RITM_test_RT1007_M->Timing.semIdForTask3);
  rtw_xpc_mutex_take(RITM_test_RT1007_M->Timing.semIdForTask4);
  RITM_test_RT1007_M->Timing.rtmClockTickBuf4 =
    RITM_test_RT1007_M->Timing.clockTick0;
  RITM_test_RT1007_M->Timing.rtmBufClockTickBufH4 =
    RITM_test_RT1007_M->Timing.clockTickH0;
  rtw_xpc_mutex_give(RITM_test_RT1007_M->Timing.semIdForTask4);
}

/* Model output function for TID1 */
static void RITM_test_RT1007_output1(void) /* Sample time: [0.01s, 0.0s] */
{
  /* RateTransition: '<S24>/Rate Transition1' */
  RITM_test_RT1007_B.RateTransition1 = RITM_test_RT1007_B.FIFOwrite1;

  /* S-Function (fiforead): '<S7>/FIFO read ' */
  {
    void **iPtrs = &RITM_test_RT1007_DW.FIFOread_PWORK[0];
    void **oPtrs = &RITM_test_RT1007_DW.FIFOread_PWORK[3];
    fiforead(iPtrs, oPtrs, &RITM_test_RT1007_DW.FIFOread_IWORK[0]);
  }

  /* S-Function (asciidecode): '<S7>/ASCII Decode ' */

  /* Level2 S-Function Block: '<S7>/ASCII Decode ' (asciidecode) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[18];
    sfcnOutputs(rts,1);
  }

  /* S-Function (scblock): '<S25>/S-Function' */
  /* ok to acquire for <S25>/S-Function */
  RITM_test_RT1007_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (fifowrite): '<S24>/FIFO write 1' */
  {
    const char *err;
    static char msg[100];
    err = fifowrite(RITM_test_RT1007_DW.FIFOwrite1_PWORK[0],
                    RITM_test_RT1007_DW.FIFOwrite1_PWORK[1],
                    &RITM_test_RT1007_DW.FIFOwrite1_PWORK[2],
                    &RITM_test_RT1007_DW.FIFOwrite1_IWORK[0]);
    if (err) {
      if (strncmp("FIFO", err, 4)) {
        rtmSetErrorStatus(RITM_test_RT1007_M, err);
      } else {
        int n = strlen(err);
        strcpy(msg, err);
        strncpy(msg + n, "XMT channel 1, IRQ 3", 99 - n);
        rtmSetErrorStatus(RITM_test_RT1007_M, msg);
      }
    }
  }

  /* S-Function (sertxenablebase): '<S24>/Enable TX 1' */

  /* S-Function Block: <S24>/Enable TX 1 (sertxenablebase) */
  if (RITM_test_RT1007_B.FIFOwrite1_o2 == 1 ) {
    TBTakeSpinFast( slrtSerialLock );
    uint8_T reg = (uint8_T)xpcInpB( (unsigned short)(760 + slrtIER) ) & 0xff;
    xpcOutpB( (unsigned short)(760 + slrtIER), (uint8_T)(reg & ~IERXMT) );
    reg |= IERXMT;
    xpcOutpB( (unsigned short)(760 + slrtIER), reg );
    TBGiveSpinFast( slrtSerialLock );
  }

  /* S-Function (fifowrite): '<S24>/FIFO write 2' */
  {
    const char *err;
    static char msg[100];
    err = fifowrite(RITM_test_RT1007_DW.FIFOwrite2_PWORK[0],
                    RITM_test_RT1007_DW.FIFOwrite2_PWORK[1],
                    &RITM_test_RT1007_DW.FIFOwrite2_PWORK[2],
                    &RITM_test_RT1007_DW.FIFOwrite2_IWORK[0]);
    if (err) {
      if (strncmp("FIFO", err, 4)) {
        rtmSetErrorStatus(RITM_test_RT1007_M, err);
      } else {
        int n = strlen(err);
        strcpy(msg, err);
        strncpy(msg + n, "XMT channel 2, IRQ 3", 99 - n);
        rtmSetErrorStatus(RITM_test_RT1007_M, msg);
      }
    }
  }

  /* RateTransition: '<S24>/Rate Transition3' */
  RITM_test_RT1007_B.RateTransition3 = RITM_test_RT1007_B.FIFOwrite2;

  /* S-Function (sersetupbase): '<S24>/Setup1' */

  /* Level2 S-Function Block: '<S24>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[19];
    sfcnOutputs(rts,1);
  }

  /* S-Function (sersetupbase): '<S24>/Setup2' */

  /* Level2 S-Function Block: '<S24>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[20];
    sfcnOutputs(rts,1);
  }

  /* Sin: '<S7>/Sine Wave' */
  if (RITM_test_RT1007_DW.systemEnable != 0) {
    RITM_test_RT1007_DW.lastSin = sin(RITM_test_RT1007_P.SineWave_Freq_p *
      RITM_test_RT1007_M->Timing.t[1]);
    RITM_test_RT1007_DW.lastCos = cos(RITM_test_RT1007_P.SineWave_Freq_p *
      RITM_test_RT1007_M->Timing.t[1]);
    RITM_test_RT1007_DW.systemEnable = 0;
  }

  RITM_test_RT1007_B.SineWave = ((RITM_test_RT1007_DW.lastSin *
    RITM_test_RT1007_P.SineWave_PCos_d + RITM_test_RT1007_DW.lastCos *
    RITM_test_RT1007_P.SineWave_PSin_p) * RITM_test_RT1007_P.SineWave_HCos_f +
    (RITM_test_RT1007_DW.lastCos * RITM_test_RT1007_P.SineWave_PCos_d -
     RITM_test_RT1007_DW.lastSin * RITM_test_RT1007_P.SineWave_PSin_p) *
    RITM_test_RT1007_P.SineWave_Hsin_j) * RITM_test_RT1007_P.SineWave_Amp_o +
    RITM_test_RT1007_P.SineWave_Bias_n;

  /* End of Sin: '<S7>/Sine Wave' */

  /* S-Function (asciiencode): '<S7>/ASCII Encode ' */

  /* Level2 S-Function Block: '<S7>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[21];
    sfcnOutputs(rts,1);
  }

  /* S-Function (fifowrite): '<S23>/FIFO write 1' */
  {
    const char *err;
    static char msg[100];
    err = fifowrite(RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[0],
                    RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[1],
                    &RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[2],
                    &RITM_test_RT1007_DW.FIFOwrite1_IWORK_f[0]);
    if (err) {
      if (strncmp("FIFO", err, 4)) {
        rtmSetErrorStatus(RITM_test_RT1007_M, err);
      } else {
        int n = strlen(err);
        strcpy(msg, err);
        strncpy(msg + n, "XMT channel 1, IRQ 4", 99 - n);
        rtmSetErrorStatus(RITM_test_RT1007_M, msg);
      }
    }
  }

  /* S-Function (sertxenablebase): '<S23>/Enable TX 1' */

  /* S-Function Block: <S23>/Enable TX 1 (sertxenablebase) */
  if (RITM_test_RT1007_B.FIFOwrite1_o2_b == 1 ) {
    TBTakeSpinFast( slrtSerialLock );
    uint8_T reg = (uint8_T)xpcInpB( (unsigned short)(1016 + slrtIER) ) & 0xff;
    xpcOutpB( (unsigned short)(1016 + slrtIER), (uint8_T)(reg & ~IERXMT) );
    reg |= IERXMT;
    xpcOutpB( (unsigned short)(1016 + slrtIER), reg );
    TBGiveSpinFast( slrtSerialLock );
  }

  /* S-Function (fifowrite): '<S23>/FIFO write 2' */
  {
    const char *err;
    static char msg[100];
    err = fifowrite(RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[0],
                    RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[1],
                    &RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[2],
                    &RITM_test_RT1007_DW.FIFOwrite2_IWORK_n[0]);
    if (err) {
      if (strncmp("FIFO", err, 4)) {
        rtmSetErrorStatus(RITM_test_RT1007_M, err);
      } else {
        int n = strlen(err);
        strcpy(msg, err);
        strncpy(msg + n, "XMT channel 2, IRQ 4", 99 - n);
        rtmSetErrorStatus(RITM_test_RT1007_M, msg);
      }
    }
  }

  /* RateTransition: '<S23>/Rate Transition1' */
  RITM_test_RT1007_B.RateTransition1_j = RITM_test_RT1007_B.FIFOwrite1_e;

  /* RateTransition: '<S23>/Rate Transition3' */
  RITM_test_RT1007_B.RateTransition3_e = RITM_test_RT1007_B.FIFOwrite2_e;

  /* S-Function (sersetupbase): '<S23>/Setup1' */

  /* Level2 S-Function Block: '<S23>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[22];
    sfcnOutputs(rts,1);
  }

  /* S-Function (sersetupbase): '<S23>/Setup2' */

  /* Level2 S-Function Block: '<S23>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[23];
    sfcnOutputs(rts,1);
  }

  /* End of Outputs for SubSystem: '<Root>/RS-232' */
}

/* Model update function for TID1 */
static void RITM_test_RT1007_update1(void) /* Sample time: [0.01s, 0.0s] */
{
  real_T HoldSine;
  real_T HoldCosine;

  /* Update for Atomic SubSystem: '<Root>/RS-232' */
  /* Update for Sin: '<S7>/Sine Wave' */
  HoldSine = RITM_test_RT1007_DW.lastSin;
  HoldCosine = RITM_test_RT1007_DW.lastCos;
  RITM_test_RT1007_DW.lastSin = HoldSine * RITM_test_RT1007_P.SineWave_HCos_f +
    HoldCosine * RITM_test_RT1007_P.SineWave_Hsin_j;
  RITM_test_RT1007_DW.lastCos = HoldCosine * RITM_test_RT1007_P.SineWave_HCos_f
    - HoldSine * RITM_test_RT1007_P.SineWave_Hsin_j;

  /* End of Update for SubSystem: '<Root>/RS-232' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++RITM_test_RT1007_M->Timing.clockTick1)) {
    ++RITM_test_RT1007_M->Timing.clockTickH1;
  }

  RITM_test_RT1007_M->Timing.t[1] = RITM_test_RT1007_M->Timing.clockTick1 *
    RITM_test_RT1007_M->Timing.stepSize1 +
    RITM_test_RT1007_M->Timing.clockTickH1 *
    RITM_test_RT1007_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output function for TID2 */
static void RITM_test_RT1007_output2(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/BA-IS-I2C' */
  /* S-Function (BA_IS_i2c_read): '<S2>/BA-IS-I2C_read' */

  /* Level2 S-Function Block: '<S2>/BA-IS-I2C_read' (BA_IS_i2c_read) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[2];
    sfcnOutputs(rts,2);
  }

  /* S-Function (scblock): '<S9>/S-Function' */
  /* ok to acquire for <S9>/S-Function */
  RITM_test_RT1007_DW.SFunction_IWORK_l.AcquireOK = 1;

  /* End of Outputs for SubSystem: '<Root>/BA-IS-I2C' */

  /* Outputs for Atomic SubSystem: '<Root>/BA-IS-SPI' */
  /* UnitDelay: '<S11>/Output' */
  RITM_test_RT1007_B.Output_b = RITM_test_RT1007_DW.Output_DSTATE_e;

  /* ManualSwitch: '<S4>/Manual Switch' incorporates:
   *  Constant: '<S4>/Generate some data'
   */
  if (RITM_test_RT1007_P.ManualSwitch_CurrentSetting == 1) {
    RITM_test_RT1007_B.ManualSwitch_g[0] =
      RITM_test_RT1007_P.Generatesomedata_Value[0];
    RITM_test_RT1007_B.ManualSwitch_g[1] =
      RITM_test_RT1007_P.Generatesomedata_Value[1];
    RITM_test_RT1007_B.ManualSwitch_g[2] =
      RITM_test_RT1007_P.Generatesomedata_Value[2];
    RITM_test_RT1007_B.ManualSwitch_g[3] =
      RITM_test_RT1007_P.Generatesomedata_Value[3];
  } else {
    /* Bias: '<S4>/Bias1' */
    RITM_test_RT1007_B.Bias1[0] = (uint8_T)((uint32_T)
      RITM_test_RT1007_P.Bias1_Bias[0] + RITM_test_RT1007_B.Output_b);
    RITM_test_RT1007_B.Bias1[1] = (uint8_T)((uint32_T)
      RITM_test_RT1007_P.Bias1_Bias[1] + RITM_test_RT1007_B.Output_b);
    RITM_test_RT1007_B.Bias1[2] = (uint8_T)((uint32_T)
      RITM_test_RT1007_P.Bias1_Bias[2] + RITM_test_RT1007_B.Output_b);
    RITM_test_RT1007_B.Bias1[3] = (uint8_T)((uint32_T)
      RITM_test_RT1007_P.Bias1_Bias[3] + RITM_test_RT1007_B.Output_b);
    RITM_test_RT1007_B.ManualSwitch_g[0] = RITM_test_RT1007_B.Bias1[0];
    RITM_test_RT1007_B.ManualSwitch_g[1] = RITM_test_RT1007_B.Bias1[1];
    RITM_test_RT1007_B.ManualSwitch_g[2] = RITM_test_RT1007_B.Bias1[2];
    RITM_test_RT1007_B.ManualSwitch_g[3] = RITM_test_RT1007_B.Bias1[3];
  }

  /* End of ManualSwitch: '<S4>/Manual Switch' */

  /* S-Function (BA_IS_spi): '<S4>/BA-IS-SPI1' */

  /* Level2 S-Function Block: '<S4>/BA-IS-SPI1' (BA_IS_spi) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[9];
    sfcnOutputs(rts,2);
  }

  /* S-Function (scblock): '<S12>/S-Function' */
  /* ok to acquire for <S12>/S-Function */
  RITM_test_RT1007_DW.SFunction_IWORK_c.AcquireOK = 1;

  /* Sum: '<S13>/FixPt Sum1' incorporates:
   *  Constant: '<S13>/FixPt Constant'
   */
  RITM_test_RT1007_B.FixPtSum1_b = (uint8_T)((uint32_T)
    RITM_test_RT1007_B.Output_b + RITM_test_RT1007_P.FixPtConstant_Value);

  /* Switch: '<S14>/FixPt Switch' incorporates:
   *  Constant: '<S14>/Constant'
   */
  if (RITM_test_RT1007_B.FixPtSum1_b >
      RITM_test_RT1007_P.CounterLimited1_uplimit) {
    RITM_test_RT1007_B.FixPtSwitch_f = RITM_test_RT1007_P.Constant_Value_i;
  } else {
    RITM_test_RT1007_B.FixPtSwitch_f = RITM_test_RT1007_B.FixPtSum1_b;
  }

  /* End of Switch: '<S14>/FixPt Switch' */
  /* End of Outputs for SubSystem: '<Root>/BA-IS-SPI' */

  /* Outputs for Atomic SubSystem: '<Root>/BA-IS-UART' */
  /* UnitDelay: '<S15>/Output' */
  RITM_test_RT1007_B.Output = RITM_test_RT1007_DW.Output_DSTATE;

  /* ManualSwitch: '<S5>/Manual Switch' incorporates:
   *  Constant: '<S5>/Generate some data'
   */
  if (RITM_test_RT1007_P.ManualSwitch_CurrentSetting_m == 1) {
    RITM_test_RT1007_B.ManualSwitch[0] =
      RITM_test_RT1007_P.Generatesomedata_Value_l[0];
    RITM_test_RT1007_B.ManualSwitch[1] =
      RITM_test_RT1007_P.Generatesomedata_Value_l[1];
    RITM_test_RT1007_B.ManualSwitch[2] =
      RITM_test_RT1007_P.Generatesomedata_Value_l[2];
    RITM_test_RT1007_B.ManualSwitch[3] =
      RITM_test_RT1007_P.Generatesomedata_Value_l[3];
  } else {
    RITM_test_RT1007_B.ManualSwitch[0] = RITM_test_RT1007_B.Output;
    RITM_test_RT1007_B.ManualSwitch[1] = RITM_test_RT1007_B.Output;
    RITM_test_RT1007_B.ManualSwitch[2] = RITM_test_RT1007_B.Output;
    RITM_test_RT1007_B.ManualSwitch[3] = RITM_test_RT1007_B.Output;
  }

  /* End of ManualSwitch: '<S5>/Manual Switch' */

  /* S-Function (BA_IS_uart_tx): '<S5>/BA-IS-UART_tx' */

  /* Level2 S-Function Block: '<S5>/BA-IS-UART_tx' (BA_IS_uart_tx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[12];
    sfcnOutputs(rts,2);
  }

  /* Sum: '<S17>/FixPt Sum1' incorporates:
   *  Constant: '<S17>/FixPt Constant'
   */
  RITM_test_RT1007_B.FixPtSum1 = (uint8_T)((uint32_T)RITM_test_RT1007_B.Output +
    RITM_test_RT1007_P.FixPtConstant_Value_k);

  /* Switch: '<S18>/FixPt Switch' incorporates:
   *  Constant: '<S18>/Constant'
   */
  if (RITM_test_RT1007_B.FixPtSum1 > RITM_test_RT1007_P.CounterLimited_uplimit)
  {
    RITM_test_RT1007_B.FixPtSwitch = RITM_test_RT1007_P.Constant_Value_h;
  } else {
    RITM_test_RT1007_B.FixPtSwitch = RITM_test_RT1007_B.FixPtSum1;
  }

  /* End of Switch: '<S18>/FixPt Switch' */
  /* End of Outputs for SubSystem: '<Root>/BA-IS-UART' */
}

/* Model update function for TID2 */
static void RITM_test_RT1007_update2(void) /* Sample time: [0.1s, 0.0s] */
{
  /* Update for Atomic SubSystem: '<Root>/BA-IS-SPI' */
  /* Update for UnitDelay: '<S11>/Output' */
  RITM_test_RT1007_DW.Output_DSTATE_e = RITM_test_RT1007_B.FixPtSwitch_f;

  /* End of Update for SubSystem: '<Root>/BA-IS-SPI' */

  /* Update for Atomic SubSystem: '<Root>/BA-IS-UART' */
  /* Update for UnitDelay: '<S15>/Output' */
  RITM_test_RT1007_DW.Output_DSTATE = RITM_test_RT1007_B.FixPtSwitch;

  /* End of Update for SubSystem: '<Root>/BA-IS-UART' */

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++RITM_test_RT1007_M->Timing.clockTick2)) {
    ++RITM_test_RT1007_M->Timing.clockTickH2;
  }

  RITM_test_RT1007_M->Timing.t[2] = RITM_test_RT1007_M->Timing.clockTick2 *
    RITM_test_RT1007_M->Timing.stepSize2 +
    RITM_test_RT1007_M->Timing.clockTickH2 *
    RITM_test_RT1007_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
static void RITM_test_RT1007_output(int_T tid)
{
  switch (tid) {
   case 0 :
    RITM_test_RT1007_output0();
    break;

   case 1 :
    RITM_test_RT1007_output1();
    break;

   case 2 :
    RITM_test_RT1007_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
static void RITM_test_RT1007_update(int_T tid)
{
  switch (tid) {
   case 0 :
    RITM_test_RT1007_update0();
    break;

   case 1 :
    RITM_test_RT1007_update1();
    break;

   case 2 :
    RITM_test_RT1007_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
static void RITM_test_RT1007_initialize(void)
{
  /* Start for Atomic SubSystem: '<Root>/BA-IS-GPIO' */
  /* Start for S-Function (BA_IS_gpio_di): '<S1>/BA_IS_gpio_di' */
  /* Level2 S-Function Block: '<S1>/BA_IS_gpio_di' (BA_IS_gpio_di) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S8>/S-Function' */

  /* S-Function Block: <S8>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("BA-IS-GPIO/BA_IS_gpio_di/p1"));
        rl32eSetScope(4, 4, 2500);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("BA-IS-GPIO/BA_IS_gpio_di/p1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        rl32eSetTargetScope(4, 1, 3.0);
        rl32eSetTargetScope(4, 11, 0.0);
        rl32eSetTargetScope(4, 10, 0.0);
        xpceScopeAcqOK(4, &RITM_test_RT1007_DW.SFunction_IWORK_k.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* Start for S-Function (BA_IS_gpio_do): '<S1>/BA_IS_gpio_do' */
  /* Level2 S-Function Block: '<S1>/BA_IS_gpio_do' (BA_IS_gpio_do) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<Root>/BA-IS-GPIO' */

  /* Start for Atomic SubSystem: '<Root>/BA-IS-PWM-CAP' */
  /* Start for S-Function (BA_IS_cap): '<S3>/BA-IS-CAP' */
  /* Level2 S-Function Block: '<S3>/BA-IS-CAP' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S10>/S-Function' */

  /* S-Function Block: <S10>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo("BA-IS-PWM-CAP/BA-IS-CAP/p1"));
        rl32eAddSignal(7, rl32eGetSignalNo("BA-IS-PWM-CAP/BA-IS-CAP/p2"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("BA-IS-PWM-CAP/BA-IS-CAP/p1"),
          "%15.8f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("BA-IS-PWM-CAP/BA-IS-CAP/p2"),
          "%15.8f");
        rl32eSetScope(7, 4, 250);
        rl32eSetScope(7, 5, 0);
        rl32eSetScope(7, 6, 1);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("BA-IS-PWM-CAP/BA-IS-CAP/p1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 9, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, 0.0);
        rl32eSetTargetScope(7, 10, 0.0);
        xpceScopeAcqOK(7, &RITM_test_RT1007_DW.SFunction_IWORK_o.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* Start for S-Function (BA_IS_cap): '<S3>/BA-IS-CAP1' */
  /* Level2 S-Function Block: '<S3>/BA-IS-CAP1' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (BA_IS_cap): '<S3>/BA-IS-CAP2' */
  /* Level2 S-Function Block: '<S3>/BA-IS-CAP2' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (BA_IS_cap): '<S3>/BA-IS-CAP3' */
  /* Level2 S-Function Block: '<S3>/BA-IS-CAP3' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S3>/Constant1' */
  RITM_test_RT1007_B.Constant1 = RITM_test_RT1007_P.Constant1_Value;

  /* Start for Constant: '<S3>/Constant8' */
  RITM_test_RT1007_B.Constant8 = RITM_test_RT1007_P.Constant8_Value;

  /* Start for S-Function (BA_IS_pwm): '<S3>/BA-IS-PWM' */
  /* Level2 S-Function Block: '<S3>/BA-IS-PWM' (BA_IS_pwm) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S3>/Constant2' */
  RITM_test_RT1007_B.Constant2 = RITM_test_RT1007_P.Constant2_Value;

  /* Start for Constant: '<S3>/Constant3' */
  RITM_test_RT1007_B.Constant3 = RITM_test_RT1007_P.Constant3_Value;

  /* Start for S-Function (BA_IS_pwm): '<S3>/BA-IS-PWM1' */
  /* Level2 S-Function Block: '<S3>/BA-IS-PWM1' (BA_IS_pwm) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<Root>/BA-IS-PWM-CAP' */

  /* Start for Atomic SubSystem: '<Root>/BA-IS-UART' */
  /* Start for S-Function (BA_IS_uart_setup): '<S5>/BA-IS-UART_setup' */
  /* Level2 S-Function Block: '<S5>/BA-IS-UART_setup' (BA_IS_uart_setup) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (BA_IS_uart_rx): '<S5>/BA-IS-UART_rx' */
  /* Level2 S-Function Block: '<S5>/BA-IS-UART_rx' (BA_IS_uart_rx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S16>/S-Function' */

  /* S-Function Block: <S16>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("BA-IS-UART/BA-IS-UART_rx/p1/s1"));
        rl32eAddSignal(5, rl32eGetSignalNo("BA-IS-UART/BA-IS-UART_rx/p1/s2"));
        rl32eAddSignal(5, rl32eGetSignalNo("BA-IS-UART/BA-IS-UART_rx/p1/s3"));
        rl32eAddSignal(5, rl32eGetSignalNo("BA-IS-UART/BA-IS-UART_rx/p1/s4"));
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "BA-IS-UART/BA-IS-UART_rx/p1/s1"),"%15.6f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "BA-IS-UART/BA-IS-UART_rx/p1/s2"),"%15.6f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "BA-IS-UART/BA-IS-UART_rx/p1/s3"),"%15.6f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "BA-IS-UART/BA-IS-UART_rx/p1/s4"),"%15.6f");
        rl32eSetScope(5, 4, 500);
        rl32eSetScope(5, 5, 0);
        rl32eSetScope(5, 6, 1);
        rl32eSetScope(5, 0, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo("BA-IS-UART/BA-IS-UART_rx/p1/s1"));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 9, 0);
        rl32eSetTargetScope(5, 1, 0.0);
        rl32eSetTargetScope(5, 11, 0.0);
        rl32eSetTargetScope(5, 10, 0.0);
        xpceScopeAcqOK(5, &RITM_test_RT1007_DW.SFunction_IWORK_h.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* Start for S-Function (BA_IS_uart_tx): '<S5>/BA-IS-UART_tx' */
  /* Level2 S-Function Block: '<S5>/BA-IS-UART_tx' (BA_IS_uart_tx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<Root>/BA-IS-UART' */

  /* Start for Atomic SubSystem: '<Root>/CA-MA-45' */
  /* Start for S-Function (CA_MA_rx): '<S6>/CA_MA_rx' */
  /* Level2 S-Function Block: '<S6>/CA_MA_rx' (CA_MA_rx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scanunpack): '<S6>/CAN Unpack' */

  /*-----------S-Function Block: <S6>/CAN Unpack -----------------*/

  /* Start for S-Function (scblock): '<S20>/S-Function' */

  /* S-Function Block: <S20>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("CA-MA-45/CAN Unpack/p1"));
        rl32eSetScope(1, 4, 2500);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 2);
        rl32eSetScope(1, 3, rl32eGetSignalNo("CA-MA-45/CAN Unpack/p1"));
        rl32eSetScope(1, 1, 1.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 3.0);
        rl32eSetTargetScope(1, 11, 0.0);
        rl32eSetTargetScope(1, 10, 0.0);
        xpceScopeAcqOK(1, &RITM_test_RT1007_DW.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for S-Function (CA_MA_status): '<S19>/CA_MA_status' */
  /* Level2 S-Function Block: '<S19>/CA_MA_status' (CA_MA_status) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[14];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (CA_MA_tx): '<S6>/CA_MA_tx' */
  /* Level2 S-Function Block: '<S6>/CA_MA_tx' (CA_MA_tx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[15];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (CA_MA_rx): '<S6>/CA_MA_rx1' */
  /* Level2 S-Function Block: '<S6>/CA_MA_rx1' (CA_MA_rx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[16];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (CA_MA_setup): '<S6>/CA_MA_setup' */
  /* Level2 S-Function Block: '<S6>/CA_MA_setup' (CA_MA_setup) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[17];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<Root>/CA-MA-45' */

  /* Start for Atomic SubSystem: '<Root>/RS-232' */
  /* Start for S-Function (xpcinterrupt): '<S24>/IRQ Source' incorporates:
   *  SubSystem: '<S24>/RS232 ISR'
   */
  RITM_test__RS232ISR_k_Start();

  /* Start for S-Function (fiforead): '<S7>/FIFO read ' */
  RITM_test_RT1007_DW.FIFOread_IWORK[0] = 1024;/* Max to read */
  RITM_test_RT1007_DW.FIFOread_IWORK[1] = 1;/* Min to read */
  RITM_test_RT1007_DW.FIFOread_IWORK[2] = 1;/* Use delimiter? */
  RITM_test_RT1007_DW.FIFOread_IWORK[3] = 13;/* delimiter */
  RITM_test_RT1007_DW.FIFOread_IWORK[4] = 6;/* FIFO type */

  /* Input pointer(s) */
  RITM_test_RT1007_DW.FIFOread_PWORK[0] = &RITM_test_RT1007_B.RateTransition1;
  RITM_test_RT1007_DW.FIFOread_PWORK[1] = NULL;
  RITM_test_RT1007_DW.FIFOread_PWORK[2] = NULL;

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOread_PWORK[3] = &RITM_test_RT1007_B.FIFOread[0];
  RITM_test_RT1007_DW.FIFOread_PWORK[4] = NULL;

  /* Start for S-Function (asciidecode): '<S7>/ASCII Decode ' */
  /* Level2 S-Function Block: '<S7>/ASCII Decode ' (asciidecode) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[18];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S25>/S-Function' */

  /* S-Function Block: <S25>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("RS-232/ASCII Decode "));
        rl32eSetScope(3, 4, 2500);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("RS-232/ASCII Decode "));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 3.0);
        rl32eSetTargetScope(3, 11, 0.0);
        rl32eSetTargetScope(3, 10, 0.0);
        xpceScopeAcqOK(3, &RITM_test_RT1007_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (fifowrite): '<S24>/FIFO write 1' */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK[0] = 1024;/* fifo size */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK[1] = 6;/* fifo type */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK[2] = 1;/* inport width */

  /* allocate memory for FIFO */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK[0] = malloc(4 * (1024 + 3));
  if (RITM_test_RT1007_DW.FIFOwrite1_PWORK[0] == NULL) {
    rtmSetErrorStatus(RITM_test_RT1007_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK[1] = ((uint8_T*) &RITM_test_RT1007_U8GND);

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK[2] = &RITM_test_RT1007_B.FIFOwrite1_o1;
  RITM_test_RT1007_DW.FIFOwrite1_PWORK[3] = &RITM_test_RT1007_B.FIFOwrite1_o2;

  {
    /* Initialize the fifo */
    int *fifo = RITM_test_RT1007_DW.FIFOwrite1_PWORK[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &RITM_test_RT1007_B.FIFOwrite1_o1;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (fifowrite): '<S24>/FIFO write 2' */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK[0] = 1024;/* fifo size */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK[1] = 6;/* fifo type */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK[2] = 1;/* inport width */

  /* allocate memory for FIFO */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK[0] = malloc(4 * (1024 + 3));
  if (RITM_test_RT1007_DW.FIFOwrite2_PWORK[0] == NULL) {
    rtmSetErrorStatus(RITM_test_RT1007_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK[1] = ((uint8_T*) &RITM_test_RT1007_U8GND);

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK[2] = &RITM_test_RT1007_B.FIFOwrite2_o1;
  RITM_test_RT1007_DW.FIFOwrite2_PWORK[3] = &RITM_test_RT1007_B.FIFOwrite2_o2;

  {
    /* Initialize the fifo */
    int *fifo = RITM_test_RT1007_DW.FIFOwrite2_PWORK[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &RITM_test_RT1007_B.FIFOwrite2_o1;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (sersetupbase): '<S24>/Setup1' */
  /* Level2 S-Function Block: '<S24>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[19];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sersetupbase): '<S24>/Setup2' */
  /* Level2 S-Function Block: '<S24>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[20];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (asciiencode): '<S7>/ASCII Encode ' */
  /* Level2 S-Function Block: '<S7>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[21];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (fifowrite): '<S23>/FIFO write 1' */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK_f[0] = 1024;/* fifo size */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK_f[1] = 6;/* fifo type */
  RITM_test_RT1007_DW.FIFOwrite1_IWORK_f[2] = 128;/* inport width */

  /* allocate memory for FIFO */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[0] = malloc(4 * (1024 + 3));
  if (RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[0] == NULL) {
    rtmSetErrorStatus(RITM_test_RT1007_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[1] = &RITM_test_RT1007_B.ASCIIEncode[0];

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[2] =
    &RITM_test_RT1007_B.FIFOwrite1_o1_o;
  RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[3] =
    &RITM_test_RT1007_B.FIFOwrite1_o2_b;

  {
    /* Initialize the fifo */
    int *fifo = RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &RITM_test_RT1007_B.FIFOwrite1_o1_o;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (fifowrite): '<S23>/FIFO write 2' */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK_n[0] = 1024;/* fifo size */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK_n[1] = 6;/* fifo type */
  RITM_test_RT1007_DW.FIFOwrite2_IWORK_n[2] = 1;/* inport width */

  /* allocate memory for FIFO */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[0] = malloc(4 * (1024 + 3));
  if (RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[0] == NULL) {
    rtmSetErrorStatus(RITM_test_RT1007_M, "Error allocating memory");
    return;
  }

  /* Input pointer */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[1] = ((uint8_T*)
    &RITM_test_RT1007_U8GND);

  /* Output pointer(s) */
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[2] =
    &RITM_test_RT1007_B.FIFOwrite2_o1_f;
  RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[3] =
    &RITM_test_RT1007_B.FIFOwrite2_o2_o;

  {
    /* Initialize the fifo */
    int *fifo = RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[0];
    memset(fifo, 0, 4 * (1024 + 3));
    serialfifoptr *oPtr = &RITM_test_RT1007_B.FIFOwrite2_o1_f;
    fifo[0] = 1024;
    oPtr->ptrlow = (uint32_T)fifo;
    oPtr->ptrhigh = 0;
    oPtr->token = (int)'FiFo';
  }

  /* Start for S-Function (xpcinterrupt): '<S23>/IRQ Source' incorporates:
   *  SubSystem: '<S23>/RS232 ISR'
   */
  RITM_test_RT_RS232ISR_Start();

  /* Start for S-Function (sersetupbase): '<S23>/Setup1' */
  /* Level2 S-Function Block: '<S23>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[22];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sersetupbase): '<S23>/Setup2' */
  /* Level2 S-Function Block: '<S23>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[23];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<Root>/RS-232' */

  /* Start for Atomic SubSystem: '<Root>/BA-IS-I2C' */
  /* Start for S-Function (BA_IS_i2c_read): '<S2>/BA-IS-I2C_read' */
  /* Level2 S-Function Block: '<S2>/BA-IS-I2C_read' (BA_IS_i2c_read) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S9>/S-Function' */

  /* S-Function Block: <S9>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(8)) == 0) {
      if ((i = rl32eDefScope(8,2)) != 0) {
        printf("Error creating scope 8\n");
      } else {
        rl32eAddSignal(8, rl32eGetSignalNo("BA-IS-I2C/BA-IS-I2C_read/p1/s1"));
        rl32eAddSignal(8, rl32eGetSignalNo("BA-IS-I2C/BA-IS-I2C_read/p1/s2"));
        rl32eAddSignal(8, rl32eGetSignalNo("BA-IS-I2C/BA-IS-I2C_read/p1/s3"));
        rl32eAddSignal(8, rl32eGetSignalNo("BA-IS-I2C/BA-IS-I2C_read/p1/s4"));
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo(
          "BA-IS-I2C/BA-IS-I2C_read/p1/s1"),"%15.6f");
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo(
          "BA-IS-I2C/BA-IS-I2C_read/p1/s2"),"%15.6f");
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo(
          "BA-IS-I2C/BA-IS-I2C_read/p1/s3"),"%15.6f");
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo(
          "BA-IS-I2C/BA-IS-I2C_read/p1/s4"),"%15.6f");
        rl32eSetScope(8, 4, 100);
        rl32eSetScope(8, 5, 0);
        rl32eSetScope(8, 6, 1);
        rl32eSetScope(8, 0, 0);
        rl32eSetScope(8, 3, rl32eGetSignalNo("BA-IS-I2C/BA-IS-I2C_read/p1/s1"));
        rl32eSetScope(8, 1, 0.0);
        rl32eSetScope(8, 2, 0);
        rl32eSetScope(8, 9, 0);
        rl32eSetTargetScope(8, 1, 0.0);
        rl32eSetTargetScope(8, 11, 0.0);
        rl32eSetTargetScope(8, 10, 0.0);
        xpceScopeAcqOK(8, &RITM_test_RT1007_DW.SFunction_IWORK_l.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(8);
    }
  }

  /* End of Start for SubSystem: '<Root>/BA-IS-I2C' */

  /* Start for Atomic SubSystem: '<Root>/BA-IS-SPI' */
  /* Start for S-Function (BA_IS_spi): '<S4>/BA-IS-SPI1' */
  /* Level2 S-Function Block: '<S4>/BA-IS-SPI1' (BA_IS_spi) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S12>/S-Function' */

  /* S-Function Block: <S12>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(6)) == 0) {
      if ((i = rl32eDefScope(6,2)) != 0) {
        printf("Error creating scope 6\n");
      } else {
        rl32eAddSignal(6, rl32eGetSignalNo("BA-IS-SPI/BA-IS-SPI1/s1"));
        rl32eAddSignal(6, rl32eGetSignalNo("BA-IS-SPI/BA-IS-SPI1/s2"));
        rl32eAddSignal(6, rl32eGetSignalNo("BA-IS-SPI/BA-IS-SPI1/s3"));
        rl32eAddSignal(6, rl32eGetSignalNo("BA-IS-SPI/BA-IS-SPI1/s4"));
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("BA-IS-SPI/BA-IS-SPI1/s1"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("BA-IS-SPI/BA-IS-SPI1/s2"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("BA-IS-SPI/BA-IS-SPI1/s3"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("BA-IS-SPI/BA-IS-SPI1/s4"),
          "%15.6f");
        rl32eSetScope(6, 4, 100);
        rl32eSetScope(6, 5, 0);
        rl32eSetScope(6, 6, 1);
        rl32eSetScope(6, 0, 0);
        rl32eSetScope(6, 3, rl32eGetSignalNo("BA-IS-SPI/BA-IS-SPI1/s1"));
        rl32eSetScope(6, 1, 0.0);
        rl32eSetScope(6, 2, 0);
        rl32eSetScope(6, 9, 0);
        rl32eSetTargetScope(6, 1, 0.0);
        rl32eSetTargetScope(6, 11, 0.0);
        rl32eSetTargetScope(6, 10, 0.0);
        xpceScopeAcqOK(6, &RITM_test_RT1007_DW.SFunction_IWORK_c.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(6);
    }
  }

  /* End of Start for SubSystem: '<Root>/BA-IS-SPI' */

  /* user code (Start function Trailer) */
  {
    uint8_T irq = 3;

    /* For an ISA board, save the given address in the struct. */
    xpcDev_1.BaseAddress[0] = 0;

    /* connect ISR system: IRQ 3 */
    if (xpceRegisterISR( irq, xPCISR1,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        0,
                        &xpcDev_1) == -1) {
      static uint8_T ermsg[100];
      sprintf( ermsg, "ISR registration failed for Interrupt %d ISA board at 0.",
              irq );
      rtmSetErrorStatus(RITM_test_RT1007_M, ermsg);
      return;
    }
  }

  xpcOutpB( 0xA0, 0x20 );
  xpcOutpB( 0x20, 0x20 );

  {
    uint8_T irq = 4;

    /* For an ISA board, save the given address in the struct. */
    xpcDev_2.BaseAddress[0] = 0;

    /* connect ISR system: IRQ 4 */
    if (xpceRegisterISR( irq, xPCISR2,
                        NULL,
                        NULL,
                        NULL,
                        NULL,
                        0,
                        &xpcDev_2) == -1) {
      static uint8_T ermsg[100];
      sprintf( ermsg, "ISR registration failed for Interrupt %d ISA board at 0.",
              irq );
      rtmSetErrorStatus(RITM_test_RT1007_M, ermsg);
      return;
    }
  }

  rtw_xpc_mutex_create(&RITM_test_RT1007_M->Timing.semIdForTask3);
  rtw_xpc_mutex_create(&RITM_test_RT1007_M->Timing.semIdForTask4);

  /* SystemInitialize for Atomic SubSystem: '<Root>/BA-IS-GPIO' */
  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Twice a second' */
  RITM_test_RT1007_DW.clockTickCounter = 0;

  /* End of SystemInitialize for SubSystem: '<Root>/BA-IS-GPIO' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/BA-IS-SPI' */
  /* InitializeConditions for UnitDelay: '<S11>/Output' */
  RITM_test_RT1007_DW.Output_DSTATE_e =
    RITM_test_RT1007_P.Output_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<Root>/BA-IS-SPI' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/BA-IS-UART' */
  /* InitializeConditions for UnitDelay: '<S15>/Output' */
  RITM_test_RT1007_DW.Output_DSTATE =
    RITM_test_RT1007_P.Output_InitialCondition_b;

  /* End of SystemInitialize for SubSystem: '<Root>/BA-IS-UART' */

  /* Enable for Atomic SubSystem: '<Root>/CA-MA-45' */
  /* Enable for Sin: '<S6>/Sine Wave' */
  RITM_test_RT1007_DW.systemEnable_i = 1;

  /* End of Enable for SubSystem: '<Root>/CA-MA-45' */

  /* Enable for Atomic SubSystem: '<Root>/RS-232' */
  /* Enable for Sin: '<S7>/Sine Wave' */
  RITM_test_RT1007_DW.systemEnable = 1;

  /* End of Enable for SubSystem: '<Root>/RS-232' */
}

/* Model terminate function */
static void RITM_test_RT1007_terminate(void)
{
  /* user code (Terminate function Header) */

  /* disable interrupt for IRQ 3 */
  xpceDeRegisterISR( &xpcDev_1 );

  /* disable interrupt for IRQ 4 */
  xpceDeRegisterISR( &xpcDev_2 );
  rtw_xpc_mutex_delete(RITM_test_RT1007_M->Timing.semIdForTask3);
  rtw_xpc_mutex_delete(RITM_test_RT1007_M->Timing.semIdForTask4);

  /* Terminate for Atomic SubSystem: '<Root>/BA-IS-GPIO' */
  /* Terminate for S-Function (BA_IS_gpio_di): '<S1>/BA_IS_gpio_di' */
  /* Level2 S-Function Block: '<S1>/BA_IS_gpio_di' (BA_IS_gpio_di) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (BA_IS_gpio_do): '<S1>/BA_IS_gpio_do' */
  /* Level2 S-Function Block: '<S1>/BA_IS_gpio_do' (BA_IS_gpio_do) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/BA-IS-GPIO' */

  /* Terminate for Atomic SubSystem: '<Root>/BA-IS-PWM-CAP' */
  /* Terminate for S-Function (BA_IS_cap): '<S3>/BA-IS-CAP' */
  /* Level2 S-Function Block: '<S3>/BA-IS-CAP' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (BA_IS_cap): '<S3>/BA-IS-CAP1' */
  /* Level2 S-Function Block: '<S3>/BA-IS-CAP1' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (BA_IS_cap): '<S3>/BA-IS-CAP2' */
  /* Level2 S-Function Block: '<S3>/BA-IS-CAP2' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (BA_IS_cap): '<S3>/BA-IS-CAP3' */
  /* Level2 S-Function Block: '<S3>/BA-IS-CAP3' (BA_IS_cap) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (BA_IS_pwm): '<S3>/BA-IS-PWM' */
  /* Level2 S-Function Block: '<S3>/BA-IS-PWM' (BA_IS_pwm) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (BA_IS_pwm): '<S3>/BA-IS-PWM1' */
  /* Level2 S-Function Block: '<S3>/BA-IS-PWM1' (BA_IS_pwm) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/BA-IS-PWM-CAP' */

  /* Terminate for Atomic SubSystem: '<Root>/BA-IS-UART' */
  /* Terminate for S-Function (BA_IS_uart_setup): '<S5>/BA-IS-UART_setup' */
  /* Level2 S-Function Block: '<S5>/BA-IS-UART_setup' (BA_IS_uart_setup) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (BA_IS_uart_rx): '<S5>/BA-IS-UART_rx' */
  /* Level2 S-Function Block: '<S5>/BA-IS-UART_rx' (BA_IS_uart_rx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (BA_IS_uart_tx): '<S5>/BA-IS-UART_tx' */
  /* Level2 S-Function Block: '<S5>/BA-IS-UART_tx' (BA_IS_uart_tx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/BA-IS-UART' */

  /* Terminate for Atomic SubSystem: '<Root>/CA-MA-45' */
  /* Terminate for S-Function (CA_MA_rx): '<S6>/CA_MA_rx' */
  /* Level2 S-Function Block: '<S6>/CA_MA_rx' (CA_MA_rx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (CA_MA_status): '<S19>/CA_MA_status' */
  /* Level2 S-Function Block: '<S19>/CA_MA_status' (CA_MA_status) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (CA_MA_tx): '<S6>/CA_MA_tx' */
  /* Level2 S-Function Block: '<S6>/CA_MA_tx' (CA_MA_tx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (CA_MA_rx): '<S6>/CA_MA_rx1' */
  /* Level2 S-Function Block: '<S6>/CA_MA_rx1' (CA_MA_rx) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[16];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (CA_MA_setup): '<S6>/CA_MA_setup' */
  /* Level2 S-Function Block: '<S6>/CA_MA_setup' (CA_MA_setup) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[17];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/CA-MA-45' */

  /* Terminate for Atomic SubSystem: '<Root>/RS-232' */
  /* Terminate for S-Function (xpcinterrupt): '<S24>/IRQ Source' incorporates:
   *  SubSystem: '<S24>/RS232 ISR'
   */
  RITM_test_R_RS232ISR_j_Term();

  /* End of Terminate for S-Function (xpcinterrupt): '<S24>/IRQ Source' */

  /* Terminate for S-Function (asciidecode): '<S7>/ASCII Decode ' */
  /* Level2 S-Function Block: '<S7>/ASCII Decode ' (asciidecode) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[18];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (fifowrite): '<S24>/FIFO write 1' */

  /* Free fifo memory */
  if (RITM_test_RT1007_DW.FIFOwrite1_PWORK[0]) {
    free(RITM_test_RT1007_DW.FIFOwrite1_PWORK[0]);
  }

  /* Terminate for S-Function (fifowrite): '<S24>/FIFO write 2' */

  /* Free fifo memory */
  if (RITM_test_RT1007_DW.FIFOwrite2_PWORK[0]) {
    free(RITM_test_RT1007_DW.FIFOwrite2_PWORK[0]);
  }

  /* Terminate for S-Function (sersetupbase): '<S24>/Setup1' */
  /* Level2 S-Function Block: '<S24>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[19];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sersetupbase): '<S24>/Setup2' */
  /* Level2 S-Function Block: '<S24>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[20];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (asciiencode): '<S7>/ASCII Encode ' */
  /* Level2 S-Function Block: '<S7>/ASCII Encode ' (asciiencode) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[21];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (fifowrite): '<S23>/FIFO write 1' */

  /* Free fifo memory */
  if (RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[0]) {
    free(RITM_test_RT1007_DW.FIFOwrite1_PWORK_p[0]);
  }

  /* Terminate for S-Function (fifowrite): '<S23>/FIFO write 2' */

  /* Free fifo memory */
  if (RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[0]) {
    free(RITM_test_RT1007_DW.FIFOwrite2_PWORK_e[0]);
  }

  /* Terminate for S-Function (xpcinterrupt): '<S23>/IRQ Source' incorporates:
   *  SubSystem: '<S23>/RS232 ISR'
   */
  RITM_test_RT1_RS232ISR_Term();

  /* End of Terminate for S-Function (xpcinterrupt): '<S23>/IRQ Source' */

  /* Terminate for S-Function (sersetupbase): '<S23>/Setup1' */
  /* Level2 S-Function Block: '<S23>/Setup1' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[22];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sersetupbase): '<S23>/Setup2' */
  /* Level2 S-Function Block: '<S23>/Setup2' (sersetupbase) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[23];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/RS-232' */

  /* Terminate for Atomic SubSystem: '<Root>/BA-IS-I2C' */
  /* Terminate for S-Function (BA_IS_i2c_read): '<S2>/BA-IS-I2C_read' */
  /* Level2 S-Function Block: '<S2>/BA-IS-I2C_read' (BA_IS_i2c_read) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/BA-IS-I2C' */

  /* Terminate for Atomic SubSystem: '<Root>/BA-IS-SPI' */
  /* Terminate for S-Function (BA_IS_spi): '<S4>/BA-IS-SPI1' */
  /* Level2 S-Function Block: '<S4>/BA-IS-SPI1' (BA_IS_spi) */
  {
    SimStruct *rts = RITM_test_RT1007_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<Root>/BA-IS-SPI' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  RITM_test_RT1007_output(tid);
}

void MdlUpdate(int_T tid)
{
  RITM_test_RT1007_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  RITM_test_RT1007_initialize();
}

void MdlTerminate(void)
{
  RITM_test_RT1007_terminate();
}

/* Registration function */
RT_MODEL_RITM_test_RT1007_T *RITM_test_RT1007(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)RITM_test_RT1007_M, 0,
                sizeof(RT_MODEL_RITM_test_RT1007_T));
  rtsiSetSolverName(&RITM_test_RT1007_M->solverInfo,"FixedStepDiscrete");
  RITM_test_RT1007_M->solverInfoPtr = (&RITM_test_RT1007_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = RITM_test_RT1007_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    RITM_test_RT1007_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RITM_test_RT1007_M->Timing.sampleTimes =
      (&RITM_test_RT1007_M->Timing.sampleTimesArray[0]);
    RITM_test_RT1007_M->Timing.offsetTimes =
      (&RITM_test_RT1007_M->Timing.offsetTimesArray[0]);

    /* task periods */
    RITM_test_RT1007_M->Timing.sampleTimes[0] = (0.001);
    RITM_test_RT1007_M->Timing.sampleTimes[1] = (0.01);
    RITM_test_RT1007_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    RITM_test_RT1007_M->Timing.offsetTimes[0] = (0.0);
    RITM_test_RT1007_M->Timing.offsetTimes[1] = (0.0);
    RITM_test_RT1007_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(RITM_test_RT1007_M, &RITM_test_RT1007_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RITM_test_RT1007_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      RITM_test_RT1007_M->Timing.perTaskSampleHitsArray;
    RITM_test_RT1007_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    RITM_test_RT1007_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RITM_test_RT1007_M, -1);
  RITM_test_RT1007_M->Timing.stepSize0 = 0.001;
  RITM_test_RT1007_M->Timing.stepSize1 = 0.01;
  RITM_test_RT1007_M->Timing.stepSize2 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    RITM_test_RT1007_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(RITM_test_RT1007_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(RITM_test_RT1007_M->rtwLogInfo, (NULL));
    rtliSetLogT(RITM_test_RT1007_M->rtwLogInfo, "tout");
    rtliSetLogX(RITM_test_RT1007_M->rtwLogInfo, "");
    rtliSetLogXFinal(RITM_test_RT1007_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(RITM_test_RT1007_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(RITM_test_RT1007_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(RITM_test_RT1007_M->rtwLogInfo, 0);
    rtliSetLogDecimation(RITM_test_RT1007_M->rtwLogInfo, 1);
    rtliSetLogY(RITM_test_RT1007_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(RITM_test_RT1007_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(RITM_test_RT1007_M->rtwLogInfo, (NULL));
  }

  RITM_test_RT1007_M->solverInfoPtr = (&RITM_test_RT1007_M->solverInfo);
  RITM_test_RT1007_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&RITM_test_RT1007_M->solverInfo, 0.001);
  rtsiSetSolverMode(&RITM_test_RT1007_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  RITM_test_RT1007_M->blockIO = ((void *) &RITM_test_RT1007_B);
  (void) memset(((void *) &RITM_test_RT1007_B), 0,
                sizeof(B_RITM_test_RT1007_T));

  {
    RITM_test_RT1007_B.CA_MA_rx_o2 = CAN_DATATYPE_GROUND;
    RITM_test_RT1007_B.CANPack = CAN_DATATYPE_GROUND;
    RITM_test_RT1007_B.CA_MA_rx1_o2 = CAN_DATATYPE_GROUND;
    RITM_test_RT1007_B.RateTransition1 = serialfifoground;
    RITM_test_RT1007_B.FIFOwrite1_o1 = serialfifoground;
    RITM_test_RT1007_B.FIFOwrite2_o1 = serialfifoground;
    RITM_test_RT1007_B.RateTransition3 = serialfifoground;
    RITM_test_RT1007_B.FIFOwrite1_o1_o = serialfifoground;
    RITM_test_RT1007_B.FIFOwrite2_o1_f = serialfifoground;
    RITM_test_RT1007_B.RateTransition1_j = serialfifoground;
    RITM_test_RT1007_B.RateTransition3_e = serialfifoground;
    RITM_test_RT1007_B.RateTransition = serialfifoground;
    RITM_test_RT1007_B.RateTransition2 = serialfifoground;
    RITM_test_RT1007_B.RateTransition_d = serialfifoground;
    RITM_test_RT1007_B.RateTransition2_p = serialfifoground;
    RITM_test_RT1007_B.FIFOwrite2 = serialfifoground;
    RITM_test_RT1007_B.FIFOwrite1 = serialfifoground;
    RITM_test_RT1007_B.FIFOwrite2_e = serialfifoground;
    RITM_test_RT1007_B.FIFOwrite1_e = serialfifoground;
  }

  /* parameters */
  RITM_test_RT1007_M->defaultParam = ((real_T *)&RITM_test_RT1007_P);

  /* states (dwork) */
  RITM_test_RT1007_M->dwork = ((void *) &RITM_test_RT1007_DW);
  (void) memset((void *)&RITM_test_RT1007_DW, 0,
                sizeof(DW_RITM_test_RT1007_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  RITM_test_RT1007_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &RITM_test_RT1007_M->NonInlinedSFcns.sfcnInfo;
    RITM_test_RT1007_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(RITM_test_RT1007_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &RITM_test_RT1007_M->Sizes.numSampTimes);
    RITM_test_RT1007_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (RITM_test_RT1007_M)[0]);
    RITM_test_RT1007_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (RITM_test_RT1007_M)[1]);
    RITM_test_RT1007_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr
      (RITM_test_RT1007_M)[2]);
    RITM_test_RT1007_M->NonInlinedSFcns.taskTimePtrs[3] = &(rtmGetTPtr
      (RITM_test_RT1007_M)[3]);
    RITM_test_RT1007_M->NonInlinedSFcns.taskTimePtrs[4] = &(rtmGetTPtr
      (RITM_test_RT1007_M)[4]);
    rtssSetTPtrPtr(sfcnInfo,RITM_test_RT1007_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(RITM_test_RT1007_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(RITM_test_RT1007_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (RITM_test_RT1007_M));
    rtssSetStepSizePtr(sfcnInfo, &RITM_test_RT1007_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(RITM_test_RT1007_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &RITM_test_RT1007_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &RITM_test_RT1007_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &RITM_test_RT1007_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &RITM_test_RT1007_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &RITM_test_RT1007_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &RITM_test_RT1007_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &RITM_test_RT1007_M->solverInfoPtr);
  }

  RITM_test_RT1007_M->Sizes.numSFcns = (24);

  /* register each child */
  {
    (void) memset((void *)&RITM_test_RT1007_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  24*sizeof(SimStruct));
    RITM_test_RT1007_M->childSfunctions =
      (&RITM_test_RT1007_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 24; i++) {
        RITM_test_RT1007_M->childSfunctions[i] =
          (&RITM_test_RT1007_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S1>/BA_IS_gpio_di (BA_IS_gpio_di) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 13);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);
        ssSetOutputPortUnit(rts, 6, 0);
        ssSetOutputPortUnit(rts, 7, 0);
        ssSetOutputPortUnit(rts, 8, 0);
        ssSetOutputPortUnit(rts, 9, 0);
        ssSetOutputPortUnit(rts, 10, 0);
        ssSetOutputPortUnit(rts, 11, 0);
        ssSetOutputPortUnit(rts, 12, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 3, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 4, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 5, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 6, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 7, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 8, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 9, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 10, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 11, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 12, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o12));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 1);
          ssSetOutputPortSignal(rts, 12, ((real_T *)
            &RITM_test_RT1007_B.BA_IS_gpio_di_o13));
        }
      }

      /* path info */
      ssSetModelName(rts, "BA_IS_gpio_di");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-GPIO/BA_IS_gpio_di");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       RITM_test_RT1007_P.BA_IS_gpio_di_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       RITM_test_RT1007_P.BA_IS_gpio_di_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       RITM_test_RT1007_P.BA_IS_gpio_di_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       RITM_test_RT1007_P.BA_IS_gpio_di_P4_Size);
      }

      /* registration */
      BA_IS_gpio_di(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortConnected(rts, 6, 0);
      _ssSetOutputPortConnected(rts, 7, 0);
      _ssSetOutputPortConnected(rts, 8, 0);
      _ssSetOutputPortConnected(rts, 9, 0);
      _ssSetOutputPortConnected(rts, 10, 0);
      _ssSetOutputPortConnected(rts, 11, 0);
      _ssSetOutputPortConnected(rts, 12, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);
      _ssSetOutputPortBeingMerged(rts, 10, 0);
      _ssSetOutputPortBeingMerged(rts, 11, 0);
      _ssSetOutputPortBeingMerged(rts, 12, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S1>/BA_IS_gpio_do (BA_IS_gpio_do) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 13);
        ssSetPortInfoForInputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        ssSetInputPortUnit(rts, 3, 0);
        ssSetInputPortUnit(rts, 4, 0);
        ssSetInputPortUnit(rts, 5, 0);
        ssSetInputPortUnit(rts, 6, 0);
        ssSetInputPortUnit(rts, 7, 0);
        ssSetInputPortUnit(rts, 8, 0);
        ssSetInputPortUnit(rts, 9, 0);
        ssSetInputPortUnit(rts, 10, 0);
        ssSetInputPortUnit(rts, 11, 0);
        ssSetInputPortUnit(rts, 12, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);
        ssSetInputPortIsContinuousQuantity(rts, 3, 0);
        ssSetInputPortIsContinuousQuantity(rts, 4, 0);
        ssSetInputPortIsContinuousQuantity(rts, 5, 0);
        ssSetInputPortIsContinuousQuantity(rts, 6, 0);
        ssSetInputPortIsContinuousQuantity(rts, 7, 0);
        ssSetInputPortIsContinuousQuantity(rts, 8, 0);
        ssSetInputPortIsContinuousQuantity(rts, 9, 0);
        ssSetInputPortIsContinuousQuantity(rts, 10, 0);
        ssSetInputPortIsContinuousQuantity(rts, 11, 0);
        ssSetInputPortIsContinuousQuantity(rts, 12, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          ssSetInputPortRequiredContiguous(rts, 2, 1);
          ssSetInputPortSignal(rts, 2, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          ssSetInputPortRequiredContiguous(rts, 3, 1);
          ssSetInputPortSignal(rts, 3, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          ssSetInputPortRequiredContiguous(rts, 4, 1);
          ssSetInputPortSignal(rts, 4, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          ssSetInputPortRequiredContiguous(rts, 5, 1);
          ssSetInputPortSignal(rts, 5, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          ssSetInputPortRequiredContiguous(rts, 6, 1);
          ssSetInputPortSignal(rts, 6, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          ssSetInputPortRequiredContiguous(rts, 7, 1);
          ssSetInputPortSignal(rts, 7, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }

        /* port 8 */
        {
          ssSetInputPortRequiredContiguous(rts, 8, 1);
          ssSetInputPortSignal(rts, 8, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 8, 1);
          ssSetInputPortWidth(rts, 8, 1);
        }

        /* port 9 */
        {
          ssSetInputPortRequiredContiguous(rts, 9, 1);
          ssSetInputPortSignal(rts, 9, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 9, 1);
          ssSetInputPortWidth(rts, 9, 1);
        }

        /* port 10 */
        {
          ssSetInputPortRequiredContiguous(rts, 10, 1);
          ssSetInputPortSignal(rts, 10, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 10, 1);
          ssSetInputPortWidth(rts, 10, 1);
        }

        /* port 11 */
        {
          ssSetInputPortRequiredContiguous(rts, 11, 1);
          ssSetInputPortSignal(rts, 11, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 11, 1);
          ssSetInputPortWidth(rts, 11, 1);
        }

        /* port 12 */
        {
          ssSetInputPortRequiredContiguous(rts, 12, 1);
          ssSetInputPortSignal(rts, 12, &RITM_test_RT1007_B.Twiceasecond);
          _ssSetInputPortNumDimensions(rts, 12, 1);
          ssSetInputPortWidth(rts, 12, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BA_IS_gpio_do");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-GPIO/BA_IS_gpio_do");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       RITM_test_RT1007_P.BA_IS_gpio_do_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       RITM_test_RT1007_P.BA_IS_gpio_do_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       RITM_test_RT1007_P.BA_IS_gpio_do_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       RITM_test_RT1007_P.BA_IS_gpio_do_P4_Size);
      }

      /* registration */
      BA_IS_gpio_do(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 1);
      _ssSetInputPortConnected(rts, 5, 1);
      _ssSetInputPortConnected(rts, 6, 1);
      _ssSetInputPortConnected(rts, 7, 1);
      _ssSetInputPortConnected(rts, 8, 1);
      _ssSetInputPortConnected(rts, 9, 1);
      _ssSetInputPortConnected(rts, 10, 1);
      _ssSetInputPortConnected(rts, 11, 1);
      _ssSetInputPortConnected(rts, 12, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
      ssSetInputPortBufferDstPort(rts, 6, -1);
      ssSetInputPortBufferDstPort(rts, 7, -1);
      ssSetInputPortBufferDstPort(rts, 8, -1);
      ssSetInputPortBufferDstPort(rts, 9, -1);
      ssSetInputPortBufferDstPort(rts, 10, -1);
      ssSetInputPortBufferDstPort(rts, 11, -1);
      ssSetInputPortBufferDstPort(rts, 12, -1);
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S2>/BA-IS-I2C_read (BA_IS_i2c_read) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 4);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            RITM_test_RT1007_B.BAISI2C_read_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &RITM_test_RT1007_B.BAISI2C_read_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-I2C_read");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-I2C/BA-IS-I2C_read");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISI2C_read_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISI2C_read_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISI2C_read_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.BAISI2C_read_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)RITM_test_RT1007_P.BAISI2C_read_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)RITM_test_RT1007_P.BAISI2C_read_P6_Size);
      }

      /* registration */
      BA_IS_i2c_read(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.1);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S3>/BA-IS-CAP (BA_IS_cap) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &RITM_test_RT1007_B.BAISCAP_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &RITM_test_RT1007_B.BAISCAP_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-CAP");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-PWM-CAP/BA-IS-CAP");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISCAP_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISCAP_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISCAP_P3_Size);
      }

      /* registration */
      BA_IS_cap(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S3>/BA-IS-CAP1 (BA_IS_cap) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &RITM_test_RT1007_B.BAISCAP1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &RITM_test_RT1007_B.BAISCAP1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-CAP1");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-PWM-CAP/BA-IS-CAP1");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISCAP1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISCAP1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISCAP1_P3_Size);
      }

      /* registration */
      BA_IS_cap(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S3>/BA-IS-CAP2 (BA_IS_cap) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &RITM_test_RT1007_B.BAISCAP2_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &RITM_test_RT1007_B.BAISCAP2_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-CAP2");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-PWM-CAP/BA-IS-CAP2");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISCAP2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISCAP2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISCAP2_P3_Size);
      }

      /* registration */
      BA_IS_cap(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S3>/BA-IS-CAP3 (BA_IS_cap) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &RITM_test_RT1007_B.BAISCAP3_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &RITM_test_RT1007_B.BAISCAP3_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-CAP3");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-PWM-CAP/BA-IS-CAP3");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISCAP3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISCAP3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISCAP3_P3_Size);
      }

      /* registration */
      BA_IS_cap(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S3>/BA-IS-PWM (BA_IS_pwm) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RITM_test_RT1007_B.Constant1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &RITM_test_RT1007_B.Constant8);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-PWM");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-PWM-CAP/BA-IS-PWM");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISPWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISPWM_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISPWM_P3_Size);
      }

      /* registration */
      BA_IS_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S3>/BA-IS-PWM1 (BA_IS_pwm) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[8]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[8]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[8]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn8.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn8.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RITM_test_RT1007_B.Constant2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &RITM_test_RT1007_B.Constant3);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-PWM1");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-PWM-CAP/BA-IS-PWM1");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISPWM1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISPWM1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISPWM1_P3_Size);
      }

      /* registration */
      BA_IS_pwm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S4>/BA-IS-SPI1 (BA_IS_spi) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[9]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[9]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2[9]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, RITM_test_RT1007_B.ManualSwitch_g);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 4);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) RITM_test_RT1007_B.BAISSPI1));
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-SPI1");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-SPI/BA-IS-SPI1");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISSPI1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISSPI1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISSPI1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.BAISSPI1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)RITM_test_RT1007_P.BAISSPI1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)RITM_test_RT1007_P.BAISSPI1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)RITM_test_RT1007_P.BAISSPI1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)RITM_test_RT1007_P.BAISSPI1_P8_Size);
      }

      /* registration */
      BA_IS_spi(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.1);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S5>/BA-IS-UART_setup (BA_IS_uart_setup) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[10]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[10]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[10]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [10]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[10]);
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-UART_setup");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-UART/BA-IS-UART_setup");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       RITM_test_RT1007_P.BAISUART_setup_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       RITM_test_RT1007_P.BAISUART_setup_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       RITM_test_RT1007_P.BAISUART_setup_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       RITM_test_RT1007_P.BAISUART_setup_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       RITM_test_RT1007_P.BAISUART_setup_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       RITM_test_RT1007_P.BAISUART_setup_P6_Size);
      }

      /* registration */
      BA_IS_uart_setup(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S5>/BA-IS-UART_rx (BA_IS_uart_rx) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[11]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[11]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[11]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [11]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[11]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn11.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn11.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 16);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            RITM_test_RT1007_B.BAISUART_rx_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &RITM_test_RT1007_B.BAISUART_rx_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint32_T *)
            &RITM_test_RT1007_B.BAISUART_rx_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-UART_rx");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-UART/BA-IS-UART_rx");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISUART_rx_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISUART_rx_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISUART_rx_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.BAISUART_rx_P4_Size);
      }

      /* registration */
      BA_IS_uart_rx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S5>/BA-IS-UART_tx (BA_IS_uart_tx) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[12]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[12]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[12]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [12]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn12.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn12.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, RITM_test_RT1007_B.ManualSwitch);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, (uint32_T*)&RITM_test_RT1007_ConstB.Width);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BA-IS-UART_tx");
      ssSetPath(rts, "RITM_test_RT1007/BA-IS-UART/BA-IS-UART_tx");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.BAISUART_tx_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.BAISUART_tx_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.BAISUART_tx_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.BAISUART_tx_P4_Size);
      }

      /* registration */
      BA_IS_uart_tx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.1);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 4);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S6>/CA_MA_rx (CA_MA_rx) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[13]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[13]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[13]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[13]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [13]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[13]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn13.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn13.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn13.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &RITM_test_RT1007_B.CA_MA_rx_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((CAN_DATATYPE *)
            &RITM_test_RT1007_B.CA_MA_rx_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "CA_MA_rx");
      ssSetPath(rts, "RITM_test_RT1007/CA-MA-45/CA_MA_rx");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.CA_MA_rx_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.CA_MA_rx_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.CA_MA_rx_P3_Size);
      }

      /* registration */
      CA_MA_rx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S19>/CA_MA_status (CA_MA_status) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[14]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[14]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[14]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[14]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [14]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[14]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn14.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn14.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn14.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            RITM_test_RT1007_B.CA_MA_status_e));
        }
      }

      /* path info */
      ssSetModelName(rts, "CA_MA_status");
      ssSetPath(rts, "RITM_test_RT1007/CA-MA-45/CA_MA_status/CA_MA_status");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.CA_MA_status_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.CA_MA_status_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.CA_MA_status_P3_Size);
      }

      /* registration */
      CA_MA_status(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S6>/CA_MA_tx (CA_MA_tx) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[15]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[15]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[15]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[15]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [15]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[15]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RITM_test_RT1007_B.CANPack);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &RITM_test_RT1007_B.CA_MA_tx_p));
        }
      }

      /* path info */
      ssSetModelName(rts, "CA_MA_tx");
      ssSetPath(rts, "RITM_test_RT1007/CA-MA-45/CA_MA_tx");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.CA_MA_tx_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.CA_MA_tx_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.CA_MA_tx_P3_Size);
      }

      /* registration */
      CA_MA_tx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S6>/CA_MA_rx1 (CA_MA_rx) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[16];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[16]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[16]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[16]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[16]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [16]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[16]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn16.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn16.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn16.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &RITM_test_RT1007_B.CA_MA_rx1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((CAN_DATATYPE *)
            &RITM_test_RT1007_B.CA_MA_rx1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "CA_MA_rx1");
      ssSetPath(rts, "RITM_test_RT1007/CA-MA-45/CA_MA_rx1");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn16.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.CA_MA_rx1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.CA_MA_rx1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.CA_MA_rx1_P3_Size);
      }

      /* registration */
      CA_MA_rx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S6>/CA_MA_setup (CA_MA_setup) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[17];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn17.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn17.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn17.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[17]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[17]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[17]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[17]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[17]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [17]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[17]);
      }

      /* path info */
      ssSetModelName(rts, "CA_MA_setup");
      ssSetPath(rts, "RITM_test_RT1007/CA-MA-45/CA_MA_setup");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn17.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.CA_MA_setup_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.CA_MA_setup_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.CA_MA_setup_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.CA_MA_setup_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)RITM_test_RT1007_P.CA_MA_setup_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)RITM_test_RT1007_P.CA_MA_setup_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)RITM_test_RT1007_P.CA_MA_setup_P7_Size);
      }

      /* registration */
      CA_MA_setup(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S7>/ASCII Decode  (asciidecode) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[18];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[18]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[18]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[18]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[18]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[18]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [18]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[18]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, RITM_test_RT1007_B.FIFOread);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1025);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &RITM_test_RT1007_B.ASCIIDecode));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Decode ");
      ssSetPath(rts, "RITM_test_RT1007/RS-232/ASCII Decode ");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.ASCIIDecode_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.ASCIIDecode_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.ASCIIDecode_P3_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &RITM_test_RT1007_DW.ASCIIDecode_IWORK[0]);
      ssSetPWork(rts, (void **) &RITM_test_RT1007_DW.ASCIIDecode_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn18.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RITM_test_RT1007_DW.ASCIIDecode_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &RITM_test_RT1007_DW.ASCIIDecode_PWORK[0]);
      }

      /* registration */
      asciidecode(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1025);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S24>/Setup1 (sersetupbase) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[19];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn19.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn19.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn19.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[19]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[19]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[19]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[19]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[19]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [19]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[19]);
      }

      /* path info */
      ssSetModelName(rts, "Setup1");
      ssSetPath(rts, "RITM_test_RT1007/RS-232/Baseboard Serial F1/Setup1");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn19.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.Setup1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.Setup1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.Setup1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.Setup1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)RITM_test_RT1007_P.Setup1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)RITM_test_RT1007_P.Setup1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)RITM_test_RT1007_P.Setup1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)RITM_test_RT1007_P.Setup1_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &RITM_test_RT1007_DW.Setup1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn19.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn19.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RITM_test_RT1007_DW.Setup1_IWORK[0]);
      }

      /* registration */
      sersetupbase(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S24>/Setup2 (sersetupbase) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[20];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn20.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn20.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn20.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[20]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[20]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[20]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[20]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[20]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [20]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[20]);
      }

      /* path info */
      ssSetModelName(rts, "Setup2");
      ssSetPath(rts, "RITM_test_RT1007/RS-232/Baseboard Serial F1/Setup2");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn20.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.Setup2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.Setup2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.Setup2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.Setup2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)RITM_test_RT1007_P.Setup2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)RITM_test_RT1007_P.Setup2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)RITM_test_RT1007_P.Setup2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)RITM_test_RT1007_P.Setup2_P8_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &RITM_test_RT1007_DW.Setup2_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn20.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn20.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RITM_test_RT1007_DW.Setup2_IWORK[0]);
      }

      /* registration */
      sersetupbase(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S7>/ASCII Encode  (asciiencode) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[21];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[21]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[21]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[21]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[21]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[21]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [21]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[21]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.UPtrs0;
          sfcnUPtrs[0] = &RITM_test_RT1007_B.SineWave;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 128);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            RITM_test_RT1007_B.ASCIIEncode));
        }
      }

      /* path info */
      ssSetModelName(rts, "ASCII Encode ");
      ssSetPath(rts, "RITM_test_RT1007/RS-232/ASCII Encode ");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.ASCIIEncode_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.ASCIIEncode_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.ASCIIEncode_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.ASCIIEncode_P4_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &RITM_test_RT1007_DW.ASCIIEncode_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn21.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RITM_test_RT1007_DW.ASCIIEncode_PWORK);
      }

      /* registration */
      asciiencode(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S23>/Setup1 (sersetupbase) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[22];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn22.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn22.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn22.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[22]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[22]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[22]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[22]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[22]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [22]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[22]);
      }

      /* path info */
      ssSetModelName(rts, "Setup1");
      ssSetPath(rts, "RITM_test_RT1007/RS-232/Baseboard Serial F/Setup1");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn22.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.Setup1_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.Setup1_P2_Size_l);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.Setup1_P3_Size_j);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.Setup1_P4_Size_b);
        ssSetSFcnParam(rts, 4, (mxArray*)RITM_test_RT1007_P.Setup1_P5_Size_a);
        ssSetSFcnParam(rts, 5, (mxArray*)RITM_test_RT1007_P.Setup1_P6_Size_i);
        ssSetSFcnParam(rts, 6, (mxArray*)RITM_test_RT1007_P.Setup1_P7_Size_p);
        ssSetSFcnParam(rts, 7, (mxArray*)RITM_test_RT1007_P.Setup1_P8_Size_k);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &RITM_test_RT1007_DW.Setup1_IWORK_e[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn22.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn22.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RITM_test_RT1007_DW.Setup1_IWORK_e[0]);
      }

      /* registration */
      sersetupbase(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: RITM_test_RT1007/<S23>/Setup2 (sersetupbase) */
    {
      SimStruct *rts = RITM_test_RT1007_M->childSfunctions[23];

      /* timing info */
      time_T *sfcnPeriod = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn23.sfcnPeriod;
      time_T *sfcnOffset = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn23.sfcnOffset;
      int_T *sfcnTsMap = RITM_test_RT1007_M->NonInlinedSFcns.Sfcn23.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RITM_test_RT1007_M->NonInlinedSFcns.blkInfo2[23]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RITM_test_RT1007_M->NonInlinedSFcns.inputOutputPortInfo2[23]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RITM_test_RT1007_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods2[23]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods3[23]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RITM_test_RT1007_M->NonInlinedSFcns.methods4[23]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RITM_test_RT1007_M->NonInlinedSFcns.statesInfo2
                         [23]);
        ssSetPeriodicStatesInfo(rts,
          &RITM_test_RT1007_M->NonInlinedSFcns.periodicStatesInfo[23]);
      }

      /* path info */
      ssSetModelName(rts, "Setup2");
      ssSetPath(rts, "RITM_test_RT1007/RS-232/Baseboard Serial F/Setup2");
      ssSetRTModel(rts,RITM_test_RT1007_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn23.params;
        ssSetSFcnParamsCount(rts, 8);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RITM_test_RT1007_P.Setup2_P1_Size_a);
        ssSetSFcnParam(rts, 1, (mxArray*)RITM_test_RT1007_P.Setup2_P2_Size_h);
        ssSetSFcnParam(rts, 2, (mxArray*)RITM_test_RT1007_P.Setup2_P3_Size_h);
        ssSetSFcnParam(rts, 3, (mxArray*)RITM_test_RT1007_P.Setup2_P4_Size_m);
        ssSetSFcnParam(rts, 4, (mxArray*)RITM_test_RT1007_P.Setup2_P5_Size_e);
        ssSetSFcnParam(rts, 5, (mxArray*)RITM_test_RT1007_P.Setup2_P6_Size_b);
        ssSetSFcnParam(rts, 6, (mxArray*)RITM_test_RT1007_P.Setup2_P7_Size_h);
        ssSetSFcnParam(rts, 7, (mxArray*)RITM_test_RT1007_P.Setup2_P8_Size_l);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &RITM_test_RT1007_DW.Setup2_IWORK_i[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn23.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RITM_test_RT1007_M->NonInlinedSFcns.Sfcn23.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RITM_test_RT1007_DW.Setup2_IWORK_i[0]);
      }

      /* registration */
      sersetupbase(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  RITM_test_RT1007_M->Sizes.numContStates = (0);/* Number of continuous states */
  RITM_test_RT1007_M->Sizes.numY = (0);/* Number of model outputs */
  RITM_test_RT1007_M->Sizes.numU = (0);/* Number of model inputs */
  RITM_test_RT1007_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  RITM_test_RT1007_M->Sizes.numSampTimes = (3);/* Number of sample times */
  RITM_test_RT1007_M->Sizes.numBlocks = (145);/* Number of blocks */
  RITM_test_RT1007_M->Sizes.numBlockIO = (100);/* Number of block outputs */
  RITM_test_RT1007_M->Sizes.numBlockPrms = (420);/* Sum of parameter "widths" */
  return RITM_test_RT1007_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
