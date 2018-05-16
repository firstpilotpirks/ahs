file(GLOB SRC "*.cpp")
add_executable(test_runner ${SRC} http_header_parser_test.cpp)

set(BOOST_INCLUDE_DIRS $boost_installation_prefix/include)
target_include_directories(test_runner PRIVATE ${BOOST_INCLUDE_DIRS})

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
target_link_libraries(test_runner
${Boost_FILESYSTEM_LIBRARY}
${Boost_SYSTEM_LIBRARY}
${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

target_link_libraries(test_runner -lpthread)
#target_link_libraries(test_runner http)



