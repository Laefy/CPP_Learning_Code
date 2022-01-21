set(executables
    1-vectors
    2-sequentials
    4-strings
    5-tuples
)

foreach(executable ${executables})
    add_executable(c5-${executable} ${executable}.cpp)
endforeach()

add_executable(c5-3-associatives
    3-associatives/main.cpp
    3-associatives/keys.h
)
