#include "Room.h"
#include "Domain/Exceptions/Exceptions.h"
Room::Room(std::int64_t player,std::int64_t id, int width, int height, int timeLimit, GameType type) :roomID_(id), width_(width),height_(height),
  timeLimit_(timeLimit), gameType_(type),host_(player){
	
}

bool Room::join(Player player) {
	if (!guest_.has_value()) {
		guest_.emplace(player);
	}
	return true;
}
 
std::int64_t Room::rID() const noexcept {
	return roomID_;
}

const Player Room::host() const noexcept {
	return host_;
}

GameType Room::game() const noexcept {
	return gameType_;
}

const std::optional<Player> Room::guest() const noexcept {
	return guest_;
}

void Room::setColor(std::int64_t player, std::string color) {
	if (player == host_.pID()  ) {
		if (color != guestColor_) {
			return;
		}
		hostColor_ = color;
	}
	if (player == guest_.emplace()  ) {
		if (color != hostColor_) {
			return;
		}
		guestColor_ = color;
	}
}
 