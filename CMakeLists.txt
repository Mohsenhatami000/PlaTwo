cmake_minimum_required(VERSION 3.21)

project(PlaTwo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt
find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

qt_standard_project_setup()

# Subprojects
add_subdirectory(Core)
add_subdirectory(Client)
add_subdirectory(Server)
add_subdirectory(Tests)
add_subdirectory(Infrastructure)