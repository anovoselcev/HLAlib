#include <iostream>
#include "SimFederate.hpp"

using namespace std;

int main()
{
    int i = 20l;
    rti1516e::VariableLengthData type = HLA::cast_to_rti<HLA::Integer32BE>(i);
    std::wcout <<  HLA::cast_from_rti<HLA::Integer32BE>(type) << std::endl;

    return 0;
}
