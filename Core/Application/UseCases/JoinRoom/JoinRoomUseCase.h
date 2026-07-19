#ifndef JOINROOMUSECASE_H
#define JOINROOMUSECASE_H
#include "Domain/Interfaces/Services/IJoinRoomPresenter.h"
#include "Domain/Interfaces/Services/inetworkclient.h"
#include "Domain/Enums/Enums.h"
#include "../../../../Infrastructure/Network/Packet/joinroompacket.h"

class JoinRoomUseCase
{
private:
	IJoinRoomPresenter* presenter_;
	INetworkClient* network_;

public:
	JoinRoomUseCase(IJoinRoomPresenter* pre, INetworkClient* net);
	void execute(std::string ip , std::int64_t port);

};

#endif // !JOINROOMUSECASE_H

