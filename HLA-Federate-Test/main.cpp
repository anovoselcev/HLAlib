#include <iostream>
#include "ThreadFederate.hpp"
#include "FollowFederate.hpp"
#include "../ModelGuard.hpp"
#include <assert.h>


constexpr int step = 2000;

using namespace std;

void NewThreadFederate(wstring&& name, int delay){
    auto fed = std::make_unique<ThreadFederate>(name,L"../HLA-Federate-Test/SampleFOM.xml");
    fed->SetPublishListOfAttributes({L"Name"}).
            SetSubscribeMapOfObjectsAndAttributes({{L"Following",{L"Name"}}}).
            SetModelingStep(step).
            ConnectRTI();
    while(true){
        auto start = chrono::steady_clock::now();
        HLA::ModelGuard guard(fed.get());
        this_thread::sleep_for(chrono::milliseconds(delay));
        if(!fed->firstly){
            //assert(fed->_other==L"Fed2");

            auto time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
            std::wcout << fed->_other << L"        " << time << std::endl;
            assert((time < (step + 50))||(time > (step-50)));
        }
        else
            fed->firstly=false;
    }
}
void NewFollowFederate(wstring&& name, int delay){
    auto fed = std::make_unique<FollowFederate>(name,L"../HLA-Federate-Test/SampleFOM.xml");
    fed->SetPublishListOfAttributes({L"Name"}).
            SetSubscribeMapOfObjectsAndAttributes({{L"Threading",{L"Name"}}}).
            SetModelingStep(step).
            ConnectRTI();
    while(true){
        auto start = chrono::steady_clock::now();

        this_thread::sleep_for(chrono::milliseconds(delay));
        HLA::ModelGuard guard(fed.get());
        if(!fed->firstly){
            assert((fed->_other==L"Fed1")||(fed->_other==L"Fed3"));
            auto time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
            assert((time < (step + 50))||(time > (step-50)));
        }
        else
            fed->firstly=false;
    }
}

int main()
{
    std::thread th1(NewThreadFederate,L"Fed1",1500);
    this_thread::sleep_for(chrono::milliseconds(10));
    std::thread th2(NewFollowFederate, L"Fed2",700);
    NewFollowFederate(L"Fed3",100);



    return 0;
}
