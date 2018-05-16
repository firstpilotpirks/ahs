#ifndef ASYNC_SESSION_H
#define ASYNC_SESSION_H

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

typedef std::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

class async_session
{
public:
    async_session(boost::asio::io_service &service);

    void async_run(socket_ptr sock, std::shared_ptr<async_session> session);

private:
    boost::asio::io_service &_service;
    std::shared_ptr<async_session> _session;
    std::shared_ptr<boost::asio::ip::tcp::socket> _socket;

    void start_read_header(const std::shared_ptr<boost::asio::streambuf> data);
    void handler_write(const boost::system::error_code &err);

    void handler_read_header(const boost::system::error_code &error,
                             size_t bytes_transferred, std::shared_ptr<boost::asio::streambuf> data);

    void start_header_parser(const std::string header);
    void handler_header_parser(const std::string raw_header);
};


#endif // ASYNC_SESSION_H
