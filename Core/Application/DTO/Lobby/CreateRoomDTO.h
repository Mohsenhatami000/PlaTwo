#ifndef CREATEROOMDTO_H
#define CREATEROOMDTO_H
#include <string>
#include "Domain\Enums\Enums.h"
#include "Domain\Entities\Player.h"

struct CreateRoomRequest
{
	Player host_;
	std::optional<Player> guest_;
	GameType gameType_;
	RoomStatus status_;
	ConnectionState hostConnection_;
	std::optional<ConnectionState> guestConnection_;
};
#endif // !CREATEROOMDTO-H

