#pragma once

class INetworkServer{


public:

    virtual ~INetworkServer() = default;
    virtual bool start() = 0;
    virtual void stop() noexcept = 0;
    virtual void send() noexcept = 0;
    virtual void broadcast() noexcept = 0;
    virtual void disconnect() noexcept = 0;

};