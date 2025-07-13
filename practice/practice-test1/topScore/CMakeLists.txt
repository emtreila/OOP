cmake_minimum_required(VERSION 3.28)
project(topScore)

set(CMAKE_CXX_STANDARD 20)

add_executable(topScore main.cpp
        domain/Scorer.cpp
        domain/Scorer.h
        repository/Repo.cpp
        repository/Repo.h
        service/Service.cpp
        service/Service.h
        tests/Tests.cpp
        tests/Tests.h
        ui/Ui.cpp
        ui/Ui.h
        DynamicVector.h)
