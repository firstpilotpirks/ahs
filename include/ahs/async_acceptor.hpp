#ifndef ASYNC_ACCEPTOR_H
#define ASYNC_ACCEPTOR_H

#include <ctime>

#include <iostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "async_session.hpp"

class async_acceptor
{
public:
    async_acceptor(boost::asio::io_service &service);

    void async_run();

private:
    boost::asio::io_service &_service;
    boost::asio::ip::tcp::endpoint _ep;
    std::shared_ptr<boost::asio::ip::tcp::acceptor> _acc;
    std::shared_ptr<boost::asio::ip::tcp::socket> _socket;

    void start_acceptor();

    void handler_acceptor(const boost::system::error_code &err);
};


#endif // ASYNC_ACCEPTOR_H
