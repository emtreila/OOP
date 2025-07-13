cmake_minimum_required(VERSION 3.28)
project(medical)

set(CMAKE_CXX_STANDARD 20)

add_executable(medical main.cpp
        Person.cpp
        Person.h
        MedicalAnalysis.cpp
        MedicalAnalysis.h
        BMI.cpp
        BMI.h
        BP.cpp
        BP.h
        Service.cpp
        Service.h
        Ui.cpp
        Ui.h)
