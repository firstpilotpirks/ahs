#ifndef HTTP_HEADER_H
#define HTTP_HEADER_H

#include <map>

class http_header
{
public:
    using header_data = std::map<std::string, std::string>;

    http_header(header_data & data);
    http_header(header_data && data);

    std::string & operator[](const std::string &field);
    std::string & operator[](std::string &&field);

private:
    header_data _data;
};


#endif // HTTP_HEADER_H
