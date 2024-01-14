cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
cmake_policy(SET CMP0048 NEW)

set(PROJECT "coursera_courses")
project(${PROJECT} VERSION "0.0.1")

# where to search for external CMAKE modules
# add protobuf to find_package search path
#list( APPEND CMAKE_PREFIX_PATH "/opt/protobuf-3.13.0" )

# build with cpp 17
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# global settings
set(CMAKE_VERBOSE_MAKEFILE ON)
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS=1)

# add sanitizers
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -fno-omit-frame-pointer -fno-optimize-sibling-calls")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory")

##set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=memory")
##set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=memory")


include(CTest)

enable_testing()

# output binaries into bin
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add dirs where other CMakelists are expected to be
add_subdirectory(${PROJECT_SOURCE_DIR}/scripts)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/white_belt)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/red_belt)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/leetcode)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/cookbook)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/c_lectures)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/cpp_lectures)
