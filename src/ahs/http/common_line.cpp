#include "ahs/http/common_line.hpp"

common_line::common_line(std::string http_version)
    : http_version_(http_version) {
}

std::string common_line::get_protocol() {
  return http_version_;
}
