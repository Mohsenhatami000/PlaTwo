#pragma once
#include <optional>
#include <cstdint>
#include "Player.h"
#include "Enums/Enums.h"
class Room
{
private:
	std::int64_t roomID_;
	Player host_;
	std::optional<Player> guest_;
	bool hostConnect_;
	GameType gameType_ ;
	RoomStatus status_;
	ConnectionState hostConnection_;
	std::optional<ConnectionState> guestConnection_;

public:
	Room(std::int64_t id ,const Player& host , GameType type);
	bool join(const Player& player);
	void leave(const std::int64_t id);
	bool isFull() const;
	bool canStart() const;
	void start();
	void close();
	std::int64_t rID() const noexcept;
	const Player& host() const noexcept;
	const std::optional<Player>& guest() const noexcept;
	GameType game() const noexcept;
	RoomStatus status() const noexcept;
	void disconnect(std::int64_t playerId);
	void reconnect(std::int64_t playerId);
	bool isHostConnected() const noexcept;
	bool isGuestConnected() const noexcept;

};