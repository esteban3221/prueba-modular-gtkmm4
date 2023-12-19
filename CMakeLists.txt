cmake_minimum_required(VERSION 3.15)

project(Plantilla CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-4.0)
find_package(SQLite3 REQUIRED)
find_library(SQLITE3_LIBRARY sqlite3 REQUIRED)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(Plantilla 
    src/ventana_main.cpp
    src/subventana1.cpp
    src/subventana2.cpp
    src/ventana_main.cpp
    src/main.cpp
)

target_link_libraries(Plantilla ${GTKMM_LIBRARIES} SQLite::SQLite3)
target_include_directories(Plantilla PRIVATE ${GTKMM_INCLUDE_DIRS})
