cmake_minimum_required(VERSION 3.0.0)

PROJECT(accessHeater)

FIND_PACKAGE(mtca4u-deviceaccess 00.22 REQUIRED)
include_directories(SYSTEM ${mtca4u-deviceaccess_INCLUDE_DIRS})
link_directories(${mtca4u-deviceaccess_LIBRARY_DIRS})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${mtca4u-deviceaccess_CXX_FLAGS}")

ADD_EXECUTABLE(${PROJECT_NAME} accessHeater.cpp )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${mtca4u-deviceaccess_LIBRARIES})
