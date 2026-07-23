#include "WaitingRoomUseCase.h"
#include "../../../../Infrastructure/Network/Packet/choosecolorpacket.h"
#include "../../../../Infrastructure/Network/Packet/authenticatepacket.h"

WaitingRoomUseCase::WaitingRoomUseCase(IWaitingRoomPresenter* pre,INetworkClient *net, ISessionContext* ses) :presenter_(pre),
                  network_(net), session_(ses) {

}
void WaitingRoomUseCase::execute(std::string color) {
	std::optional<AuthenticatedUser> user = session_->currentUser();
	ChooseColorPacket choosecolorpacket(color,user.value().id());
	network_->send(choosecolorpacket);
}