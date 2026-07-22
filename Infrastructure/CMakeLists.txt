add_library(Infrastructure STATIC
    sessioncontext.h sessioncontext.cpp
    Encryption/Argon2ID.h 
    Encryption/Argon2ID.cpp 
    Encryption/src/argon2.c
    Encryption/src/core.c
    Encryption/src/encoding.c
    Encryption/src/ref.c
    Encryption/src/blake2/blake2b.c
    Repository/sqliteuserrepository.h Repository/sqliteuserrepository.cpp
    DataBase/databasemanager.h DataBase/databasemanager.cpp
    Network/Server/qtcpnetworkserver.h Network/Server/qtcpnetworkserver.cpp
    Network/Client/qtcpnetworkclient.h Network/Client/qtcpnetworkclient.cpp
    Network/Packet/packet.h Network/Packet/packet.cpp
    Session/clientsession.h Session/clientsession.cpp
    Session/sessionmanager.h Session/sessionmanager.cpp
    Network/Packet/authenticatepacket.h Network/Packet/authenticatepacket.cpp
    Network/Packet/createroompacket.h Network/Packet/createroompacket.cpp
    Network/Packet/joinroompacket.h Network/Packet/joinroompacket.cpp
    Network/Packet/readyplayerpacket.h Network/Packet/readyplayerpacket.cpp
    Network/Packet/choosecolorpacket.h Network/Packet/choosecolorpacket.cpp
    Network/Packet/makemovepacket.h Network/Packet/makemovepacket.cpp
    Network/Packet/savegamepacket.h Network/Packet/savegamepacket.cpp
    Network/Packet/loadgamepacket.h Network/Packet/loadgamepacket.cpp
    Manager/RoomManager.h Manager/RoomManager.cpp


)

target_link_libraries(Infrastructure
    PUBLIC
        Core
        Qt6::Core
        Qt6::Widgets
        Qt6::Sql
        Qt6::Network
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