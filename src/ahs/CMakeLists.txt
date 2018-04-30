file(GLOB SRC "*.cpp")
add_executable(ahs ${SRC})

set(BOOST_INCLUDE_DIRS $boost_installation_prefix/include)
target_include_directories(ahs PRIVATE ${BOOST_INCLUDE_DIRS})

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
target_link_libraries(ahs
${Boost_FILESYSTEM_LIBRARY}
${Boost_SYSTEM_LIBRARY}
${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

target_link_libraries(ahs -lpthread)

add_subdirectory(http)



