cmake_minimum_required(VERSION 3.16)

project(ble_and_net_for_esp32_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Bluetooth Network)

qt_standard_project_setup()

qt_add_executable(ble_and_net_for_esp32_app
    main.cpp
    widget.cpp
    widget.h
    widget.ui
)

target_link_libraries(ble_and_net_for_esp32_app PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Bluetooth Qt6::Network)

set_target_properties(ble_and_net_for_esp32_app PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ble_and_net_for_esp32_app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
