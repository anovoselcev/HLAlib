#include"Analyzer.hpp"
#include <QDebug>
#include <random>
namespace UPIM{

	using namespace std;
	using namespace rti1516e;

    class Staff{
    public:
        HLA::Byte b = true;
        HLA::Float64BE f = 1.1;
        HLA::Integer16BE i = 1;
    };

    class RTIStaff : public HLA::BaseRTIFixedRecord<Staff,8>{
    public:
        // Получить данные из источника. Есть максимальный размер данных. (из RTI)
        void getDataMax(void* ptrSource, unsigned long uiMaxSize) noexcept(false){
            HLA::RTIbyte  field0;
            HLA::RTIfloat64BE field1;
            HLA::RTIinteger16BE  field2;
            unsigned offset = 0;
            // Определяем размер поля данных
            F_offset< HLA::RTIbyte, HLA::RTIfloat64BE >(field0,field1,offset,ptrSource,uiMaxSize);
            F_offset< HLA::RTIfloat64BE, HLA::RTIinteger16BE >(field1,field2,offset,ptrSource,uiMaxSize);
            F_offsetLast< HLA::RTIinteger16BE >(field2,offset,ptrSource,static_cast<unsigned>(uiMaxSize));

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
            //  qDebug() << "Field 0 done" <<endl;
            //********************************************
            unsigned offset = 0, P, uiSize, mmOBV;
            m_uiSizeData=0;
            //********************************************
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
            // 3-ое поле

            offset += uiSize;
            //---------------------------------------------
            m_uiSizeData = offset;
            ///////////////////////////////////////////////
            if (ptrData!=nullptr) delete[] ptrData;
            ptrData = new HLA::Octet[m_uiSizeData];
            ///////////////////////////////////////////////
            offset = 0;
            // 0-ое поле
            uiSize = field0.getsize();
            //********************************************
            field0.setData(ptrData+offset,uiSize);
            //********************************************
            // 1-ое поле
            mmOBV = field1.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field1.getsize();
            //********************************************
            field1.setData(ptrData+offset,uiSize);
            //********************************************
            // 2-ое поле
            mmOBV = field2.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = field2.getsize();
            //********************************************
            field2.setData(ptrData+offset,uiSize);
            //********************************************
            // 3-ое поле
        }
        //Получить из RTI-представления его модельное значение
        void set(Staff &obj){
            HLA::RTIbyte  field0;
            HLA::RTIfloat64BE field1;
            HLA::RTIinteger16BE  field2;
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
       VariableLengthData v;
       Staff d,p;
       //v.setData(d,20);
       //AttributeHandleValueMap m;
       //m[_AttributesMap[_MyClass][L"Opa"]] = v;
       //qDebug() << v.data() << endl;
       //_rtiAmbassador->updateAttributeValues(_MyInstanceID,m,VariableLengthData());
       RTIStaff s;
       d.f = 200.13213;
       d.b = false;
       s.get(d);
       s.setDataToRTI(v);
       //s.getDataFromRTI(v);
       RTIStaff r;
       r.getDataFromRTI(v);
       r.set(p);
       qDebug() << p.b << " " << p.f << endl;
	}

    void AnalyzerFederate::UpdateAttributes() const {

    }

}
