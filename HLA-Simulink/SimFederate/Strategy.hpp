#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "HLAdata/HLAdata.hpp"

namespace HLA {

void Dispatch(int id, rti1516e::VariableLengthData v){
    switch(id){
    case 0:
        ActionPB(HLA::cast_from_rti<HLA::Button>(v));
        break;
    }
}


struct PushButton{

    void Action(const Button&){

    }

};

struct SwithchTumbler{

};

}



#endif // STRATEGY_HPP
