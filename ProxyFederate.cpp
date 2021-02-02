#include "ProxyFederate.hpp"
#include <iostream>
#include "HLAdata/HLAdata.hpp"

namespace HLA {

    ProxyFederate::ProxyFederate(const JSON& file) noexcept : BaseFederate(file){}

//    bool ProxyFederate::operator()(const std::string& ip,
//                                   const std::vector<unsigned short>& ports,
//                                   const JSON& file){

//        _sockets.resize(ports.size());
//        _buffers.resize(ports.size());

//        for(size_t idx = 0; idx < _sockets.size(); ++idx){
//           _sockets[idx] = std::make_unique<udp_socket_t>(_context);
//           _sockets[idx]->open(boost::asio::ip::udp::v4());
//           _sockets[idx]->bind(udp_endpoint_t(boost::asio::ip::address::from_string(ip), ports[idx]));
//           Listen(idx);
//        }
////        _socket.open(boost::asio::ip::udp::v4());
////        const auto& sep =  ip.find(':');
////        std::string address = ip.substr(0, sep);
////        unsigned short port    = static_cast<unsigned short>(std::stoi(ip.substr(sep + 1, ip.size())));
////        std::cout << address << std::endl;
////        std::cout << port << std::endl;
////        _socket.bind(udp_endpoint_t(boost::asio::ip::address::from_string(address), port));


//        return ConnectRTI(file);
//    }

    bool ProxyFederate::operator()(const JSON &proxy_file,
                                   const JSON &hla_file){
        auto root = proxy_file.GetRoot()->AsMap();
        auto ip = root.at(L"IP")->AsWstring();
        _ports = JSON::ToMapUshortWstring(root.at(L"Ports"));
        for(const auto& port : _ports){
           _sockets[port.first] = std::make_unique<udp_socket_t>(_context);
           _sockets[port.first]->open(boost::asio::ip::udp::v4());
           _sockets[port.first]->bind(udp_endpoint_t(boost::asio::ip::address::from_string(std::string(ip.begin(), ip.end())), port.first));
           Listen(port.first);
        }
        return ConnectRTI(hla_file);
    }

    void ProxyFederate::RunFederate(){
        _context.run();
    }

    void ProxyFederate::Listen(unsigned short port){
        auto handle = [this, port](const udp_error_t& error, size_t size){
            if(error) return;
            double value;
            memcpy(&value, _buffers[port].data(), 8);
            rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Float64LE>(value);
            rti1516e::AttributeHandleValueMap map;
            map[_AttributesMap[_MyClass][_ports[port]]] = v;
            _rtiAmbassador->updateAttributeValues(_MyInstanceID, map, rti1516e::VariableLengthData());
            memcpy(&value, _buffers[port].data(), 8);
            std::cout << "Received: " << value << " with size = " << size << "\n";
            this->Listen(port);
        };
//        for(auto& socket : _sockets)
        _sockets[port]->async_receive_from(boost::asio::buffer(_buffers[port]),_endp, handle);
    }
}
