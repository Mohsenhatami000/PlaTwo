#include "CreateRoomUseCase.h"
#include "../../../../Infrastructure/Network/Packet/createroompacket.h"
#include "../../../../Infrastructure/Network/Packet/authenticatepacket.h"



CreateRoomUseCase::CreateRoomUseCase(ICreateRoomPresenter* presenter,INetworkClient *network, ISessionContext *session){
    presenter_ = presenter;
    network_ = network;
    session_ = session;
}

void CreateRoomUseCase::execute(int width, int height, int timeLimit) {

    network_->Connect("127.0.0.1", 5000);
    std::optional<AuthenticatedUser> user = session_->currentUser();

    AuthenticatePacket authPacket(user.value().id(), user.value().name().nameValue(), user.value().username().userNameValue());
    network_->send(authPacket);

    GameType gameType = session_->gameType();
    CreateRoomPacket createRoomPacket(width, height, timeLimit, gameType);
    network_->send(createRoomPacket);

}