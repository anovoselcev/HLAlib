#include "Wrapper.hpp"

static HLA::SimFederate* fed;



void Start_Point_ModelARM(){
   auto file =  HLA::JSON::MakeJSON( L"/home/k-110-04/QtWork/HLA/HLAlib/conf/matlab.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->ConnectRTI(file);
    }
    catch(...){}
}


void Terminate_Point(){
    delete fed;
}

void Output_Point_ModelARM(double* u1, double* u2){
   // HLA::ModelGuard guard(fed);
}
