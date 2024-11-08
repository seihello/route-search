#ifndef WEBSOCKET_SERVER_H
#define WEBSOCKET_SERVER_H

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>

namespace net = boost::asio;
namespace beast = boost::beast;
namespace websocket = beast::websocket;
using tcp = net::ip::tcp;

class WebSocketSession : public std::enable_shared_from_this<WebSocketSession> {
public:
    explicit WebSocketSession(tcp::socket socket);
    void start();

private:
    websocket::stream<tcp::socket> ws_;
    beast::flat_buffer buffer_;

    void on_accept(beast::error_code ec);
    void do_read();
    void on_read(beast::error_code ec, std::size_t bytes_transferred);
    void on_write(beast::error_code ec, std::size_t bytes_transferred);
};

class WebSocketServer {
public:
    WebSocketServer(net::io_context& ioc, tcp::endpoint endpoint);

private:
    tcp::acceptor acceptor_;

    void do_accept();
};

#endif // WEBSOCKET_SERVER_HPP
