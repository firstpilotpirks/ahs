#ifndef HTTP_HEADER_H
#define HTTP_HEADER_H

#include <map>

#include "ahs/http/request_line.hpp"

template<template<class ...> class Dictionary, class Key, class T,
                             class ...Settings>
class http_header {
 public:
  using header_data = Dictionary<Key, T, Settings...>;

  using key_type = typename header_data::key_type;
  using mapped_type = typename header_data::mapped_type;
  using value_type = typename header_data::value_type;
  using size_type = typename header_data::size_type;

  http_header() = default;
  http_header(const http_header &header) = default;
  http_header(http_header &&header) = default;

  explicit http_header(const header_data &data)
      :
      _data(data) {
  }

  explicit http_header(header_data &&data)
      :
      _data(std::move(data)) {
  }

  mapped_type &operator[](const key_type &field) {
    return _data[field];
  }

  mapped_type &operator[](key_type &&field) {
    return _data[field];
  }

 private:
  header_data _data;
};

#endif // HTTP_HEADER_H
