cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(untitled
        src/main.cpp
        src/Person.cpp
        src/Student.cpp
        src/Profesor.cpp
        src/Subject.cpp
        src/Foititologio.cpp
)