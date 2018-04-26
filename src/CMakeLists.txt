cmake_minimum_required(VERSION 3.10)
project(ahs)

set(CMAKE_CXX_STANDARD 17)

add_executable(ahs server.cpp async_acceptor.cpp async_acceptor.h async_session.cpp async_session.h http_header.cpp http_header.h)

set(BOOST_INCLUDE_DIRS $boost_installation_prefix/include)
target_include_directories(ahs PRIVATE ${BOOST_INCLUDE_DIRS})

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
target_link_libraries(ahs
${Boost_FILESYSTEM_LIBRARY}
${Boost_SYSTEM_LIBRARY}
${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

target_link_libraries(ahs -lpthread)



