#include "GameSession.h"
GameSession::GameSession(std::int64_t id, Turn turn) :sessionID_(id), turn_(turn), lastSave_(std::chrono::system_clock::now()) {

}
std::int64_t GameSession::sessionID() const noexcept{
	return std::int64_t() sessionID_;
}
Turn GameSession::turn() const noexcept{
	return turn_;
}
const std::chrono::system_clock::time_point& GameSession::lastSaveTime() const noexcept{
	return lastSave_;
}
void GameSession::switchTurn() {
	turn_ = (turn_ == Turn::Host) ? Turn::Guest : Turn::Host;
}
void GameSession::update(){
	lastSave_ = std::chrono::system_clock::now();
}