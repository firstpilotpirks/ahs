#include "ahs/http/request_line.hpp"

request_line::request_line(std::string method, std::string path,
                           std::string http_version)
    : common_line(http_version), method_(method), path_(path) {
}

std::string request_line::get_method() {
  return method_;
}

std::string request_line::get_path() {
  return path_;
}

