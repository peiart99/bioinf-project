cmake_minimum_required(VERSION 3.26)
project(bioinf_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(bioinf_project main.cpp
        include/Generator.h
        src/Generator.cpp
        include/Spectrum.h
        src/Spectrum.cpp
        include/Oligonucleotide.h
        src/Oligonucleotide.cpp
        include/Greedy.h
        src/Greedy.cpp
)
