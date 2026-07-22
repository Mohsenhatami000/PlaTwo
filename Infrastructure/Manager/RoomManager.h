#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H
#include <unordered_map>
#include <string>
#include "Domain/Entities/Room.h"
#include "Domain/Interfaces/Repositories/IRoomRepository.h"
class RoomManager : public IRoomRepository
{
private:
	std::unordered_map<std::int64_t,Room> rooms_;

public:
	RoomManager() = default;
	void save(const Room& room) override;
	void update(const Room& room) override;
	void remove(std::int64_t id) override;
	std::optional<Room> findByID(std::int64_t id) const override;
	void createRoom(std::int64_t player, std::int64_t id,int w , int h , int time ,GameType type);
	void joinRoom(std::int64_t player ,std::string ip , std::int64_t port , std::int64_t id);

};
#endif // !ROOMMANAGER_H
