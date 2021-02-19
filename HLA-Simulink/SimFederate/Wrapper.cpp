#include "Wrapper.hpp"

static HLA::SimFederate* fed;

void Start_Point_ModelARM(){
   auto file =  HLA::JSON::MakeJSON( L"C:\\config\\SP.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->ConnectRTI(file);
    }
    catch(...){}
}

void Start_Point_ModelBins(){
   auto file =  HLA::JSON::MakeJSON( L"C:\\config\\BINS.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->ConnectRTI(file);
    }
    catch(...){}
}


void Terminate_Point(){
    delete fed;
}

void Output_Point_ModelARM(AngleData* u1, AngleData* y1){
    HLA::ModelGuard guard(fed);
    
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> output_to_rti;
    output_to_rti[L"Angle"] = HLA::cast_to_rti<HLA::AngleData>(*u1);
    fed->SendDataToRTI(output_to_rti);
    
    std::unordered_map<std::wstring, rti1516e::VariableLengthData>& input_from_rti = fed->getData();
    
    if(input_from_rti[L"Angle"].size())
        *y1 = HLA::cast_from_rti<HLA::AngleData>(input_from_rti[L"Angle"]);
}


void Output_Point_ModelBins(BinsData* u1){
    HLA::ModelGuard guard(fed);
    
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> output_to_rti;
    output_to_rti[L"BinsData"] = HLA::cast_to_rti<HLA::BinsData>(*u1);
    fed->SendDataToRTI(output_to_rti);
}
