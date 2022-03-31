cmake_minimum_required(VERSION 3.17)
project(1C_task)

OPTION(BUILD_TESTS OFF)
set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

#Add source files
add_executable(1C_task_run main.cpp solution.h)

if(BUILD_TESTS)
    include(ExternalProject)
    set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" ${CMAKE_SOURCE_DIR}/cmake ${PROJECT_SOURCE_DIR})

    set(EXTERNAL_INSTALL_LOCATION ${PROJECT_SOURCE_DIR}/3rdparty)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
    find_package(Threads REQUIRED)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage --coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage --coverage")

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
    if (APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
    endif()
    ExternalProject_Add(
            googletest_repo
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG main
            CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
    )
    include_directories(${EXTERNAL_INSTALL_LOCATION}/include include)
    link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

    add_subdirectory(tests)
endif()