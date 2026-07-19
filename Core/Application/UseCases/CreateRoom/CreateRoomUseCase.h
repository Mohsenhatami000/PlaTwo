#ifndef CREATEROOMUSECASE_H
#define CREATEROOMUSECASE_H
#include "Domain/Interfaces/Services/ICreateRoomPresenter.h"
#include "Domain/Interfaces/Services/inetworkclient.h"
#include "Domain/Enums/Enums.h"
#include "../../../../Infrastructure/Network/Packet/createroompacket.h"

class CreateRoomUseCase
{
private:
	ICreateRoomPresenter* presenter_;
	INetworkClient* network_;

public:
	CreateRoomUseCase(ICreateRoomPresenter* pre,INetworkClient *net);
	void execute(int width, int height, int timeLimit, GameType gameType);

};

#endif // !CREATEROOMUSECASE_H

