cmake_minimum_required(VERSION 3.5.0)

PROJECT(accessHeater)

FIND_PACKAGE(ChimeraTK-DeviceAccess 01.00 REQUIRED)
include_directories(SYSTEM ${ChimeraTK-DeviceAccess_INCLUDE_DIRS})
link_directories(${ChimeraTK-DeviceAccess_LIBRARY_DIRS})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ChimeraTK-DeviceAccess_CXX_FLAGS}")

ADD_EXECUTABLE(${PROJECT_NAME} accessHeater.cpp )
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${ChimeraTK-DeviceAccess_LIBRARIES})

file(COPY oven.map devices.dmap DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
