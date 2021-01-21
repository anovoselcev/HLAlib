#include <iostream>
#include "ThreadFederate.hpp"
#include "FollowFederate.hpp"
#include "../ModelGuard.hpp"
#include "../FederationManager.hpp"
#include "../ProxyFederate.hpp"
#include <assert.h>
#include <tbb/tbb.h>

constexpr int step = 2;

using namespace std;

void  NewThreadFederate(wstring&& name, int delay){
    auto file = HLA::JSON::MakeJSON(L"../conf/ThreadingSOM.json");
    auto fed = std::make_unique<ThreadFederate>(file);
    fed->ConnectRTI(file);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    auto begin = chrono::steady_clock::now();
    while(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - begin).count() < step*100000){
        auto start = chrono::steady_clock::now();
        //HLA::ModelGuard guard(fed.get());
        this_thread::sleep_for(chrono::milliseconds(delay));
        if(!fed->firstly){

            auto time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
            //assert((time < (step*1.05))||(time > (step*0.95)));
        }
        else
            fed->firstly=false;
    }
}
void NewFollowFederate(wstring&& name, int delay){
    auto file = HLA::JSON::MakeJSON(L"../conf/FollowingSOM.json");
    auto fed = std::make_unique<FollowFederate>(file);
    fed->ConnectRTI(file);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto begin = chrono::steady_clock::now();
    while(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - begin).count() < step*100000){
        auto start = chrono::steady_clock::now();
        std::wcout << L"New Step" << std::endl;
        this_thread::sleep_for(chrono::milliseconds(delay));
        HLA::ModelGuard guard(fed.get());
        if(!fed->firstly){
            //assert((fed->_other==L"Fed1")||(fed->_other==L"Fed3"));
            auto time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count();
            //std::wcout << fed->_other << L"        " << time << std::endl;
            //assert((time < (step*1.05))||(time > (step*0.95)));
        }
        else
            fed->firstly=false;
        //std::wcout << fed->GetName() << L" recive " << fed->_other << std::endl;
    }
}

void f1(){
    std::wcout << L"First" << std::endl;
    for(;;);
    std::this_thread::sleep_for(std::chrono::minutes(5));
}

void f2(){
    std::wcout << L"Second" << std::endl;
    for(;;)
    std::this_thread::sleep_for(std::chrono::minutes(5));
}

int main()
{
//    tbb::task_group tg;
//    tg.run([](){f1();});
//    tg.run([](){f2();});
    auto file = HLA::JSON::MakeJSON(L"/home/k-110-04/QtWork/HLA/build-AutoCoderForTest-Desktop_Qt_5_12_5_GCC_64bit-Release/Test.JSON");
    HLA::FederationManager man(file);
    auto start = std::chrono::steady_clock::now();
    man.ConnectRTI(file);
    auto end = std::chrono::steady_clock::now();
    std::wcout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << L"us" << std::endl;
    //HLA::ProxyFederate prx(file);
    //prx("10.55.82.125:8080", file);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //std::thread th1(NewThreadFederate,L"Fed1",1000);
    //th1.join();
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    //NewFollowFederate( L"Fed2",10000);
    //th1.detach();
   // std::this_thread::sleep_for(std::chrono::milliseconds(10000));
   // auto file = HLA::JSON::MakeJSON(L"../conf/ThreadingSOM.json");
    //std::wcout << L"Thread done " << std::endl;
   // HLA::FederationManager man(file);
   // man.ConnectRTI(file);
  // this_thread::sleep_for(chrono::milliseconds(5));
 //  std::thread th2(NewFollowFederate, L"Fed2",70);
  // th2.join();
//    this_thread::sleep_for(chrono::milliseconds(5));
//    std::thread th3(NewThreadFederate,L"Fed3",110);
//    th3.detach();
//    this_thread::sleep_for(chrono::milliseconds(5));
//    std::thread th4(NewThreadFederate,L"Fed4",133);
//    th4.detach();
//    this_thread::sleep_for(chrono::milliseconds(5));
//    std::thread th5(NewFollowFederate, L"Fed5",120);
//    th5.detach();
//    this_thread::sleep_for(chrono::milliseconds(5));
//    std::thread th6(NewThreadFederate,L"Fed6",199);
//    th6.detach();
    //NewFollowFederate(L"Fed7",100);
    //std::wcout << sizeof (int32_t) << std::endl;

    return 0;
}
