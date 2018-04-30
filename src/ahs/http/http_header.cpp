#include "ahs/http/http_header.h"

http_header::http_header(http_header::header_data &data) :
_data(data)
{

}

http_header::http_header(http_header::header_data &&data):
_data(std::move(data))
{

}

std::string & http_header::operator[](const std::string &field)
{
    return _data[field];
}

std::string & http_header::operator[](std::string &&field)
{
    return _data[field];
}
