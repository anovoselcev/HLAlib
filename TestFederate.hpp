#ifndef TESTFEDERATE_HPP
#define TESTFEDERATE_HPP

#include "BaseFederate.hpp"
#include "ModelGuard.hpp"
#include "HLAdata/HLA-Data-Test/TetsRTIfixedRecord.hpp"

class TestFederate : public HLA::BaseFederate{
public:
    TestFederate(std::wstring&& name,
                 std::wstring&& type,
                 std::wstring&& FOM,
                 std::wstring&& fname);

    void RunFederate() override;

    void AttributeProcess() override;

    std::vector<double> Signal;
    std::array<int,4> id;
    Person person;
};

#endif // TESTFEDERATE_HPP
