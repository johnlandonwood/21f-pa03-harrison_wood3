cmake_minimum_required(VERSION 3.20)
project (community_detection)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/Program Files/Boost/boost_1_77_0")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/Program Files/Boost/boost_1_77_0/libs")

SET(BOOST_ROOT "C:/Program Files/Boost/boost_1_77_0")
SET(BOOST_INCLUDEDIR "C:/Program Files/Boost/boost_1_77_0")
SET(BOOST_LIBRARYDIR "C:/Program Files/Boost/boost_1_77_0/libs")

# set(Boost_DEBUG 1)
find_package(Boost 1.77.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost version: ${Boost_VERSION}")

add_executable(community_detection src/main.cpp src/community_detector.cpp src/community_detector.h """C:/Program Files/Boost/boost_1_77_0/libs/graph/src/graphml.cpp""" )

target_link_libraries(community_detection Boost::boost)