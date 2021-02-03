/*
 * Ethernet_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Ethernet_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "Ethernet.h"
#include "Ethernet_capi.h"
#include "Ethernet_private.h"
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
  { 0, 1, TARGET_STRING("Ethernet/Data Type Conversion"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 1, TARGET_STRING("Ethernet/Data Type Conversion1"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 2, 1, TARGET_STRING("Ethernet/Byte Packing 2"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 3, 1, TARGET_STRING("Ethernet/Byte Packing 6"),
    TARGET_STRING(""), 0, 2, 2, 0, 0 },

  { 4, 1, TARGET_STRING("Ethernet/Byte Packing 7"),
    TARGET_STRING(""), 0, 2, 3, 0, 0 },

  { 5, 1, TARGET_STRING("Ethernet/Sine Wave1"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 6, 1, TARGET_STRING("Ethernet/Sine Wave5"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 7, 1, TARGET_STRING("Ethernet/Sine Wave6"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  { 8, 1, TARGET_STRING("Ethernet/Width1"),
    TARGET_STRING(""), 0, 3, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 9, TARGET_STRING("Ethernet/UDP Configure"),
    TARGET_STRING("P1"), 3, 4, 0 },

  { 10, TARGET_STRING("Ethernet/UDP Configure"),
    TARGET_STRING("P2"), 3, 4, 0 },

  { 11, TARGET_STRING("Ethernet/UDP Configure"),
    TARGET_STRING("P3"), 3, 4, 0 },

  { 12, TARGET_STRING("Ethernet/UDP Configure"),
    TARGET_STRING("P5"), 3, 0, 0 },

  { 13, TARGET_STRING("Ethernet/UDP Configure"),
    TARGET_STRING("P8"), 3, 0, 0 },

  { 14, TARGET_STRING("Ethernet/UDP Configure"),
    TARGET_STRING("P9"), 3, 0, 0 },

  { 15, TARGET_STRING("Ethernet/UDP Configure"),
    TARGET_STRING("P10"), 3, 0, 0 },

  { 16, TARGET_STRING("Ethernet/UDP Configure"),
    TARGET_STRING("P11"), 3, 0, 0 },

  { 17, TARGET_STRING("Ethernet/UDP Configure"),
    TARGET_STRING("P12"), 3, 0, 0 },

  { 18, TARGET_STRING("Ethernet/UDP Send1"),
    TARGET_STRING("P1"), 3, 5, 0 },

  { 19, TARGET_STRING("Ethernet/UDP Send1"),
    TARGET_STRING("P2"), 3, 0, 0 },

  { 20, TARGET_STRING("Ethernet/UDP Send1"),
    TARGET_STRING("P3"), 3, 5, 0 },

  { 21, TARGET_STRING("Ethernet/UDP Send1"),
    TARGET_STRING("P4"), 3, 0, 0 },

  { 22, TARGET_STRING("Ethernet/UDP Send1"),
    TARGET_STRING("P5"), 3, 0, 0 },

  { 23, TARGET_STRING("Ethernet/UDP Send1"),
    TARGET_STRING("P6"), 3, 0, 0 },

  { 24, TARGET_STRING("Ethernet/Sine Wave1"),
    TARGET_STRING("Amplitude"), 3, 0, 0 },

  { 25, TARGET_STRING("Ethernet/Sine Wave1"),
    TARGET_STRING("Bias"), 3, 0, 0 },

  { 26, TARGET_STRING("Ethernet/Sine Wave1"),
    TARGET_STRING("Frequency"), 3, 0, 0 },

  { 27, TARGET_STRING("Ethernet/Sine Wave1"),
    TARGET_STRING("SinH"), 3, 0, 0 },

  { 28, TARGET_STRING("Ethernet/Sine Wave1"),
    TARGET_STRING("CosH"), 3, 0, 0 },

  { 29, TARGET_STRING("Ethernet/Sine Wave1"),
    TARGET_STRING("SinPhi"), 3, 0, 0 },

  { 30, TARGET_STRING("Ethernet/Sine Wave1"),
    TARGET_STRING("CosPhi"), 3, 0, 0 },

  { 31, TARGET_STRING("Ethernet/Sine Wave5"),
    TARGET_STRING("Amplitude"), 3, 0, 0 },

  { 32, TARGET_STRING("Ethernet/Sine Wave5"),
    TARGET_STRING("Bias"), 3, 0, 0 },

  { 33, TARGET_STRING("Ethernet/Sine Wave5"),
    TARGET_STRING("Frequency"), 3, 0, 0 },

  { 34, TARGET_STRING("Ethernet/Sine Wave5"),
    TARGET_STRING("SinH"), 3, 0, 0 },

  { 35, TARGET_STRING("Ethernet/Sine Wave5"),
    TARGET_STRING("CosH"), 3, 0, 0 },

  { 36, TARGET_STRING("Ethernet/Sine Wave5"),
    TARGET_STRING("SinPhi"), 3, 0, 0 },

  { 37, TARGET_STRING("Ethernet/Sine Wave5"),
    TARGET_STRING("CosPhi"), 3, 0, 0 },

  { 38, TARGET_STRING("Ethernet/Sine Wave6"),
    TARGET_STRING("Amplitude"), 3, 0, 0 },

  { 39, TARGET_STRING("Ethernet/Sine Wave6"),
    TARGET_STRING("Bias"), 3, 0, 0 },

  { 40, TARGET_STRING("Ethernet/Sine Wave6"),
    TARGET_STRING("Frequency"), 3, 0, 0 },

  { 41, TARGET_STRING("Ethernet/Sine Wave6"),
    TARGET_STRING("SinH"), 3, 0, 0 },

  { 42, TARGET_STRING("Ethernet/Sine Wave6"),
    TARGET_STRING("CosH"), 3, 0, 0 },

  { 43, TARGET_STRING("Ethernet/Sine Wave6"),
    TARGET_STRING("SinPhi"), 3, 0, 0 },

  { 44, TARGET_STRING("Ethernet/Sine Wave6"),
    TARGET_STRING("CosPhi"), 3, 0, 0 },

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
  &Ethernet_B.DataTypeConversion,      /* 0: Signal */
  &Ethernet_B.DataTypeConversion1,     /* 1: Signal */
  &Ethernet_B.BytePacking2[0],         /* 2: Signal */
  &Ethernet_B.BytePacking6[0],         /* 3: Signal */
  &Ethernet_B.BytePacking7[0],         /* 4: Signal */
  &Ethernet_B.SineWave1,               /* 5: Signal */
  &Ethernet_B.SineWave5,               /* 6: Signal */
  &Ethernet_B.SineWave6,               /* 7: Signal */
  &Ethernet_B.Width1,                  /* 8: Signal */
  &Ethernet_P.UDPConfigure_P1[0],      /* 9: Block Parameter */
  &Ethernet_P.UDPConfigure_P2[0],      /* 10: Block Parameter */
  &Ethernet_P.UDPConfigure_P3[0],      /* 11: Block Parameter */
  &Ethernet_P.UDPConfigure_P5,         /* 12: Block Parameter */
  &Ethernet_P.UDPConfigure_P8,         /* 13: Block Parameter */
  &Ethernet_P.UDPConfigure_P9,         /* 14: Block Parameter */
  &Ethernet_P.UDPConfigure_P10,        /* 15: Block Parameter */
  &Ethernet_P.UDPConfigure_P11,        /* 16: Block Parameter */
  &Ethernet_P.UDPConfigure_P12,        /* 17: Block Parameter */
  &Ethernet_P.UDPSend1_P1[0],          /* 18: Block Parameter */
  &Ethernet_P.UDPSend1_P2,             /* 19: Block Parameter */
  &Ethernet_P.UDPSend1_P3[0],          /* 20: Block Parameter */
  &Ethernet_P.UDPSend1_P4,             /* 21: Block Parameter */
  &Ethernet_P.UDPSend1_P5,             /* 22: Block Parameter */
  &Ethernet_P.UDPSend1_P6,             /* 23: Block Parameter */
  &Ethernet_P.SineWave1_Amp,           /* 24: Block Parameter */
  &Ethernet_P.SineWave1_Bias,          /* 25: Block Parameter */
  &Ethernet_P.SineWave1_Freq,          /* 26: Block Parameter */
  &Ethernet_P.SineWave1_Hsin,          /* 27: Block Parameter */
  &Ethernet_P.SineWave1_HCos,          /* 28: Block Parameter */
  &Ethernet_P.SineWave1_PSin,          /* 29: Block Parameter */
  &Ethernet_P.SineWave1_PCos,          /* 30: Block Parameter */
  &Ethernet_P.SineWave5_Amp,           /* 31: Block Parameter */
  &Ethernet_P.SineWave5_Bias,          /* 32: Block Parameter */
  &Ethernet_P.SineWave5_Freq,          /* 33: Block Parameter */
  &Ethernet_P.SineWave5_Hsin,          /* 34: Block Parameter */
  &Ethernet_P.SineWave5_HCos,          /* 35: Block Parameter */
  &Ethernet_P.SineWave5_PSin,          /* 36: Block Parameter */
  &Ethernet_P.SineWave5_PCos,          /* 37: Block Parameter */
  &Ethernet_P.SineWave6_Amp,           /* 38: Block Parameter */
  &Ethernet_P.SineWave6_Bias,          /* 39: Block Parameter */
  &Ethernet_P.SineWave6_Freq,          /* 40: Block Parameter */
  &Ethernet_P.SineWave6_Hsin,          /* 41: Block Parameter */
  &Ethernet_P.SineWave6_HCos,          /* 42: Block Parameter */
  &Ethernet_P.SineWave6_PSin,          /* 43: Block Parameter */
  &Ethernet_P.SineWave6_PCos,          /* 44: Block Parameter */
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
  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0, 0 },

  { "short", "int16_T", 0, 0, sizeof(int16_T), SS_INT16, 0, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 }
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

  { rtwCAPI_VECTOR, 10, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  8,                                   /* 2 */
  1,                                   /* 3 */
  4,                                   /* 4 */
  1,                                   /* 5 */
  2,                                   /* 6 */
  1,                                   /* 7 */
  1,                                   /* 8 */
  4,                                   /* 9 */
  1,                                   /* 10 */
  10                                   /* 11 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
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
  { rtBlockSignals, 9,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 36,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2631844814U,
    2685931753U,
    4102488394U,
    2050563093U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  Ethernet_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void Ethernet_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(Ethernet_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(Ethernet_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(Ethernet_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(Ethernet_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(Ethernet_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  Ethernet_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (Ethernet_M);
  Ethernet_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof(P_Ethernet_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(Ethernet_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(Ethernet_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(Ethernet_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void Ethernet_host_InitializeDataMapInfo(Ethernet_host_DataMapInfo_T *dataMap,
    const char *path)
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

/* EOF: Ethernet_capi.c */
