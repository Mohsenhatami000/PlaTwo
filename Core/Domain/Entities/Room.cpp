#include "Room.h"
#include "Domain/Exceptions/Exceptions.h"
Room::Room(std::int64_t player,std::int64_t id, int width, int height, int timeLimit, GameType type) :roomID_(id), width_(width),height_(height),
  timeLimit_(timeLimit), gameType_(type),host_(player){
	
}

bool Room::join(Player player) {
	guest_.emplace(player);
	return true;
}
/**
void Room::leave(const std::int64_t id) {
	if (id == host_.pID()) {
		close();
		return;
	}
	if (guest_.has_value() && id == guest_->pID()) {
		guest_.reset();
		guestConnection_.reset();
		status_ = RoomStatus::Waiting;
		return;
	}
	throw Exceptions(DomainError::RoomPlayerNotFound);
}
bool Room::isFull() const {
	return hostConnection_ == ConnectionState::Connected ? guest_.has_value() : true;
}
bool Room::canStart() const {
	if (!guest_.has_value()) {
		return false;
	}
	if (hostConnection_ == ConnectionState::Disconnected) {
		return false;
	}
	if (*guestConnection_ == ConnectionState::Disconnected) {
		return false;
	}
	return host_.pIsReady() && guest_->pIsReady();
}
void Room::start() {
	if (!canStart()) {
		throw Exceptions(DomainError::RoomCanNotStart);
	}
	status_ = RoomStatus::Playing;
}
void Room::close() {
	guest_.reset();
	guestConnection_.reset();
	status_ = RoomStatus::Closed;
}**/
std::int64_t Room::rID() const noexcept {
	return roomID_;
}
const Player Room::host() const noexcept {
	return host_;
}
GameType Room::game() const noexcept {
	return gameType_;
}
/**
RoomStatus Room::status() const noexcept {
	return status_;
}
void Room::disconnect(std::int64_t id) {
	if (id == host_.pID()){
		if (hostConnection_ == ConnectionState::Disconnected) {
			throw Exceptions(DomainError::PlayerAlreadyDisconnected);
		}
		hostConnection_ = ConnectionState::Disconnected;
		return;
	}
	if (guest_.has_value() && guest_->pID() == id){
		if (*guestConnection_ == ConnectionState::Disconnected) {
			throw Exceptions(DomainError::PlayerAlreadyDisconnected);
		}
		*guestConnection_ = ConnectionState::Disconnected;
		return;
	}
	throw Exceptions(DomainError::PlayerNotFound);
}
void Room::reconnect(std::int64_t id) {
	if (id == host_.pID()){
		if (hostConnection_ == ConnectionState::Connected) {
			throw Exceptions(DomainError::PlayerAlreadyConnected);
		}
		hostConnection_ = ConnectionState::Connected;
		return;
	}
	if (guest_.has_value() && guest_->pID() == id){
		if (*guestConnection_ == ConnectionState::Connected) {
			throw Exceptions(DomainError::PlayerAlreadyConnected);
		}
		*guestConnection_ = ConnectionState::Connected;
		return;
	}
	throw Exceptions(DomainError::PlayerNotFound);
}
bool Room::isHostConnected() const noexcept {
	return hostConnection_ == ConnectionState::Connected;
}
bool Room::isGuestConnected() const noexcept {
	return guestConnection_.has_value() && *guestConnection_ == ConnectionState::Connected;
}
**/
const std::optional<Player> Room::guest() const noexcept {
	return guest_;
}
