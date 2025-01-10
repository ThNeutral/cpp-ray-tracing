cmake_minimum_required(VERSION 3.16)

project(ray-tracing VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the main source files
set(SOURCES "${CMAKE_SOURCE_DIR}/main.cpp")
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(APPEND SOURCES ${SRC_FILES})

# Include all .cpp files in ./libs
file(GLOB_RECURSE LIB_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/libs/*.cpp")
list(APPEND SOURCES ${LIB_FILES})

# Uncomment and add headers if needed
# set(HEADERS
#     include/example.h
# )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Add include directories for headers
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC libs)