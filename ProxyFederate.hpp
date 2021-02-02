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

        bool operator()(const std::string& ip,
                        const std::vector<unsigned short>& ports,
                        const JSON& file);


    private:

        using udp_socket_t     = boost::asio::ip::udp::socket;
        using udp_endpoint_t   = boost::asio::ip::udp::endpoint;
        using udp_error_t      = boost::system::error_code;

    protected:

        void Listen(size_t idx);

        void RunFederate() override;

        boost::asio::io_context _context;
        udp_endpoint_t _endp;
        std::vector<std::unique_ptr<udp_socket_t>> _sockets;
       // udp_socket_t _socket{_context};
        std::vector<std::array<char, 64>> _buffers;
    };
}


#endif // PROXYFEDERATE_HPP
