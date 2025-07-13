cmake_minimum_required(VERSION 3.30)
project(t2_emtreila_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(t2_emtreila_1 main.cpp
        Engine.cpp
        Engine.h
        Car.cpp
        Car.h
        ElectricEngine.cpp
        ElectricEngine.h
        TurboEngine.cpp
        TurboEngine.h
        Service.cpp
        Service.h
        Ui.cpp
        Ui.h)
