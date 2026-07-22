#ifndef JOINROOMUSECASE_H
#define JOINROOMUSECASE_H
#include "Domain/Interfaces/Services/IJoinRoomPresenter.h"
#include "Domain/Interfaces/Services/inetworkclient.h"
#include "../../../../Infrastructure/Network/Packet/authenticatepacket.h"
#include <Domain/Entities/authenticateduser.h>
#include "Domain/Interfaces/Services/isessioncontext.h"

class JoinRoomUseCase
{
private:
	IJoinRoomPresenter* presenter_;
	INetworkClient* network_;
	ISessionContext* session_;

public:
	JoinRoomUseCase(IJoinRoomPresenter* pre, INetworkClient* net, ISessionContext* session);
    void execute(std::string ip , std::int64_t port, std::int64_t roomID);

};

#endif // !JOINROOMUSECASE_H

