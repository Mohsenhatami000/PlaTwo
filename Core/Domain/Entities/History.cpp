#include "History.h"
History::History(std::int64_t id, std::int64_t hostid, std::int64_t guestid, GameType type,MatchResult res,
	std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end):
    historyID_(id),hostID_(hostid),guestID_(guestid),gameType_(type),result_(res),startTime_(start),endTime_(end){

}
std::int64_t History::hID() const noexcept {
	return historyID_;
}
std::int64_t History::hostID() const noexcept {
	return hostID_;
}
std::int64_t History::guestID() const noexcept {
	return guestID_;
}
GameType History::game() const noexcept {
	return gameType_;
}
MatchResult History::result() const noexcept {
	return result_;
}
const std::chrono::system_clock::time_point& History::startTime() const noexcept {
	return startTime_;
}
const std::chrono::system_clock::time_point& History::endTime() const noexcept {
	return endTime_;
}
std::chrono::seconds History::duration() const noexcept{
	return std::chrono::duration_cast<std::chrono::seconds>(endTime_ - startTime_);
}