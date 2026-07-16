#include "packet.h"

Packet::Packet(Type type){
    type_ = type;
}

Type Packet::type() const{
    return type_;
}