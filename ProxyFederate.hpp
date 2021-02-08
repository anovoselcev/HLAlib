#ifndef PROXYFEDERATE_HPP
#define PROXYFEDERATE_HPP

#include "BaseFederate.hpp"
#include "boost/asio.hpp"
#include <array>

namespace HLA {

    class ProxyFederate : public BaseFederate{
    public:
        ProxyFederate() = delete;

        ProxyFederate(const JSON& file) noexcept;

        ProxyFederate(JSON&& file) noexcept;

        bool StartProxy(const JSON& proxy_file,
                        const JSON& hla_file);


    private:

        using udp_socket_t     = boost::asio::ip::udp::socket;
        using udp_endpoint_t   = boost::asio::ip::udp::endpoint;
        using udp_error_t      = boost::system::error_code;

    protected:

        void Listen_attributes(unsigned short port);

        void Listen_interactions(unsigned short port);

        void WriteAttributes(unsigned short port, const rti1516e::VariableLengthData&);

        void WriteInteractions(unsigned short port, const rti1516e::VariableLengthData&);

        void RunFederate() override;

        void AttributeProcess(rti1516e::ObjectClassHandle &handle, rti1516e::AttributeHandleValueMap &data, rti1516e::VariableLengthData &info) override;

        void ParameterProcess(rti1516e::InteractionClassHandle &handle, rti1516e::ParameterHandleValueMap &data, rti1516e::VariableLengthData &info) override;

        boost::asio::io_context _context;
        udp_endpoint_t _endp;

        std::unordered_map<unsigned short, std::unique_ptr<udp_socket_t>> _sockets;

        std::unordered_map<unsigned short, std::wstring> _ports_pub_attributes;
        std::unordered_map<std::wstring, unsigned short> _attributes_sub_ports;
        std::unordered_map<unsigned short, std::wstring> _ports_sub_attributes;
        std::unordered_map<unsigned short, std::wstring> _ports_pub_interactions;
        std::unordered_map<unsigned short, std::wstring> _ports_sub_interactions;
        std::wstring ip_remote;
        std::unordered_map<unsigned short, std::array<char, 64>> _buffers;
    };
}


#endif // PROXYFEDERATE_HPP
