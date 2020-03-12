#include"Analyzer.hpp"
#include <QDebug>
#include <random>
#include "RTI/encoding/DataElement.h"

namespace UPIM{

	using namespace std;
	using namespace rti1516e;

    class Staff{
    public:
        HLA::Byte b = true;
        HLA::Float64BE f = 1.1;
        HLA::Integer16BE i = 1;
        HLA::String s = "abds";
        HLA::Char c = '-';
    };
    class RTIStaff : public HLA::BaseRTIFixedRecord<Staff,8>{
    public:
        // Получить данные из источника. Есть максимальный размер данных. (из RTI)
        void getDataMax(void* ptrSource, unsigned long uiMaxSize){
            HLA::RTIbyte  field0;
            HLA::RTIfloat64BE field1;
            HLA::RTIinteger16BE  field2;
            HLA::RTIstring field3;
            HLA::RTIchar field4;
            unsigned offset = 0;
            // Определяем размер поля данных
            F_offset< HLA::RTIbyte, HLA::RTIfloat64BE >(field0,field1,offset,ptrSource,uiMaxSize);
            F_offset< HLA::RTIfloat64BE, HLA::RTIinteger16BE >(field1,field2,offset,ptrSource,uiMaxSize);
            F_offset< HLA::RTIinteger16BE, HLA::RTIstring >(field2,field3,offset,ptrSource,uiMaxSize);
            F_offset< HLA::RTIstring, HLA::RTIchar >(field3,field4,offset,ptrSource,uiMaxSize);
            F_offsetLast< HLA::RTIchar >(field4,offset,ptrSource,static_cast<unsigned>(uiMaxSize));

            // Создаем новое поле данных и копируем туда данные;

            if (ptrData!=nullptr) delete[] ptrData;
            m_uiSizeData = offset;
            ptrData = new HLA::Octet[m_uiSizeData];
            memcpy(ptrData, ptrSource, m_uiSizeData);
        }
        //Получить из модельного новое RTI значение
        void get(Staff const &obj){
            HLA::RTIbyte  field0;
            HLA::RTIfloat64BE field1;
            HLA::RTIinteger16BE  field2;
            HLA::RTIstring field3;
            HLA::RTIchar field4;
            unsigned offset = 0, P, uiSize, mmOBV;
            m_uiSizeData=0;
            // 0-ое поле
            field0.get(obj.b);
            uiSize = field0.getsize();

            // 1-ое поле
            field1.get(obj.f);
            mmOBV = field1.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field1.getsize();
            // 2-ое поле
            field2.get(obj.i);
            mmOBV = field2.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field2.getsize();
            // 3-e поле
            field3.get(obj.s);
            mmOBV = field3.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field3.getsize();
            // 4-ое поле
            field4.get(obj.c);
            mmOBV = field3.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field4.getsize();

            offset += uiSize;
            m_uiSizeData = offset;
            if (ptrData!=nullptr) delete[] ptrData;
            ptrData = new HLA::Octet[m_uiSizeData];
            offset = 0;
            // 0-ое поле
            uiSize = field0.getsize();
            field0.setData(ptrData+offset,uiSize);
            // 1-ое поле
            mmOBV = field1.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field1.getsize();
            field1.setData(ptrData+offset,uiSize);
            // 2-ое поле
            mmOBV = field2.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field2.getsize();
            field2.setData(ptrData+offset,uiSize);
            // 3-е поле
            mmOBV = field3.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field3.getsize();
            field3.setData(ptrData+offset,uiSize);
            // 4-ое поле
            mmOBV = field4.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field4.getsize();
            field4.setData(ptrData+offset,uiSize);
        }
        //Получить из RTI-представления его модельное значение
        void set(Staff &obj){
            HLA::RTIbyte  field0;
            HLA::RTIfloat64BE field1;
            HLA::RTIinteger16BE  field2;
            HLA::RTIstring field3;
            HLA::RTIchar field4;
            //********************************************
            unsigned offset = 0, P, uiSize, mmOBV;
            //********************************************
            // 0-ое поле
            field0.getDataMax(ptrData+offset,m_uiSizeData-offset);
            field0.set(obj.b);
            uiSize = field0.getsize();
            // 1-ое поле
            mmOBV = field1.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            field1.getDataMax(ptrData+offset,m_uiSizeData-offset);
            field1.set(obj.f);
            uiSize = field1.getsize();
            // 2-ое поле
            mmOBV = field2.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            field2.getDataMax(ptrData+offset,m_uiSizeData-offset);
            field2.set(obj.i);
            uiSize = field2.getsize();
            // 3-е поле
            mmOBV = field3.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            field3.getDataMax(ptrData+offset,m_uiSizeData-offset);
            field3.set(obj.s);
            uiSize = field3.getsize();
            // 4-ое поле
            mmOBV = field4.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            field4.getDataMax(ptrData+offset,m_uiSizeData-offset);
            field4.set(obj.c);
            uiSize = field4.getsize();
        }
    };
	AnalyzerFederate::AnalyzerFederate() noexcept{}


	AnalyzerFederate::AnalyzerFederate(const wstring& name,
						 const wstring& type,
						 const wstring& FOMname,
						 const wstring& ip,
						 const wstring& fname) noexcept :
								 UPIMFederate(name,type,FOMname,ip,fname) {}


    AnalyzerFederate::AnalyzerFederate(wstring&& name,
                         wstring&& type,
                         wstring&& FOMname,
                         wstring&& ip,
                         wstring&& fname) noexcept :
                                 UPIMFederate(std::move(name),std::move(type),std::move(FOMname),std::move(ip),std::move(fname)){}


	void AnalyzerFederate::RunFederate(){
        SetWindow();
	}

	void AnalyzerFederate::SetWindow(){
//        std::default_random_engine e;
//        std::uniform_int_distribution<int> dU(0,10);
//        std::normal_distribution<double> dN(0,100);
//        std::mt19937 mt(e());
//        //e.seed(1212);
//        auto randomU = [&mt,&dU](){
//            return dU(mt);
//        };
//        auto randomN = [&mt,&dN](){
//            return dN(mt);
//        };
//        double t = randomN();
//        qDebug() << t << " " <<endl;
//        for(int i = 0;i<10000;i++){
//            wstring wname = to_wstring(i);
//            QString qname = QString(i);
//            _federates[wname] = DATA::DataFederate(qname,QString::fromStdString(to_string(randomU())),QString::fromStdString(to_string(randomU())));
//            _federates[wname].AddAttribute(DATA::DataAttribute(QString(i),qname,randomN()));
//            _federates[wname].AddAttribute(DATA::DataAttribute(QString(i+1),qname,randomN()));
//            _federates[wname].AddAttribute(DATA::DataAttribute(QString(i+1),qname,QString(i)+" "+qname));
//        }
        _federates[L"A"] = DATA::DataFederate("First","A","Test");
        _federates[L"B"] = DATA::DataFederate("Second","A","Test2");
        _federates[L"A"].AddAttribute(DATA::DataAttribute("A","First",13.5));
        _federates[L"A"].AddAttribute(DATA::DataAttribute("C","First",20));
        _federates[L"A"].AddAttribute(DATA::DataAttribute("B","First","A"));
        _federates[L"B"].AddAttribute(DATA::DataAttribute("A","Second",-0.33));
        _federates[L"C"] = DATA::DataFederate("Third","B","Test3");
        _federates[L"C"].AddAttribute(DATA::DataAttribute("A","Third",-33));
        _MainWindow = make_unique<GRAPH::MainWindow>();
        _MainWindow->SetTree();
        _MainWindow->show();
////        qDebug() <<"Load factor = "<< _federates.load_factor() << endl;
       _MainWindow->SetInitialMap(_federates);
       VariableLengthData v1,v2,v3;
       Staff d,p;
       //v.setData(d,20);

       RTIStaff s;
       d.f = 200.13213;
       d.b = false;
       s.get(d);
       s.setDataToRTI(v1);
       RTIStaff r;
       r.getDataFromRTI(v1);
       r.set(p);
       qDebug() << p.b << " " << p.f << " " << QString::fromStdString(p.s) << endl;
       AttributeHandleValueMap m;
       m[_AttributesMap[_MyClass][L"Aim"]] = v1;
       qDebug() << v1.data() << endl;

       HLA::RTIASCIIstring str;
       std::vector<HLA::Char> vec(100,'2');
       HLA::RTIvariableArray<HLA::RTIchar,HLA::Char> varr;
       HLA::RTIFixedArray<HLA::RTIchar,HLA::Char,100,2> arr;
       varr.get(vec);
       varr.setDataToRTI(v2);
       m[_AttributesMap[_MyClass][L"Var"]] = v2;
       std::array<HLA::Char,100> a;
       a.fill('2');
       arr.get(a);
       arr.setDataToRTI(v3);
       m[_AttributesMap[_MyClass][L"Ar"]] = v3;
        _rtiAmbassador->updateAttributeValues(_MyInstanceID,m,VariableLengthData());
	}

    void AnalyzerFederate::UpdateAttributes() const {

    }

    void AnalyzerFederate::reflectAttributeValues(ObjectInstanceHandle theObject,
                                                  const AttributeHandleValueMap &theAttributeValues,
                                                  const VariableLengthData &theUserSuppliedTag,
                                                  OrderType sentOrder,
                                                  TransportationType theType,
                                                  SupplementalReflectInfo theReflectInfo)
    throw (FederateInternalError){
        Staff d;
        RTIStaff t;
        HLA::RTIvariableArray<HLA::RTIchar,HLA::Char> varr;
        HLA::RTIFixedArray<HLA::RTIchar,HLA::Char,100,2> arr;
        std::vector<HLA::Char> vec;
        std::array<HLA::Char,100> a;
        t.getDataFromRTI(theAttributeValues.find(_AttributesMap[_MyClass][L"Aim"])->second);
        varr.getDataFromRTI(theAttributeValues.find(_AttributesMap[_MyClass][L"Var"])->second);
        arr.getDataFromRTI(theAttributeValues.find(_AttributesMap[_MyClass][L"Ar"])->second);
        t.set(d);
        varr.set(vec);
        arr.set(a);
        qDebug()<< QString::fromStdString(d.s) <<" "<< d.c <<endl;
        qDebug() << vec[0] <<" "<<vec[3] << " " << vec.size() << endl;
        qDebug() << a[0] << " " << a[33] <<endl;
    }
}
