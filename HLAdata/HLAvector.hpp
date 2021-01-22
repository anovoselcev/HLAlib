#ifndef RTIVECTOR_HPP
#define RTIVECTOR_HPP

#include "BasicTemplates.hpp"

namespace HLA {

    template<typename HLAtype, unsigned OBV>
    rti1516e::VariableLengthData cast_to_rti(const std::vector<typename HLAtype::type>& t);

    template<typename HLAtype, unsigned OBV>
    std::vector<typename HLAtype::type> cast_from_rti(const rti1516e::VariableLengthData& v);

    template <typename T_FOM, unsigned m_OBV = 1, typename T_MOD = typename T_FOM::type, bool Easy = std::is_integral<T_MOD>::value || std::is_floating_point<T_MOD>::value>
    class Vector final: public ClassForRTI<std::vector<T_MOD>,m_OBV>
    {
        Vector& operator = (const Vector &) {
            return *this;
        }

    public:

        using type = T_MOD;
        using assertion_type = std::vector<type>;

        virtual ~Vector() {
            if (ptrData) {
                delete[] ptrData;
                ptrData=nullptr;
            }
        }

        void getDataFromRTI(const rti1516e::VariableLengthData &obj){
            getData(const_cast<void*>(obj.data()), static_cast<unsigned long>(obj.size()));
        }

        void getData(void* input_data, unsigned long inSize){

            chekSize(input_data, inSize);

            if (ptrData)
                delete[] ptrData;
            ptrData = new byte[m_uiSizeData];
            memcpy(ptrData, input_data, m_uiSizeData);
        }

        void getDataMax(void* input_data, unsigned long inSize){
            chekSize(input_data, inSize);
            if (ptrData)
                delete[] ptrData;
            ptrData = new byte[m_uiSizeData];
            memcpy(ptrData, input_data, m_uiSizeData);
        }

        void get(const std::vector<T_MOD> & inData) {
            unsigned uiSizeEl = 0,
                    uiSizeData = 4,
                    P = 0,
                    uiHeader;

            T_FOM tmpFOBobj;

            m_uiSizeData = 0;

            m_DIM = static_cast<size_t>(inData.size());

            if(Easy){
                if (ptrData)
                    delete[] ptrData;
                m_uiSizeData = 4 + sizeof (T_MOD) * m_DIM;
                ptrData = new byte[m_uiSizeData];
                uiHeader = m_DIM;
                memcpy(ptrData, &uiHeader, 4);
               // memcpy(ptrData + 4, inData.data(), m_uiSizeData - 4);
            }
            else{

                if (m_DIM) {
                    for (size_t i = 0; i < m_DIM - 1; i++) {
                        tmpFOBobj.get(inData[i]);
                        uiSizeEl = tmpFOBobj.getsize();
                        P = Tools::getPendingBytes(uiSizeEl, m_OBV);
                        uiSizeData += uiSizeEl + P;
                    }
                    tmpFOBobj.get(inData[m_DIM - 1]);
                    uiSizeEl = tmpFOBobj.getsize();
                }
                else {
                    uiSizeEl = 0;
                    P = 0;
                }

                m_uiSizeData = uiSizeData + uiSizeEl;

                if (ptrData)
                    delete[] ptrData;
                ptrData = new byte[m_uiSizeData];

                uiHeader = m_DIM;

                uiSizeData = 4;
                memcpy(ptrData, &uiHeader, 4);

                if (m_DIM) {
                    for (size_t i = 0; i < m_DIM - 1; i++) {
                        tmpFOBobj.get(inData[i]);
                        uiSizeEl = tmpFOBobj.setData(ptrData + uiSizeData);
                        P = Tools::getPendingBytes(uiSizeEl,m_OBV);
                        uiSizeData += uiSizeEl + P;
                    }
                    tmpFOBobj.get(inData[m_DIM - 1]);
                    uiSizeEl = tmpFOBobj.setData(ptrData + uiSizeData);
                }
            }
        }

        void get (Vector<T_FOM,m_OBV>& obj) {

            if (this != &obj) {
                m_DIM = obj.m_DIM;
                m_uiSizeData = obj.m_uiSizeData;
                if (ptrData)
                    delete[] ptrData;
                ptrData = new byte[m_uiSizeData];
                obj.setData(ptrData,m_uiSizeData);
            }
        }

        void setDataToRTI(rti1516e::VariableLengthData &obj){
            if (ptrData)  {
                obj.setData(ptrData,m_uiSizeData);
            } else
                throw std::runtime_error("HLAvector.setDataToRTI. ) NULL pointer.");
        }

        void setData(void* ptrDest, unsigned long inSize){
            if (m_uiSizeData != inSize) {
                std::stringstream wstrOut;
                wstrOut
                        << "HLAvector\n" << "The size of the data did not match. Must recive " << m_uiSizeData
                        << " recived "<< inSize << " bytes";
                throw std::runtime_error(wstrOut.str());
            }

            if (ptrData)  {
                memcpy(ptrDest, ptrData, m_uiSizeData);
            }
            else
                throw std::runtime_error("HLAvector.setData. NULL pointer.");
        }

        unsigned setData(void* ptrDest) const {

            if (ptrData)  {
                memcpy(ptrDest, ptrData, m_uiSizeData);
            } else
                throw std::runtime_error("HLAvector.setData. NULL pointer.");
            return m_uiSizeData;
        }

        void set(std::vector<T_MOD>& outData) {

            unsigned uiSizeOfVector;
            memcpy(&uiSizeOfVector, ptrData, 4);
            Tools::changeENDIAN(uiSizeOfVector);
            outData.resize(m_DIM);
            if(Easy){
               // T_MOD* pointer = reinterpret_cast<T_MOD*>(outData.data());
               // memcpy(pointer, ptrData + 4, sizeof (T_MOD) * m_DIM);
                //std::copy(ptrData + 4, ptrData + m_uiSizeData - sizeof (T_MOD), outData);
            }
            else{
                T_MOD obj;
                T_FOM objFOM;
                unsigned uiSizeEl, P;
                unsigned uiSizeData = 4;
                for (size_t i = 0; i < m_DIM; i++) {
                    objFOM.getDataMax(ptrData + uiSizeData, m_uiSizeData - uiSizeData);
                    objFOM.set(obj);
                    outData[i] = std::move(obj);
                    uiSizeEl = objFOM.getsize();
                    P = Tools::getPendingBytes(uiSizeEl,m_OBV);
                    uiSizeData += uiSizeEl + P;
                }
            }
        }

        std::vector<T_MOD> get() {
            std::vector<T_MOD> vRet;
            set(vRet);
            return vRet;
        }

        unsigned getsize() const {return m_uiSizeData;}

        unsigned getOctetBoundary(){return m_OBV;}

    private:
        byte* ptrData = nullptr;
        unsigned m_uiSizeData = 0;
        size_t m_DIM = 0;

        void chekSize(void* input_data, unsigned long inSize) /*noexcept(false)*/ {
            m_uiSizeData = 4;
            if (inSize < m_uiSizeData) {
                throw std::runtime_error("HLAvector Data is exhausted before reading is complete!.");
            }
            memcpy(&m_DIM, input_data,m_uiSizeData);
            unsigned uiSizeEl,P;
            T_FOM tmpT;
            for (size_t i = 0; i < m_DIM; i++) {
                if (inSize <= m_uiSizeData) {
                    throw std::runtime_error("HLAvector Data is exhausted before reading is complete!.");
                }
                try {
                    tmpT.getDataMax(static_cast<char*>(input_data)+m_uiSizeData, inSize-m_uiSizeData);
                }
                catch (std::runtime_error & ex) {
                    throw std::runtime_error(std::string("HLAvector") +ex.what());
                }
                uiSizeEl = tmpT.getsize();
                if (i != m_DIM - 1) {
                    P = Tools::getPendingBytes(uiSizeEl,m_OBV);
                }
                else
                    P = 0;
                m_uiSizeData+=uiSizeEl+P;
            }
        }
    };


    template<typename HLAtype, unsigned OBV>
    rti1516e::VariableLengthData cast_to_rti(const std::vector<typename HLAtype::type>& t){
        Vector<HLAtype,OBV> conv;
        rti1516e::VariableLengthData v;
        conv.get(t);
        conv.setDataToRTI(v);
        return v;
    }

    template<typename HLAtype, unsigned OBV>
    std::vector<typename HLAtype::type> cast_from_rti(const rti1516e::VariableLengthData& v){

        std::vector<typename HLAtype::type> t;
        Vector<HLAtype, OBV> conv;
        conv.getDataFromRTI(v);
        conv.set(t);
        return t;
    }

}
#endif // RTIVECTOR_HPP
