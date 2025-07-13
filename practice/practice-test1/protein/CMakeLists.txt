cmake_minimum_required(VERSION 3.28)
project(protein)

set(CMAKE_CXX_STANDARD 20)

add_executable(protein main.cpp
        DynamicVector.h
        domain/Protein.cpp
        domain/Protein.h
        repository/Repo.cpp
        repository/Repo.h
        service/Service.cpp
        service/Service.h
        ui/Ui.cpp
        ui/Ui.h
        tests/Tests.cpp
        tests/Tests.h)
