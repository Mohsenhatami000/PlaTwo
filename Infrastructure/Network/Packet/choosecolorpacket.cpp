#include "choosecolorpacket.h"
#include <QString>
ChooseColorPacket::ChooseColorPacket(): Packet(Type::ChooseColor){};

ChooseColorPacket::ChooseColorPacket(Type type, std::string color): Packet(type){
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
