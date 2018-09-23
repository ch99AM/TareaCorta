cmake_minimum_required(VERSION 3.12)
project(TareaCorta_)

set(CMAKE_CXX_STANDARD 14)

include_directories("Hearder File")

add_executable(TareaCorta_
    cmake-build-debug/12kB.txt
    cmake-build-debug/1kB.txt
    cmake-build-debug/24kB.txt
    cmake-build-debug/36kB.txt
    cmake-build-debug/4kB.txt
    cmake-build-debug/8kB.txt
    cmake-build-debug/Doc.bin
        "Hearder File/ManegerFile.h"
    "Hearder File/Ordenamiento.h"
    "Hearder File/PagedArray.h"
        main.cpp)
