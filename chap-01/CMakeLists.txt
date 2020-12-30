set(executables
    1-hello_world
    2-parrot
    3-array
    4-calculator
)

foreach(executable ${executables})
    add_executable(c1-${executable} ${executable}.cpp)
endforeach()
