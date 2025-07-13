cmake_minimum_required(VERSION 3.30)
project(hospital)

set(CMAKE_CXX_STANDARD 20)

add_executable(hospital main.cpp
        Controller.cpp
        Controller.h
        Ui.cpp
        Ui.h
        Surgery.cpp
        Surgery.h
        NeonatalUnit.cpp
        NeonatalUnit.h
        HospitalDepartment.cpp
        HospitalDepartment.h)
