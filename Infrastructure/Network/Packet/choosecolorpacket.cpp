#include "choosecolorpacket.h"
#include <QString>
ChooseColorPacket::ChooseColorPacket(): Packet(Type::ChooseColor){};

ChooseColorPacket::ChooseColorPacket(std::string color): Packet(Type::ChooseColor){
    color_ = color;
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
