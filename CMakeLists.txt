cmake_minimum_required(VERSION 3.29)
project(OOP345Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(MS1/MS1)
include_directories(MS2/MS2)
include_directories(MS3/MS3)

add_executable(OOP345Project
    MS1/MS1/ms1.cpp
    MS1/MS1/Station.cpp
    MS1/MS1/Station.h
    MS1/MS1/Utilities.cpp
    MS1/MS1/Utilities.h
    MS2/MS2/CustomerOrder.cpp
    MS2/MS2/CustomerOrder.h
    MS2/MS2/ms2.cpp
    MS2/MS2/Station.cpp
    MS2/MS2/Station.h
    MS2/MS2/Utilities.cpp
    MS2/MS2/Utilities.h
    MS3/MS3/CustomerOrder.cpp
    MS3/MS3/CustomerOrder.h
    MS3/MS3/LineManager.cpp
    MS3/MS3/LineManager.h
    MS3/MS3/ms3.cpp
    MS3/MS3/Station.cpp
    MS3/MS3/Station.h
    MS3/MS3/Utilities.cpp
    MS3/MS3/Utilities.h
    MS3/MS3/Workstation.cpp
    MS3/MS3/Workstation.h)
