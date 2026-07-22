#pragma once
#include <optional>
#include <cstdint>
#include "Player.h"
#include "Domain/Enums/Enums.h"
class Room
{
private:
	std::int64_t roomID_;
	Player host_;
	std::optional<Player> guest_;
	GameType gameType_ ;
	//RoomStatus status_;
	int width_;
	int height_;
	int timeLimit_;
	//ConnectionState hostConnection_;
	//std::optional<ConnectionState> guestConnection_;
	

public:
	Room(std::int64_t player ,std::int64_t id, int width, int height, int timeLimit, GameType type);
	bool join(Player player);
	/**void leave(const std::int64_t id);
	bool isFull() const;
	bool canStart() const;
	void start();
	void close();
	**/std::int64_t rID() const noexcept;
	const Player host() const noexcept;
	const std::optional<Player> guest() const noexcept;
	GameType game() const noexcept;
	/**RoomStatus status() const noexcept;
	void disconnect(std::int64_t playerId);
	void reconnect(std::int64_t playerId);
	bool isHostConnected() const noexcept;
	bool isGuestConnected() const noexcept;
	**/
};