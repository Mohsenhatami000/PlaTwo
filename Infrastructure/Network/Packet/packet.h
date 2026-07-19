#ifndef PACKET_H
#define PACKET_H

#include <QDataStream>

enum class Type{
    Authenticate,
    CreateRoom,
    JoinRoom,
    ReadyPlayer,
    LeaveRoom, // roomID in ClientSession
    StartGame,
    CancelRoom,
    ChooseColor,
    MakeMove, // later implemenation
    Ressign,
    StartNewMatch,
    SaveGame, // later implementation
    LoadGame // later implementation
};

class Packet
{
    Type type_;

public:

    Packet(Type type);
    virtual ~Packet() = default;

    virtual Type type() const;
    virtual void serialize(QDataStream &out) const = 0;
    virtual void deserialize(QDataStream &in) = 0;

};

#endif // PACKET_H
