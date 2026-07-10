add_library(Infrastructure STATIC
    sessioncontext.h sessioncontext.cpp
    Encryption/Argon2ID.h 
    Encryption/Argon2ID.cpp 
    Encryption/src/argon2.c
    Encryption/src/core.c
    Encryption/src/encoding.c
    Encryption/src/ref.c
    Encryption/src/blake2/blake2b.c
)

target_link_libraries(Infrastructure
    PUBLIC
        Core
    PRIVATE
        bcrypt
)

target_include_directories(Infrastructure
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Encryption/include
        ${CMAKE_CURRENT_SOURCE_DIR}/Encryption/src
)

target_compile_definitions(Infrastructure PRIVATE
    ARGON2_NO_THREADS
)