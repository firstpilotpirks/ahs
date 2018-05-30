#ifndef PROJECT_RESPONSE_LINE_HPP
#define PROJECT_RESPONSE_LINE_HPP

#include "ahs/http/common_line.hpp"

class response_line : public common_line {
 public:
  response_line(const response_line &line) = default;
  response_line(response_line &&line) = default;
  response_line(std::string error_code, std::string error_status,
                std::string http_version);

  std::string get_status_code();
  std::string get_status_msg();

 private:
  std::string error_code_;
  std::string error_status_;
};

#endif //PROJECT_RESPONSE_LINE_HPP
