#include "JoinRoomUseCase.h"
JoinRoomUseCase::JoinRoomUseCase(IJoinRoomPresenter* pre, INetworkClient* net) :presenter_(pre), network_(net) {

}
void JoinRoomUseCase::execute(std::string ip , std::int64_t port) {
	JoinRoomPacket packet(ip, port, port); //edits later
	if (network_) {
		network_->send(packet);
	}
}