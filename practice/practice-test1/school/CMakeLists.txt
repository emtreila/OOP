cmake_minimum_required(VERSION 3.28)
project(school)

set(CMAKE_CXX_STANDARD 20)

add_executable(school main.cpp
        domain/School.cpp
        domain/School.h
        repository/Repo.cpp
        repository/Repo.h
        DynamicVector.h
        service/Service.cpp
        service/Service.h
        ui/Ui.cpp
        ui/Ui.h
        tests/Tests.cpp
        tests/Tests.h)
