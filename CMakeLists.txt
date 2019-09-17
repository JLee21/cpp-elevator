cmake_minimum_required(VERSION 2.6)
project(elevator)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(elevator ${SOURCES})

set_property(TARGET elevator PROPERTY CXX_STANDARD 17)
target_link_libraries(elevator ${CURSES_LIBRARIES})
# TODO: Run -Werror in CI.
target_compile_options(elevator PRIVATE -Wall -Wextra)
