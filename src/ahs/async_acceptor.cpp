#include "ahs/async_acceptor.h"

async_acceptor::async_acceptor(boost::asio::io_service &service) :
        _service(service)
{
}

void async_acceptor::async_run()
{
    _ep = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 2001);
    _acc = std::make_shared<boost::asio::ip::tcp::acceptor>(_service, _ep);
    _socket = std::make_shared<boost::asio::ip::tcp::socket>(_service);

    start_acceptor();
}

void async_acceptor::start_acceptor()
{
    _acc->async_accept(*_socket, boost::bind(&async_acceptor::handler_acceptor, this, _1));
}

void async_acceptor::handler_acceptor(const boost::system::error_code &err)
{
    if (err)
    {
        return;
    }

    auto session = std::make_shared<async_session>(_service);
    session->async_run(_socket, session);

    _socket = std::make_shared<boost::asio::ip::tcp::socket>(_service);
    start_acceptor();
}
