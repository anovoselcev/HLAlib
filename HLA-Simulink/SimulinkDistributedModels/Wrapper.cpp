#include "Wrapper.hpp"

static HLA::SimFederate* fed;

namespace HLA{
    
    using BusObject_Mode_SP = Struct_wrapper<BusObject_Mode_SP, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_Mode_ZS = Struct_wrapper<BusObject_Mode_ZS, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_Mode = Struct_wrapper<BusObject_Mode, 8,
                                             HLA::BusObject_Mode_SP,
                                             HLA::BusObject_Mode_ZS>;
    
    using BusObject_G_SP = Struct_wrapper<BusObject_G_SP, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_G_ZS = Struct_wrapper<BusObject_G_ZS, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_G = Struct_wrapper<BusObject_G, 8,
                                             HLA::BusObject_G_SP,
                                             HLA::BusObject_G_ZS>;
    
    using BusObject_obj = Struct_wrapper<BusObject_obj, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_Y_SP = Struct_wrapper<BusObject_Y_SP, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_Y_ZS = Struct_wrapper<BusObject_Y_ZS, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_Y_P = Struct_wrapper<BusObject_Y_P, 8,
                                             HLA::BusObject_Y_SP,
                                             HLA::BusObject_Y_ZS>;
    
    using BusObject_Matrix = Struct_wrapper<BusObject_Matrix, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_Y = Struct_wrapper<BusObject_Y, 8,
                                             HLA::BusObject_Y_P,
                                             HLA::BusObject_Matrix>;
    
   using BusObject_E_SP = Struct_wrapper<BusObject_E_SP, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_E_ZS = Struct_wrapper<BusObject_E_ZS, 8,
                                             HLA::Float64BE,
                                             HLA::Float64BE>;
    
    using BusObject_E = Struct_wrapper<BusObject_E, 8,
                                             HLA::BusObject_E_SP,
                                             HLA::BusObject_E_ZS>;
}

void Start_Point_ModelVK(){
   auto file =  HLA::JSON::MakeJSON(L"C:\\RRTI\\HLAlib\\conf\\ModelVK_SOM.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->   LoadSOMFromJSON(file).
        ConnectRTI();
    }
    catch(...){}
}

void Start_Point_ModelInput(){
    auto file =  HLA::JSON::MakeJSON(L"C:\\RRTI\\HLAlib\\conf\\ModelInputSOM.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->   LoadSOMFromJSON(file).
        ConnectRTI();
    }
    catch(...){}
}

void Start_Point_ModelObject(){
    auto file =  HLA::JSON::MakeJSON(L"C:\\RRTI\\HLAlib\\conf\\ModelObject_SOM.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->   LoadSOMFromJSON(file).
        ConnectRTI();
    }
    catch(...){}
}

void Start_Point_ModelMain(){
    auto file =  HLA::JSON::MakeJSON(L"C:\\RRTI\\HLAlib\\conf\\ModelMain_SOM.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->   LoadSOMFromJSON(file).
        ConnectRTI();
    }
    catch(...){}
}

void Start_Point_ModelMainIn(){
    auto file =  HLA::JSON::MakeJSON(L"C:\\RRTI\\HLAlib\\conf\\ModelMainIn_SOM.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->   LoadSOMFromJSON(file).
        ConnectRTI();
    }
    catch(...){}
}
void Start_Point_ModelMainOut(){
    auto file =  HLA::JSON::MakeJSON(L"C:\\RRTI\\HLAlib\\conf\\ModelMainOut_SOM.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->   LoadSOMFromJSON(file).
        ConnectRTI();
    }
    catch(...){}
}
 
void Start_Point_ModelPlants(){
    auto file =  HLA::JSON::MakeJSON(L"C:\\RRTI\\HLAlib\\conf\\ModelPlants_SOM.json");
    fed = new HLA::SimFederate(file);
    try{
        fed->   LoadSOMFromJSON(file).
        ConnectRTI();
    }
    catch(...){}
}

void Terminate_Point(){
    delete fed;
}

void Output_Point_ModelInput(BusObject_Mode* u1, BusObject_G* u2){
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> output_to_rti;
    output_to_rti[L"Mode"] = HLA::cast_to_rti<HLA::BusObject_Mode>(*u1);
    output_to_rti[L"G"]    = HLA::cast_to_rti<HLA::BusObject_G>(*u2);
    fed->SendDataToRTI(output_to_rti);  
   // HLA::ModelGuard guard(fed);
}

void Output_Point_ModelVK(BusObject_Mode* y1, BusObject_G* y2, BusObject_Y* y3, BusObject_E* u1){
    
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> output_to_rti;
    output_to_rti[L"E"] = HLA::cast_to_rti<HLA::BusObject_E>(*u1);
    fed->SendDataToRTI(output_to_rti);
   
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> input_from_rti = fed->getData();
    if(input_from_rti[L"Mode"].size())
        *y1 = HLA::cast_from_rti<HLA::BusObject_Mode>(input_from_rti[L"Mode"]);
    if(input_from_rti[L"G"].size())
        *y2 = HLA::cast_from_rti<HLA::BusObject_G>(input_from_rti[L"G"]);
    if(input_from_rti[L"Y"].size())
        *y3 = HLA::cast_from_rti<HLA::BusObject_Y>(input_from_rti[L"Y"]);
   // HLA::ModelGuard guard(fed);
}
 
void Output_Point_ModelObject(BusObject_obj* u1){
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> output_to_rti;
    output_to_rti[L"Out_obj"] = HLA::cast_to_rti<HLA::BusObject_obj>(*u1);
    fed->SendDataToRTI(output_to_rti);
}


void Output_Point_ModelMain( BusObject_Y* u1, BusObject_obj* y1, BusObject_Y_P* y2){
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> output_to_rti;
    output_to_rti[L"Y"] = HLA::cast_to_rti<HLA::BusObject_Y>(*u1);
    fed->SendDataToRTI(output_to_rti);
    
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> input_from_rti = fed->getData();
    if(input_from_rti[L"Out_obj"].size())
        *y1 = HLA::cast_from_rti<HLA::BusObject_obj>(input_from_rti[L"Out_obj"]);
    if(input_from_rti[L"Y_P"].size())
        *y2 = HLA::cast_from_rti<HLA::BusObject_Y_P>(input_from_rti[L"Y_P"]);
}

void Output_Point_ModelMainIn(BusObject_obj* y1, BusObject_Y_P* y2){  
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> input_from_rti = fed->getData();
    if(input_from_rti[L"Out_obj"].size())
        *y1 = HLA::cast_from_rti<HLA::BusObject_obj>(input_from_rti[L"Out_obj"]);
    if(input_from_rti[L"Y_P"].size())
        *y2 = HLA::cast_from_rti<HLA::BusObject_Y_P>(input_from_rti[L"Y_P"]);
}

void Output_Point_ModelMainOut( BusObject_Y* u1){
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> output_to_rti;
    output_to_rti[L"Y"] = HLA::cast_to_rti<HLA::BusObject_Y>(*u1);
    fed->SendDataToRTI(output_to_rti);
}

void Output_Point_ModelPlants(BusObject_Y_P* u1, BusObject_E* y1){
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> output_to_rti;
    output_to_rti[L"Y_P"] = HLA::cast_to_rti<HLA::BusObject_Y_P>(*u1);
    fed->SendDataToRTI(output_to_rti);
    
    std::unordered_map<std::wstring, rti1516e::VariableLengthData> input_from_rti = fed->getData();
    if(input_from_rti[L"E"].size())
        *y1 = HLA::cast_from_rti<HLA::BusObject_E>(input_from_rti[L"E"]);
}
