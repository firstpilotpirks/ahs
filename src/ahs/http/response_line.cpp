#include "ahs/http/response_line.hpp"

response_line::response_line(std::string error_code, std::string error_status,
                             std::string http_version)
    : common_line(http_version), error_code_(error_code),
      error_status_(error_status) {
}

std::string response_line::get_status_code() {
  return error_code_;
}

std::string response_line::get_status_msg() {
  return error_status_;
}

