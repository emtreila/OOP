cmake_minimum_required(VERSION 3.30)
project(equation)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_PATH "C:/Qt/6.9.0/mingw_64")
set(QT_DLL_PATH "${QT_PATH}/bin")
set(WINDEPLOYQT "${QT_PATH}/bin/windeployqt.exe")

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

set(SOURCES
        main.cpp
        Equation.cpp
        Repo.cpp
        Service.cpp
        gui.cpp
        gui.ui
)

set(HEADERS
        Equation.h
        Repo.h
        Service.h
        gui.h
)

add_executable(equation ${SOURCES} ${HEADERS})

target_link_libraries(equation Qt::Core Qt::Gui Qt::Widgets)

foreach(QT_LIB Core Gui Widgets)
    add_custom_command(TARGET equation POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${QT_DLL_PATH}/Qt6${QT_LIB}.dll"
            "$<TARGET_FILE_DIR:equation>/Qt6${QT_LIB}.dll"
    )
endforeach()


set(QPLATFORM_DLL "${QT_PATH}/plugins/platforms/qwindows.dll")
add_custom_command(TARGET equation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        "$<TARGET_FILE_DIR:equation>/plugins/platforms/"
)
add_custom_command(TARGET equation POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${QPLATFORM_DLL}"
        "$<TARGET_FILE_DIR:equation>/plugins/platforms/qwindows.dll"
)
