#ifndef PROXYFEDERATE_HPP
#define PROXYFEDERATE_HPP

#include "BaseFederate.hpp"
#include "3dparty/boost_1_74_0/boost/asio.hpp"
#include <array>

namespace HLA {

    class ProxyFederate : public BaseFederate{
    public:
        ProxyFederate() = delete;

        ProxyFederate(const JSON& file) noexcept;

        ProxyFederate(JSON&& file) noexcept;

        bool operator()(const std::string& ip, const JSON& file);


    private:

        using udp_socket_t     = boost::asio::ip::udp::socket;
        using udp_endpoint_t   = boost::asio::ip::udp::endpoint;
        using udp_error_t      = boost::system::error_code;

    protected:

        void Listen();

        void RunFederate() override;

        boost::asio::io_context _context;
        udp_endpoint_t _endp;
        udp_socket_t _socket{_context};
        std::array<char, 256> _buffer;
    };
}


#endif // PROXYFEDERATE_HPP
