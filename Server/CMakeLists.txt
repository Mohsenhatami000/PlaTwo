add_executable(ServerApp
    main.cpp
)

target_link_libraries(ServerApp
    PRIVATE
        Qt6::Network
        Core
        Infrastructure
)
