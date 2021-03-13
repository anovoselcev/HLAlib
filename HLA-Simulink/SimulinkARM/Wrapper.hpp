#ifndef WRAPPER_HPP
#define WRAPPER_HPP

#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

#include "SimFederate.hpp"
#include "ModelGuard.hpp"
#include "HLAdata/HLAdata.hpp"

void Start_Point_ModelARM();

void Terminate_Point();

void Output_Point_ModelARM(double* u1, double* u2);


#endif
