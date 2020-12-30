cmake_minimum_required(VERSION 3.1)

project(Cours-CPP)

if(MSVC)
    add_compile_options(/std:c++17 /W4 /WX)
else()
    add_compile_options(-std=c++17 -Wall -W -Werror)
endif()

file(GLOB chapter_folders chap-*)

foreach(chapter ${chapter_folders})
    add_subdirectory(${chapter})
endforeach()
