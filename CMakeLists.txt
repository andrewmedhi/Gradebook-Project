cmake_minimum_required(VERSION 3.24)
project(Gradebook-Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Gradebook-Project main.cpp person.h deliverable.cpp deliverable.h grade.cpp grade.h person.cpp gradebook.cpp gradebook.h)
