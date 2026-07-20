#include "CreateRoomUseCase.h"
CreateRoomUseCase::CreateRoomUseCase(ICreateRoomPresenter* pre,INetworkClient *net) :presenter_(pre),network_(net) {

}
void CreateRoomUseCase::execute(int width, int height, int timeLimit, GameType gameType) {
	CreateRoomPacket packet( width, height, timeLimit, gameType);
	if (network_) {
		network_->send(packet);
	}
}