cmake_minimum_required(VERSION 3.30)
project(shoppingList)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
  Core
  Gui
  Widgets
  REQUIRED)

add_executable(shoppingList main.cpp
        Item.cpp
        Item.h
        Repo.cpp
        Repo.h
        Service.cpp
        Service.h
        gui.cpp
        gui.h
        gui.ui)
target_link_libraries(shoppingList
  Qt::Core
  Qt::Gui
  Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif()

    set(QT_INSTALL_PATH "C:/Qt/6.9.0/mingw_64")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        message(FATAL_ERROR "Invalid QT_INSTALL_PATH: ${QT_INSTALL_PATH}")
    endif()

    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET shoppingList POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:shoppingList>/plugins/platforms/"
        )
        add_custom_command(TARGET shoppingList POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:shoppingList>/plugins/platforms/"
        )
    endif()

    foreach(QT_LIB Core Gui Widgets)
        add_custom_command(TARGET shoppingList POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:shoppingList>"
        )
    endforeach()
endif()