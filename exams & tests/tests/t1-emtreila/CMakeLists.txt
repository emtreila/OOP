cmake_minimum_required(VERSION 3.28)
project(t1_emtreila)

set(CMAKE_CXX_STANDARD 20)

add_executable(t1_emtreila main.cpp
        DynamicVector.h
        repository/Repo.cpp
        repository/Repo.h
        service/Service.cpp
        service/Service.h
        ui/Ui.cpp
        ui/Ui.h
        domain/School.cpp
        domain/School.h
        tests/Tests.cpp
        tests/Tests.h)
