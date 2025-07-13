cmake_minimum_required(VERSION 3.30)
project(appliances)

set(CMAKE_CXX_STANDARD 20)

add_executable(appliances main.cpp
        Service.cpp
        Service.h
        Appliance.cpp
        Appliance.h
        Refrigerator.cpp
        Refrigerator.h
        DishWasher.cpp
        DishWasher.h
        Ui.cpp
        Ui.h)
