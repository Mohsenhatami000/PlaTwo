#ifndef INETWORKCLIENT_H
#define INETWORKCLIENT_H

#include <cstdint>
#include <string>
#include "Network/Packet/packet.h"

class INetworkClient
{
public:
    INetworkClient();
    virtual void Connect(std::string IP,std::int64_t port) = 0;
    virtual void Disconnect() = 0;
    virtual void send(Packet &packet) = 0;
    virtual ~INetworkClient() = default;



};

#endif // INETWORKCLIENT_H
