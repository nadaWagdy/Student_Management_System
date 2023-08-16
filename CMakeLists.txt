cmake_minimum_required(VERSION 3.5)

project(Student_Management_System LANGUAGES C)

add_executable(Student_Management_System main.c Student.c Student.h Validation.h Validation.c)

install(TARGETS Student_Management_System
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
