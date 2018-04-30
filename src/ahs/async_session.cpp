#include <boost/range/iterator.hpp>
#include <boost/algorithm/string.hpp>

#include "ahs/async_session.h"

async_session::async_session(boost::asio::io_service &service) :
        _service(service)
{

}

void async_session::async_run(socket_ptr sock, std::shared_ptr<async_session> session)
{
    _session = session;
    _socket = sock;

    auto data = std::make_shared<boost::asio::streambuf>();
    start_read_header(data);
}

void handler(
  // Result of operation.
  const boost::system::error_code& error,

  // The number of bytes in the streambuf's get
  // area up to and including the delimiter.
  // 0 if an error occurred.
  std::size_t bytes_transferred
)
{

}

void async_session::start_read_header(const std::shared_ptr<boost::asio::streambuf> data)
{

//    boost::asio::streambuf b;
//    std::istream is(&b);
//    boost::asio::async_read_until(*_socket, b, "\n\r", handler);

    async_read_until(*_socket, *data, "\r\n\r\n", boost::bind(&async_session::handler_read_header,
                                                                              this,
                                                                              _1,
                                                                              _2,
                                                                              data));

//    _socket->async_read_some(boost::asio::buffer(*data),
//                          boost::bind(&handler_read_header, this, boost::asio::placeholders::error,
//                                      boost::asio::placeholders::bytes_transferred, data));
}

void async_session::handler_write(const boost::system::error_code &err)
{
    if (err)
    {
        return;
    }

}

void async_session::handler_read_header(const boost::system::error_code &error,
                                        size_t bytes_transferred, std::shared_ptr<boost::asio::streambuf> data)
{
    if (error)
    {
        return;
    }

    std::istream is(data.get());
    std::string header(std::istreambuf_iterator<char>(is), {});

    start_header_parser(header);
}

void async_session::start_header_parser(const std::string header)
{
    _service.post(boost::bind(&async_session::handler_header_parser, this, header));
}

void async_session::handler_header_parser(const std::string header)
{
    typedef std::vector<std::string> split_vector_type;
    typedef std::map<std::string, std::string> split_value_type;

    split_vector_type lines;
    boost::split(lines, header, boost::is_any_of("\r\n"), boost::token_compress_on);

    split_value_type header_parameter;
    for(auto & line : lines)
    {
        split_vector_type key_and_value;
        boost::split(key_and_value, line, boost::is_any_of(":"), boost::token_compress_on);
        if(key_and_value.size() == 2)
        {
            header_parameter[key_and_value.at(0)] = key_and_value.at(1);
        }
    }

    for(auto  & parameter: header_parameter)
    {
        std::cout << parameter.first << "=" << parameter.second << std::endl;
    }
}

