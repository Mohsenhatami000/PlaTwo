add_library(Core STATIC)

target_sources(Core PRIVATE
    Domain/Entities/User.cpp
    Domain/Entities/Player.cpp
    Domain/Entities/Room.cpp
    Domain/Entities/Match.cpp
    Domain/Entities/History.cpp
    Domain/Entities/GameSession.cpp

    Domain/ValueObjects/Coordinate.cpp
    Domain/ValueObjects/Email.cpp
    Domain/ValueObjects/Name.cpp
    Domain/ValueObjects/PasswordHash.cpp
    Domain/ValueObjects/PhoneNumber.cpp
    Domain/ValueObjects/UserName.cpp

    Domain/Exceptions/Exceptions.cpp
)

target_include_directories(Core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
