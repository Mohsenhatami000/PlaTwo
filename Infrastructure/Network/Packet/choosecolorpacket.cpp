#include "choosecolorpacket.h"
#include <QString>
ChooseColorPacket::ChooseColorPacket(): Packet(Type::ChooseColor){};

ChooseColorPacket::ChooseColorPacket(std::string color,std::int64_t id): Packet(Type::ChooseColor){
    color_ = color;
    roomID_ = id;
}

void ChooseColorPacket::serialize(QDataStream &out) const{
    out << QString::fromStdString(color_);
}

void ChooseColorPacket::deserialize(QDataStream &in){
    QString color;
    in >> color;
    color_ = color.toStdString();
}


std::string ChooseColorPacket::color() const{
    return color_;
}

std::int64_t ChooseColorPacket::roomID() const {
    return roomID_;
}