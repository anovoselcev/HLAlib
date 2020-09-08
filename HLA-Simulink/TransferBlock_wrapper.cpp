
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include "SimFederate.hpp"
HLA::SimFederate* fed;
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void TransferBlock_Start_wrapper(const real_T *Param1, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
//std::wcout << L"Im in Start" << std::endl;
fed = new HLA::SimFederate(L"Transfer1",L"Transfer",L"/home/k-110-04/QtWork/HLA/FOMS/ARMfom.xml",L"UPIM");
fed->SetPublishListOfAttributes({L"Value", L"Class", L"Vector",L"Array"});
fed->SetSubscribeMapOfObjectsAndAttributes({{L"ARM",{L"Name"}}});
fed->SetMapOfInteractionsAndParameters({{L"ARMaction",{L"Button",L"Tumbler"}}});
fed->SetModelingStep(100);
fed->ConnectRTI();
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void TransferBlock_Outputs_wrapper(const real_T *X,
			real_T *Y,
			const real_T *Param1, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
Y[0]=X[0]+1;
//sleep(1);
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Terminate function
 *
 */
void TransferBlock_Terminate_wrapper(const real_T *Param1, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Terminate code goes here.
 */
//std::wcout << L"Im in Terminate" << std::endl;
delete fed;
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

