cmake_minimum_required(VERSION 3.28)
project(matrixLibrary C)

set(CMAKE_C_STANDARD 11)

add_executable(matrixLibrary main.c
        Matrix.h
        Matrix/ManageMatrix.c
        Matrix/MatrixOperation.c
        Matrix/MatrixType.c
        Matrix/UtilityMatrix.c)
