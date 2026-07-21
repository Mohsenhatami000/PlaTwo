#include "JoinRoomUseCase.h"
#include "../../../../Infrastructure/Network/Packet/joinroompacket.h"


JoinRoomUseCase::JoinRoomUseCase(IJoinRoomPresenter* pre, INetworkClient* net) :presenter_(pre), network_(net) {

}

void JoinRoomUseCase::execute(std::string ip , std::int64_t port, std::int64_t roomID){

    JoinRoomPacket packet(ip, port, roomID);
    network_->send(packet);
}