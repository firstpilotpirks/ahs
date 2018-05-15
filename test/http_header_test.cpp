#define BOOST_TEST_DYN_LINK

#include <iostream>

#include <boost/test/unit_test.hpp>

#include "ahs/http/http_header.hpp"

BOOST_AUTO_TEST_SUITE(http_header_test)

 template<template<class ...> class Dictionary, class Key>
 void constructor_init() {
   auto data = typename http_header<Dictionary, Key, Key>::header_data {
       {"param_1", "value_1"},
       {"param_2", "value_2"},
       {"param_3", "value_3"},
   };

   http_header<Dictionary, Key, Key> header(data);

   BOOST_CHECK_EQUAL(header["param_1"], "value_1");
   BOOST_CHECK_EQUAL(header["param_2"], "value_2");
   BOOST_CHECK_EQUAL(header["param_3"], "value_3");
 }

 BOOST_AUTO_TEST_CASE(constructor_init_std_map_std_string) {
   constructor_init<std::map, std::string>();
 }

 BOOST_AUTO_TEST_CASE(constructor_init_std_unordered_map_std_string) {
   constructor_init<std::unordered_map, std::string>();
 }

 BOOST_AUTO_TEST_CASE(constructor_init_std_map_std_string_view) {
   constructor_init<std::map, std::string_view>();
 }

 template<template<class ...> class Dictionary, class Key>
 void constructor_init_move() {
   http_header<Dictionary, Key, Key> header(
       typename http_header<Dictionary, Key, Key>::header_data {
           {"param_1", "value_1"},
           {"param_2", "value_2"},
           {"param_3", "value_3"},
       });

   BOOST_CHECK_EQUAL(header["param_1"], "value_1");
   BOOST_CHECK_EQUAL(header["param_2"], "value_2");
   BOOST_CHECK_EQUAL(header["param_3"], "value_3");
 }

 BOOST_AUTO_TEST_CASE(constructor_init_move_std_map_std_string) {
   constructor_init_move<std::map, std::string>();
 }

 BOOST_AUTO_TEST_CASE(constructor_init_move_std_unordered_map_std_string) {
   constructor_init_move<std::unordered_map, std::string>();
 }

 BOOST_AUTO_TEST_CASE(constructor_init_move_std_map_std_string_view) {
   constructor_init_move<std::map, std::string_view>();
 }

 template<template<class ...> class Dictionary, class Key>
 void access_to_element() {
   http_header header(typename http_header<Dictionary, Key, Key>::header_data {
       {"param_1", "value_1"},
       {"param_2", "value_2"},
       {"param_3", "value_3"},
   });

   std::string value_over_9002 {"value_over_9002"};
   char value_over_9003[] = {"value_over_9003"};

   header["param_1"] = "value_over_9001";
   header["param_2"] = value_over_9002;
   header["param_3"] = value_over_9003;

   BOOST_CHECK_EQUAL(header["param_1"], "value_over_9001");
   BOOST_CHECK_EQUAL(header["param_2"], value_over_9002);
   BOOST_CHECK_EQUAL(header["param_3"], value_over_9003);
 }

 BOOST_AUTO_TEST_CASE(access_to_element_std_map_std_string) {
   access_to_element<std::map, std::string>();
 }

 BOOST_AUTO_TEST_CASE(access_to_element_std_unordered_map_std_string) {
   access_to_element<std::unordered_map, std::string>();
 }

 BOOST_AUTO_TEST_CASE(access_to_element_std_map_std_string_view) {
   access_to_element<std::map, std::string_view>();
 }

 template<template<class ...> class Dictionary, class Key>
 void add_element() {
   http_header<Dictionary, Key, Key> header;

   std::string value_over_9002 {"value_over_9002"};
   char value_over_9003[] = {"value_over_9003"};

   header["param_1"] = "value_over_9001";
   header["param_2"] = value_over_9002;
   header["param_3"] = value_over_9003;

   BOOST_CHECK_EQUAL(header["param_1"], "value_over_9001");
   BOOST_CHECK_EQUAL(header["param_2"], value_over_9002);
   BOOST_CHECK_EQUAL(header["param_3"], value_over_9003);
 }

 BOOST_AUTO_TEST_CASE(add_element_std_map_std_string) {
   add_element<std::map, std::string>();
 }

 BOOST_AUTO_TEST_CASE(add_element_std_unordered_map_std_string) {
   add_element<std::unordered_map, std::string>();
 }

 BOOST_AUTO_TEST_CASE(add_element_std_map_std_string_view) {
   add_element<std::map, std::string_view>();
 }

BOOST_AUTO_TEST_SUITE_END()
