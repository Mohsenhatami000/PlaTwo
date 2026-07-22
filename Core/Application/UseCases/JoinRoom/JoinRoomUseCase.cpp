#include "JoinRoomUseCase.h"
#include "../../../../Infrastructure/Network/Packet/joinroompacket.h"



JoinRoomUseCase::JoinRoomUseCase(IJoinRoomPresenter* pre, INetworkClient* net, ISessionContext* session) :presenter_(pre),
                  network_(net),session_(session) {

}

void JoinRoomUseCase::execute(std::string ip , std::int64_t port, std::int64_t roomID){
    network_->Connect(ip, port);
    std::optional<AuthenticatedUser> user = session_->currentUser();

    AuthenticatePacket authPacket(user.value().id(), user.value().name().nameValue(), user.value().username().userNameValue());
    network_->send(authPacket);

    JoinRoomPacket packet(ip, port, roomID);
    network_->send(packet);
}