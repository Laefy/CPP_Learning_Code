add_executable(tp3-pokemons
    Pokemons/Main.cpp
    Pokemons/PC.h
    Pokemons/PC.cpp
    Pokemons/Pokeball.h
    Pokemons/Pokemon.h
    Pokemons/Stdafx.h
    Pokemons/Tests.cpp
    Pokemons/Trainer.h
)

target_include_directories(tp3-pokemons PRIVATE Pokemons/external)
target_precompile_headers(tp3-pokemons PRIVATE Pokemons/Stdafx.h)
set_source_files_properties(Pokemons/Main.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

