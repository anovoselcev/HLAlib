#ifndef TETSRTIFIXEDRECORD_HPP
#define TETSRTIFIXEDRECORD_HPP
#include "test_runner.hpp"
#include "../include/RTIfixedRecod.hpp"
#include "../include/RTIstring.hpp"

struct Position{
    double x = 0;
    double y = 0;
};

class RTIPosition : public HLA::BaseRTIFixedRecord<Position,8>{
public:
    void getDataMax(void *ptrSource, unsigned long uiMaxSize){
        HLA::RTIfloat64BE field0;
        HLA::RTIfloat64BE field1;
        unsigned offset = 0;
        auto_offset(offset,ptrSource,uiMaxSize,field0,field1);
    }

    void get(const Position &obj){
        HLA::RTIfloat64BE field0;
        HLA::RTIfloat64BE field1;
        unsigned offset = 0, uiSize;
        m_uiSizeData=0;
        auto_geter_first(offset,uiSize,field0,obj.x,field1,obj.y);
        auto_geter_second(offset,uiSize,field0,field1);
    }

    void set(Position &obj){
        HLA::RTIfloat64BE field0;
        HLA::RTIfloat64BE field1;
        unsigned offset = 0, uiSize;
        auto_seter(offset,uiSize,field0,obj.x,field1,obj.y);
    }
};

void TestPosition(){
    Position pos1{4.0,2.2};
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<RTIPosition>(pos1);
    Position pos2 = HLA::cast_from_rti<RTIPosition>(v1);
    ASSERT_EQUAL(pos1.x,pos2.x)
    ASSERT_EQUAL(pos1.y,pos2.y)

}

struct Book{
    int pages = 0;
    std::string name = "";
};

class RTIBook : public HLA::BaseRTIFixedRecord<Book,8>{
public:
    void getDataMax(void *ptrSource, unsigned long uiMaxSize){
        HLA::RTIinteger32BE field0;
        HLA::RTIstring field1;
        unsigned offset = 0;
        auto_offset(offset,ptrSource,uiMaxSize,field0,field1);
    }

    void get(const Book &obj){
        HLA::RTIinteger32BE field0;
        HLA::RTIstring field1;
        unsigned offset = 0, uiSize;
        m_uiSizeData=0;
        auto_geter_first(offset,uiSize,field0,obj.pages,field1,obj.name);
        auto_geter_second(offset,uiSize,field0,field1);
    }

    void set(Book &obj){
        HLA::RTIinteger32BE field0;
        HLA::RTIstring field1;
        unsigned offset = 0, uiSize;
        auto_seter(offset,uiSize,field0,obj.pages,field1,obj.name);
    }
};

void TestBook(){
    Book book1 = {784,"C++ Templates"};
    rti1516e::VariableLengthData v = HLA::cast_to_rti<RTIBook>(book1);
    Book book2 = HLA::cast_from_rti<RTIBook>(v);
    ASSERT_EQUAL(book1.name,book2.name)
    ASSERT_EQUAL(book1.pages,book2.pages)

}

struct Juice{
    int volume = 0;
    double price = 0;
    std::string type = "";
};

class RTIJuice : public HLA::BaseRTIFixedRecord<Juice,8>{
public:
    void getDataMax(void *ptrSource, unsigned long uiMaxSize){
        HLA::RTIfloat64BE field0;
        HLA::RTIinteger32BE field1;
        HLA::RTIstring field2;
         unsigned offset = 0;
         auto_offset(offset,ptrSource,uiMaxSize,field0,field1,field2);
    }

    void get(const Juice &obj){
        HLA::RTIfloat64LE field0;
        HLA::RTIinteger32BE field1;
        HLA::RTIstring field2;
        unsigned offset = 0, uiSize;
        m_uiSizeData=0;
        auto_geter_first(offset,uiSize,field0,obj.price,field1,obj.volume,field2,obj.type);
        auto_geter_second(offset,uiSize,field0,field1,field2);
    }

    void set(Juice &obj){
        HLA::RTIfloat64LE field0;
        HLA::RTIinteger32BE field1;
        HLA::RTIstring field2;
        unsigned offset = 0, uiSize;
        auto_seter(offset,uiSize,field0,obj.price,field1,obj.volume, field2, obj.type);
    }
};

void TestJuice(){
    Juice j1 = {2,2.33,"Orange"};
    rti1516e::VariableLengthData v = HLA::cast_to_rti<RTIJuice>(j1);
    Juice j2 = HLA::cast_from_rti<RTIJuice>(v);
    ASSERT_EQUAL(j1.volume,j2.volume)
    ASSERT_EQUAL(j1.type,j2.type)
    ASSERT_EQUAL(j1.price,j2.price)
}

struct Person{
    std::wstring first_name;
    std::wstring second_name;
    int age;
    double weight;
    double height;
};

class RTIPerson : public HLA::BaseRTIFixedRecord<Person,8>{
public:
    void getDataMax(void *ptrSource, unsigned long uiMaxSize){
        HLA::RTIwstring field0;
        HLA::RTIwstring field1;
        HLA::RTIinteger32BE field2;
        HLA::RTIfloat64BE field3;
        HLA::RTIfloat64BE field4;
         unsigned offset = 0;
         auto_offset(offset,ptrSource,uiMaxSize,field0,field1,field2,field3,field4);
    }

    void get(const Person &obj){
        HLA::RTIwstring field0;
        HLA::RTIwstring field1;
        HLA::RTIinteger32BE field2;
        HLA::RTIfloat64BE field3;
        HLA::RTIfloat64BE field4;
        unsigned offset = 0, uiSize;
        m_uiSizeData=0;
        auto_geter_first(offset,uiSize,field0,obj.first_name,
                                       field1,obj.second_name,
                                       field2,obj.age,
                                       field3,obj.weight,
                                       field4,obj.height);

        auto_geter_second(offset,uiSize,field0,field1,field2,field3,field4);
    }

    void set(Person &obj){
        HLA::RTIwstring field0;
        HLA::RTIwstring field1;
        HLA::RTIinteger32BE field2;
        HLA::RTIfloat64BE field3;
        HLA::RTIfloat64BE field4;
        unsigned offset = 0, uiSize;
        auto_seter(offset,uiSize,field0,obj.first_name,
                   field1,obj.second_name,
                   field2,obj.age,
                   field3,obj.weight,
                   field4,obj.height);
    }
};

void TestPerson(){
    Person p1 = {L"Ivan",L"Ivanov",30,80.4,179.3};
    rti1516e::VariableLengthData v = HLA::cast_to_rti<RTIPerson>(p1);
    Person p2 = HLA::cast_from_rti<RTIPerson>(v);
    ASSERT_EQUAL(p1.first_name,p2.first_name)
    ASSERT_EQUAL(p1.second_name,p2.second_name)
    ASSERT_EQUAL(p1.age,p2.age)
    ASSERT_EQUAL(p1.weight,p2.weight)
    ASSERT_EQUAL(p1.height,p2.height)
}

void TestRTIfixedRecord(){
    TestPosition();
    TestBook();
    TestJuice();
    TestPerson();
}
#endif // TETSRTIFIXEDRECORD_HPP
