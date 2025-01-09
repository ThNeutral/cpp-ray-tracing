cmake_minimum_required(VERSION 3.16)

project(ray-tracing VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SOURCES "${CMAKE_SOURCE_DIR}/main.cpp")
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(APPEND SOURCES ${SRC_FILES})

# set(HEADERS
#     include/example.h
# )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC include)