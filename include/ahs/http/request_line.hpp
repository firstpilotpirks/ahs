#ifndef PROJECT_REQUEST_LINE_HPP
#define PROJECT_REQUEST_LINE_HPP

#include "ahs/http/common_line.hpp"

class request_line : public common_line {
 public:
  request_line(const request_line &line) = default;
  request_line(request_line &&line) = default;
  request_line(std::string method, std::string path, std::string http_version);

  std::string get_method();
  std::string get_path();

 private:
  std::string method_;
  std::string path_;
  std::string http_version_;
};

#endif //PROJECT_REQUEST_LINE_HPP
