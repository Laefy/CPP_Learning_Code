cmake_minimum_required(VERSION 3.16)

project(Cours-CPP)

if(MSVC)
    add_compile_options(/std:c++17 /W4 /WX)
else()
    add_compile_options(-std=c++17 -Wall -W -Werror)
endif()

# Chapters

file(GLOB chapter_folders chap-*)

foreach(chapter ${chapter_folders})
    add_subdirectory(${chapter})
endforeach()

# TPs

file(GLOB tp_folders tp-*)

foreach(tp ${tp_folders})
    add_subdirectory(${tp})
endforeach()
