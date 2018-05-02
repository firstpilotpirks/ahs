cmake_minimum_required(VERSION 3.9.2)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)

set(GCC_WARNINGS
        "-Wall "
        "-Werror"
        "-Wpedantic"
        "-Wextra"
        "-Wduplicated-cond"
        "-Wduplicated-branches"
        "-Wlogical-op"
        "-Wrestrict"
        "-Wnull-dereference"
        "-Wold-style-cast"
        "-Wuseless-cast"
        "-Wdouble-promotion"
        "-Wshadow"
        "-Wformat=2"
        )

set(CLANG_WARNINGS
        "-Wall "
        "-Werror"
        "-Wpedantic"
        "-Wextra"
        "-Wnull-dereference"
        "-Wdouble-promotion"
        "-Wshadow"
        "-Wformat=2"
        )

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions(${CLANG_WARNINGS})
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_definitions(${GCC_WARNINGS})
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    message(FATAL_ERROR "Intel compiler don't support")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message(FATAL_ERROR "MSVC compiler don't support")
else()
    message(FATAL_ERROR "Unknown compiler")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

add_subdirectory(src)
add_subdirectory(test)



