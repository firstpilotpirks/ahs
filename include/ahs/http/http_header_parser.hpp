#ifndef PROJECT_HTTP_HEADER_PARSER_HPP
#define PROJECT_HTTP_HEADER_PARSER_HPP

#include <vector>
#include <iostream>

#include <boost/algorithm/string.hpp>

#include "http_header.hpp"

class http_header_parser
{
 public:
  http_header_parser() = default;
  http_header_parser(const http_header_parser & parser) = default;
  http_header_parser(http_header_parser && parser) = default;

  template <class S>
  http_header<std::map, std::string, std::string> parse(S raw_header){
    typedef std::vector<std::string> split_vector_type;
    typedef std::map<std::string, std::string> split_value_type;

    split_vector_type lines;
    boost::split(lines, raw_header, boost::is_any_of("\r\n"), boost::token_compress_on);

    split_value_type header_parameter;
    for(auto & line : lines)
    {
        auto n = line.find(':');
        if (n != line.npos)
        {
          header_parameter[line.substr(0, n)] =
              line.substr(n + 1, line.size() - n);
        }
    }

    http_header<std::map, std::string, std::string> header;
    for(auto  & parameter: header_parameter)
    {
      auto key = boost::trim_copy(parameter.first);
      auto value = boost::trim_copy(parameter.second);

      header[key] = value;
    }

    return header;
  }

 private:
};

#endif //PROJECT_HTTP_HEADER_PARSER_HPP
