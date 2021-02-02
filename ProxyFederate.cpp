#include "ProxyFederate.hpp"
#include <iostream>


namespace HLA {

    ProxyFederate::ProxyFederate(const JSON& file) noexcept : BaseFederate(file){}

    bool ProxyFederate::operator()(const std::string& ip,
                                   const std::vector<unsigned short>& ports,
                                   const JSON& file){

        _sockets.resize(ports.size());
        _buffers.resize(ports.size());

        for(size_t idx = 0; idx < _sockets.size(); ++idx){
           _sockets[idx] = std::make_unique<udp_socket_t>(_context);
           _sockets[idx]->open(boost::asio::ip::udp::v4());
           _sockets[idx]->bind(udp_endpoint_t(boost::asio::ip::address::from_string(ip), ports[idx]));
           Listen(idx);
        }
//        _socket.open(boost::asio::ip::udp::v4());
//        const auto& sep =  ip.find(':');
//        std::string address = ip.substr(0, sep);
//        unsigned short port    = static_cast<unsigned short>(std::stoi(ip.substr(sep + 1, ip.size())));
//        std::cout << address << std::endl;
//        std::cout << port << std::endl;
//        _socket.bind(udp_endpoint_t(boost::asio::ip::address::from_string(address), port));


        return ConnectRTI(file);
    }

    void ProxyFederate::RunFederate(){
        _context.run();
    }

    void ProxyFederate::Listen(size_t idx){
        auto handle = [this, idx](const udp_error_t& error, size_t size){
            if(error) return;
            rti1516e::VariableLengthData v;
            v.setData(_buffers[idx].data(), size);
//            rti1516e::AttributeHandleValueMap map;
//            map[_AttributesMap[_MyClass].begin()->second] = v;
//            _rtiAmbassador->updateAttributeValues(_MyInstanceID, map, rti1516e::VariableLengthData());
            double value;
            memcpy(&value, _buffers[idx].data(), 8);
            std::cout << "Received: '" << value << " with size = " << size << "' (" << error.message() << ")\n";
            this->Listen(idx);
        };
//        for(auto& socket : _sockets)
        _sockets[idx]->async_receive_from(boost::asio::buffer(_buffers[idx]),_endp, handle);
    }
}
