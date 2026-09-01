cmake_minimum_required(VERSION 3.20)
project(Practica_Estructuras)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Practica_Estructuras
        main.cpp
        DatasetManager.cpp DatasetManager.h
        QuickSort.cpp QuickSort.h
        HeapSort.cpp HeapSort.h
        AVLTree.cpp AVLTree.h
        Metrics.cpp Metrics.h
)
