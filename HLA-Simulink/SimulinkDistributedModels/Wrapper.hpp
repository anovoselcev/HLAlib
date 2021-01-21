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
#include "MyTypes.h"

void Start_Point_ModelVK();

void Start_Point_ModelInput();

void Start_Point_ModelObject();

void Start_Point_ModelMain();

void Start_Point_ModelMainIn();

void Start_Point_ModelMainOut();

void Start_Point_ModelPlants();

void Terminate_Point();

void Output_Point_ModelInput(BusObject_Mode* u1, BusObject_G* u2);

void Output_Point_ModelVK(BusObject_Mode* y1, BusObject_G* y2, BusObject_Y* y3, BusObject_E* u1);

void Output_Point_ModelObject(BusObject_obj* u1);

void Output_Point_ModelMain(BusObject_Y* u1, BusObject_obj* y1, BusObject_Y_P* y2);

void Output_Point_ModelMainIn( BusObject_obj* y1, BusObject_Y_P* y2);

void Output_Point_ModelMainOut(BusObject_Y* u1);

void Output_Point_ModelPlants(BusObject_Y_P* u1, BusObject_E* y1);

#endif