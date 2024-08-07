cmake_minimum_required(VERSION 3.9)
project(format_json C)

add_definitions(-O3 -Wall)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")

set(SOURCES
	src/main.c
)

find_package(LIBUBOX REQUIRED)
find_library(JSON_LIBRARIES NAMES json-c)

set(_LINK ${LIBUBOX_LIBRARIES} ${JSON_LIBRARIES})
set(_INCLUDE ${CMAKE_BINARY_DIR})

add_executable(format_json ${SOURCES})
target_link_libraries(format_json ${_LINK})
target_include_directories(format_json PRIVATE ${_INCLUDE})

install(TARGETS format_json RUNTIME DESTINATION bin)
