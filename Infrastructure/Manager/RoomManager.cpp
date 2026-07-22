#include "RoomManager.h"
void RoomManager::save(const Room& room){
	rooms_.insert({ room.rID(), room });
}

void RoomManager::update(const Room& room){

}

void RoomManager::remove(std::int64_t id) {
	rooms_.erase(id);
}

std::optional<Room> RoomManager::findByID(std::int64_t id) const{
	auto it = rooms_.find(id);
	if (it != rooms_.end()) {
		return it->second;
	}
	return std::nullopt;
}

void RoomManager::createRoom(std::int64_t player ,std::int64_t id, int w, int h, int time, GameType type) {
	Room newRoom(player,id, w, h, time, type);
	save(newRoom);
	return;
}

void RoomManager::joinRoom(std::int64_t player ,std::string ip, std::int64_t port, std::int64_t id){
	auto it = rooms_.find(id);
	if (it == rooms_.end()) {
		return;
	}
	auto& room = it->second;
	room.join(Player(player));
}