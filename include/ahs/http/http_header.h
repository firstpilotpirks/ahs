#ifndef HTTP_HEADER_H
#define HTTP_HEADER_H

#include <map>

class http_header
{
public:
    using header_data = std::map<std::string, std::string>;

    http_header(const http_header & header) = default;
    http_header(http_header && header) = default;

    explicit http_header(const header_data & data);
    explicit http_header(header_data && data);

    std::string & operator[](const std::string & field);
    std::string & operator[](std::string && field);

private:
    header_data _data;
};

#endif // HTTP_HEADER_H
