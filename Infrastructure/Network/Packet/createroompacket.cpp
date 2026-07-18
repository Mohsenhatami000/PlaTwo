#include "createroompacket.h"

CreateRoomPacket::CreateRoomPacket(Type type, int width, int height, int timeLimit, GameType gameType): Packet(type){
    width_ = width;
    height_ = height;
    timeLimit_ = timeLimit;
    gameType_ = gameType;
};

CreateRoomPacket::CreateRoomPacket(): Packet(Type::CreateRoom){};


void CreateRoomPacket::serialize(QDataStream &out) const{

    out << width_;
    out << height_;
    out << timeLimit_;
    out << gameType_;
}

void CreateRoomPacket::deserialize(QDataStream &in){
    in >> width_;
    in >> height_;
    in >> timeLimit_;
    in >> gameType_;
}

int CreateRoomPacket::width() const{
    return width_;
}

int CreateRoomPacket::height() const{
    return height_;
}

int CreateRoomPacket::timeLimit() const{
    return timeLimit_;
}

GameType CreateRoomPacket::gameType() const{
    return gameType_;
}