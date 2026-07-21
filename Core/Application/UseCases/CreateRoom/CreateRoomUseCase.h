#ifndef CREATEROOMUSECASE_H
#define CREATEROOMUSECASE_H
#include "Domain/Interfaces/Services/ICreateRoomPresenter.h"
#include "Domain/Interfaces/Services/inetworkclient.h"
#include "Domain/Interfaces/Services/isessioncontext.h"


class CreateRoomUseCase
{
private:

	ICreateRoomPresenter* presenter_;
	INetworkClient* network_;
    ISessionContext* session_;

public:
    CreateRoomUseCase(ICreateRoomPresenter* presenter,INetworkClient *network, ISessionContext *session);
    void execute(int width, int height, int timeLimit);

};

#endif // !CREATEROOMUSECASE_H

