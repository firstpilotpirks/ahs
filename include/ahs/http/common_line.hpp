#ifndef PROJECT_COMMON_LINE_HPP
#define PROJECT_COMMON_LINE_HPP

#include <string>

class common_line {
 public:
  common_line(const common_line &line) = default;
  common_line(common_line &&line) = default;
  common_line(std::string http_version);

  virtual std::string get_protocol();

 private:
  std::string http_version_;
};

#endif //PROJECT_COMMON_LINE_HPP
