#ifndef RTW_HEADER_RITM_test_RT1007_cap_host_h_
#define RTW_HEADER_RITM_test_RT1007_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} RITM_test_RT1007_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void RITM_test_RT1007_host_InitializeDataMapInfo
    (RITM_test_RT1007_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                             /* RTW_HEADER_RITM_test_RT1007_cap_host_h_ */

/* EOF: RITM_test_RT1007_capi_host.h */
