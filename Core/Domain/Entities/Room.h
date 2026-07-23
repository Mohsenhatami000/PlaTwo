#pragma once
#include <optional>
#include <string>
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
	int width_;
	int height_;
	int timeLimit_;
	std::string hostColor_;
    std::string guestColor_;


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
	void setColor(std::int64_t player , std::string color);



};