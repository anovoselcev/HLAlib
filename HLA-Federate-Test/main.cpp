#include <iostream>
#include "ThreadFederate.hpp"
#include "FollowFederate.hpp"
#include "../ModelGuard.hpp"
#include <assert.h>


constexpr int step = 200;

using namespace std;

void  NewThreadFederate(wstring&& name, int delay){
    auto fed = std::make_unique<ThreadFederate>(name,L"../HLA-Federate-Test/SampleFOM.xml");
    fed->SetPublishListOfAttributes({L"Name"}).
            SetSubscribeMapOfObjectsAndAttributes({{L"Following",{L"Name",L"Attr1",L"Attr2"}}}).
            SetModelingStep(step).
            ConnectRTI();
    auto begin = chrono::steady_clock::now();
    while(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - begin).count() < step*100){
        auto start = chrono::steady_clock::now();
        HLA::ModelGuard guard(fed.get());
        this_thread::sleep_for(chrono::milliseconds(delay));
        if(!fed->firstly){
            //assert(fed->_other==L"Fed2");

            auto time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
            std::wcout << fed->_other << L"        " << time << std::endl;
            assert((time < (step*1.05))||(time > (step*0.95)));
        }
        else
            fed->firstly=false;
    }
}
void NewFollowFederate(wstring&& name, int delay){
    auto fed = std::make_unique<FollowFederate>(name,L"../HLA-Federate-Test/SampleFOM.xml");
    fed->SetPublishListOfAttributes({L"Name"}).
            SetSubscribeMapOfObjectsAndAttributes({{L"Threading",{L"Name",L"Attr1",L"Attr2"}}}).
            SetModelingStep(step).
            ConnectRTI();
    auto begin = chrono::steady_clock::now();
    while(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - begin).count() < step*100){
        auto start = chrono::steady_clock::now();

        this_thread::sleep_for(chrono::milliseconds(delay));
        HLA::ModelGuard guard(fed.get());
        if(!fed->firstly){
            //assert((fed->_other==L"Fed1")||(fed->_other==L"Fed3"));
            auto time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
            std::wcout << fed->_other << L"        " << time << std::endl;
            assert((time < (step*1.05))||(time > (step*0.95)));
        }
        else
            fed->firstly=false;
    }
}

int main()
{
    std::thread th1(NewThreadFederate,L"Fed1",150);
    th1.detach();
    this_thread::sleep_for(chrono::milliseconds(5));
    std::thread th2(NewFollowFederate, L"Fed2",70);
    th2.detach();
    this_thread::sleep_for(chrono::milliseconds(5));
    std::thread th3(NewThreadFederate,L"Fed3",110);
    th3.detach();
    this_thread::sleep_for(chrono::milliseconds(5));
    std::thread th4(NewThreadFederate,L"Fed4",133);
    th4.detach();
    this_thread::sleep_for(chrono::milliseconds(5));
    std::thread th5(NewFollowFederate, L"Fed5",120);
    th5.detach();
    this_thread::sleep_for(chrono::milliseconds(5));
    std::thread th6(NewThreadFederate,L"Fed6",199);
    th6.detach();
    NewFollowFederate(L"Fed7",100);



    return 0;
}
