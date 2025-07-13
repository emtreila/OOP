cmake_minimum_required(VERSION 3.28)
project(assignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment main.cpp
        DynamicVector.h
        domain/Assignment.cpp
        domain/Assignment.h
        repository/Repo.cpp
        repository/Repo.h
        service/Service.cpp
        service/Service.h
        tests/Tests.cpp
        tests/Tests.h
        ui/Ui.cpp
        ui/Ui.h)
