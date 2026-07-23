#ifndef WAITINGROOMUSECASE_H
#define WAITINGROOMUSECASE_H
#include "Domain/Interfaces/Services/IWaitingRoomPresenter.h"
#include "Domain/Interfaces/Services/inetworkclient.h"
#include "Domain/Interfaces/Services/isessioncontext.h"

class WaitingRoomUseCase
{
private:
	IWaitingRoomPresenter* presenter_;
	INetworkClient* network_;
	ISessionContext* session_ ;


public:
	WaitingRoomUseCase(IWaitingRoomPresenter* pre ,INetworkClient *net,ISessionContext *ses);
	void execute(std::string color);

};
#endif // !WAITINGROOMUSECASE_H

