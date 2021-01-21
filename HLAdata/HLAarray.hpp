#ifndef RTIARRAY_HPP
#define RTIARRAY_HPP

#include "BasicTemplates.hpp"

namespace HLA{

    template<typename HLAtype, unsigned Size, unsigned OBV>
    rti1516e::VariableLengthData cast_to_rti(const std::array<typename HLAtype::type,Size>& t);

    template<typename HLAtype, unsigned Size, unsigned OBV>
    typename std::array<typename HLAtype::type, Size> cast_from_rti(const rti1516e::VariableLengthData& v);

    template <class T_FOM, size_t uiDim, unsigned m_OBV, class T_MOD = class T_FOM::type>
    class Array : public ClassForRTI <std::array<T_MOD,uiDim>, m_OBV>{
        Array & operator = (const Array &) {
            return *this;
        }
    public:

        using type = T_MOD;
        using assertion_type = std::array<type, uiDim>;

        virtual ~Array() {
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
            memcpy(reinterpret_cast<void*>(ptrData), input_data, m_uiSizeData);
        }

        void getDataMax(void* input_data, unsigned long inSize){
            chekSize(input_data, inSize);
            if (ptrData != nullptr)
                delete[] ptrData;
            ptrData = new byte[m_uiSizeData];
            memcpy(reinterpret_cast<void*>(ptrData), input_data,m_uiSizeData);
        }

        void get(const std::array<T_MOD,uiDim> & inData) {
            unsigned uiSizeEl, uiSizeData, P;
            T_FOM tmpFOMobj;
            m_uiSizeData = 0;
            uiSizeData = 0;
            uiSizeEl = 0;
            for (size_t i = 0; i < uiDim - 1; i++) {
                tmpFOMobj.get(inData[i]);
                uiSizeEl = tmpFOMobj.getsize();
                P = Tools::getPendingBytes(uiSizeEl,m_OBV);
                uiSizeData += uiSizeEl + P;
            }
            tmpFOMobj.get(inData[uiDim - 1]);
            uiSizeEl = tmpFOMobj.getsize();
            m_uiSizeData = uiSizeData + uiSizeEl;
            if (ptrData)
                delete[] ptrData;
            ptrData = new byte[m_uiSizeData];
            uiSizeData = 0;
            for (size_t i = 0; i < uiDim - 1; i++) {
                tmpFOMobj.get(inData[i]);
                uiSizeEl = tmpFOMobj.setData(ptrData + uiSizeData);
                P = Tools::getPendingBytes(uiSizeEl,m_OBV);
                uiSizeData += uiSizeEl + P;
            }
            tmpFOMobj.get(inData[uiDim - 1]);
            uiSizeEl = tmpFOMobj.setData(ptrData + uiSizeData);
        }

        void get (Array<T_FOM,uiDim,m_OBV>& obj) {
            if (this != &obj) {
                m_uiSizeData = obj.m_uiSizeData;
                if (ptrData)
                    delete[] ptrData;
                ptrData = new byte[m_uiSizeData];
                obj.setData(ptrData, m_uiSizeData);
            }
        }

        void setDataToRTI(rti1516e::VariableLengthData &obj) {
            if (ptrData)  {
                obj.setData(ptrData, m_uiSizeData);
            }
            else
                throw std::runtime_error("HLAarray.setDataToRTI. NULL pointer.");
        }

        void setData(void* ptrDest, unsigned long inSize){
            if (m_uiSizeData != inSize) {
                std::stringstream wstrOut;
                wstrOut
                        << "HLAarray\n" << "The size of the data did not match. Must recive " << m_uiSizeData
                        << " recived " << inSize << " bytes";
                throw std::runtime_error(wstrOut.str());
            }
            if (ptrData)
                memcpy(ptrDest, ptrData, m_uiSizeData);
            else
                throw std::runtime_error("HLAarray.setData. NULL pointer.");
        }

        unsigned setData(void* ptrDest) const {
            if (ptrData)
                memcpy(ptrDest, ptrData, m_uiSizeData);
            else
                throw std::runtime_error("HLAarray.setData. NULL pointer.");
            return m_uiSizeData;
        }

        void set (std::array<T_MOD,uiDim>& obj){
            unsigned uiSizeEl, P;
            T_FOM objFOM;
            unsigned uiSizeData = 0;
            if (ptrData)  {
                for (size_t i = 0; i < uiDim; i++) {
                    objFOM.getDataMax(ptrData+uiSizeData, m_uiSizeData-uiSizeData);
                    objFOM.set(obj[i]);

                    uiSizeEl = objFOM.getsize();
                    P = Tools::getPendingBytes(uiSizeEl,m_OBV);
                    uiSizeData += uiSizeEl+P;
                }
            }
        }

        unsigned getsize() const {return m_uiSizeData;}
        unsigned getOctetBoundary(){return m_OBV;}

    private:
        byte* ptrData = nullptr;
        unsigned m_uiSizeData = 0;

        void chekSize(void* input_data, unsigned long inSize){
            m_uiSizeData = 0;
            if (inSize < m_uiSizeData) {
                throw std::runtime_error("HLAarray Data is exhausted before reading is complete!.");
            }
            unsigned uiSizeEl,P;
            T_FOM tmpT;
            for (size_t i = 0; i < uiDim; i++) {
                if (inSize < m_uiSizeData)
                    throw std::runtime_error("HLAarray Data is exhausted before reading is complete!.");
                try {
                    tmpT.getDataMax((reinterpret_cast<char*>(input_data)+m_uiSizeData), inSize-m_uiSizeData);
                }
                catch (std::runtime_error & ex) {
                    throw std::runtime_error(std::string("HLAarray") + ex.what());
                }
                uiSizeEl = tmpT.getsize();
                if (i != uiDim - 1) {
                    P = Tools::getPendingBytes(uiSizeEl,m_OBV);
                }
                else
                    P = 0;
                m_uiSizeData+=uiSizeEl + P;
            }
        }
    };

    template<typename HLAtype, unsigned Size, unsigned OBV>
    inline rti1516e::VariableLengthData cast_to_rti(const std::array<typename HLAtype::type,Size>& t){
        Array<HLAtype, Size, OBV> conv;
        rti1516e::VariableLengthData v;
        conv.get(t);
        conv.setDataToRTI(v);
        return v;
    }

    template<typename HLAtype, unsigned Size, unsigned OBV>
    inline typename std::array<typename HLAtype::type, Size> cast_from_rti(const rti1516e::VariableLengthData& v){
        Array<HLAtype, Size, OBV> conv;
        std::array<typename HLAtype::type, Size> t;
        conv.getDataFromRTI(v);
        conv.set(t);
        return t;
    }
}
#endif // RTIARRAY_HPP
