#include "WebsocketServer.h"
#include <iostream>

// WebSocketSessionの実装
WebSocketSession::WebSocketSession(tcp::socket socket)
    : ws_(std::move(socket)) {}

void WebSocketSession::start() {
    ws_.async_accept(
        beast::bind_front_handler(
            &WebSocketSession::on_accept,
            shared_from_this()));
}

void WebSocketSession::on_accept(beast::error_code ec) {
    if (ec) {
        std::cerr << "Accept Error: " << ec.message() << std::endl;
        return;
    }

    do_read();
}

void WebSocketSession::do_read() {
    ws_.async_read(
        buffer_,
        beast::bind_front_handler(
            &WebSocketSession::on_read,
            shared_from_this()));
}

void WebSocketSession::on_read(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if (ec == websocket::error::closed) {
        return;
    }

    if (ec) {
        std::cerr << "Read Error: " << ec.message() << std::endl;
        return;
    }

    ws_.text(ws_.got_text());
    ws_.async_write(
        buffer_.data(),
        beast::bind_front_handler(
            &WebSocketSession::on_write,
            shared_from_this()));
}

void WebSocketSession::on_write(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if (ec) {
        std::cerr << "Write Error: " << ec.message() << std::endl;
        return;
    }

    buffer_.consume(buffer_.size());
    do_read();
}

WebSocketServer::WebSocketServer(net::io_context& ioc, tcp::endpoint endpoint)
    : acceptor_(ioc, endpoint) {
    do_accept();
}

void WebSocketServer::do_accept() {
    acceptor_.async_accept(
        [this](beast::error_code ec, tcp::socket socket) {
            if (!ec) {
                std::make_shared<WebSocketSession>(std::move(socket))->start();
            }
            do_accept();
        });
}
