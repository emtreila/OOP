cmake_minimum_required(VERSION 3.28)
project(buildings)

set(CMAKE_CXX_STANDARD 20)

add_executable(buildings main.cpp
        Block.cpp
        Block.h
        House.cpp
        House.h
        Building.cpp
        Building.h
        Controller.cpp
        Controller.h
        Ui.cpp
        Ui.h
        Tests.cpp
        Tests.h)
