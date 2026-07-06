add_library(Infrastructure STATIC
    sessioncontext.h sessioncontext.cpp)

target_link_libraries(Infrastructure
    PUBLIC
        Core
)

target_include_directories(Infrastructure
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)