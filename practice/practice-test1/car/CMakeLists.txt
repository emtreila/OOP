cmake_minimum_required(VERSION 3.28)
project(car)

set(CMAKE_CXX_STANDARD 20)

add_executable(car main.cpp
        DynamicVector.h
        domain/Car.cpp
        domain/Car.h
        repository/Repo.cpp
        repository/Repo.h
        service/Service.cpp
        service/Service.h
        ui/Ui.cpp
        ui/Ui.h
        tests/Tests.cpp
        tests/Tests.h)
