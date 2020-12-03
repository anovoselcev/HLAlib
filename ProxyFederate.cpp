#include "ProxyFederate.hpp"
#include <iostream>


namespace HLA {

    ProxyFederate::ProxyFederate(const JSON& file) noexcept : BaseFederate(file){}

    bool ProxyFederate::operator()(const std::string& ip, const JSON& file){

        _socket.open(boost::asio::ip::udp::v4());
        const auto& sep =  ip.find(':');
        std::string address = ip.substr(0, sep);
        unsigned short port    = static_cast<unsigned short>(std::stoi(ip.substr(sep + 1, ip.size())));
        std::cout << address << std::endl;
        std::cout << port << std::endl;
        _socket.bind(udp_endpoint_t(boost::asio::ip::address::from_string(address), port));

        Listen();

        _context.run();
        //ConnectRTI(file)
        return true;
    }

    void ProxyFederate::RunFederate(){
        _context.run();
    }

    void ProxyFederate::Listen(){
        auto handle = [this](const udp_error_t& error, size_t size){
            if(error) return;
            rti1516e::VariableLengthData v;
            v.setData(_buffer.data(), size);
//            rti1516e::AttributeHandleValueMap map;
//            map[_AttributesMap[_MyClass].begin()->second] = v;
//            _rtiAmbassador->updateAttributeValues(_MyInstanceID, map, rti1516e::VariableLengthData());
            std::cout << "Received: '" << std::string(_buffer.begin(), _buffer.begin()+size) << "' (" << error.message() << ")\n";
            this->Listen();
        };

        _socket.async_receive_from(boost::asio::buffer(_buffer),_endp, handle);
    }
}
