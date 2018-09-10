cmake_minimum_required(VERSION 3.12)
project(TareaCorta_)

set(CMAKE_CXX_STANDARD 14)

add_executable(TareaCorta_ main.cpp "Hearder File/PagedArray.h" "Hearder File/ManegerFile.h" MemoryManeger/GestorLRU.h MemoryManeger/GestorMemoria.h MemoryManeger/Nodo.h MemoryManeger/GestorLRU.cpp "Hearder File/QuickSort.h" "Hearder File/quicksort.h" "Hearder File/insertionsort.h" "Hearder File/selectionsort.h")