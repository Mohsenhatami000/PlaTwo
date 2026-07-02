#pragma once
#include <string>
#include <chrono>
#include "Enums/Enums.h"
class History
{
private:
	std::int64_t historyID_; // equal with roomID_
	std::int64_t hostID_;
	std::int64_t guestID_;
	MatchResult result_;
	GameType gameType_;
	std::chrono::system_clock::time_point startTime_;
	std::chrono::system_clock::time_point endTime_;

public:
	History::History(std::int64_t id, std::int64_t hostid, std::int64_t guestid, GameType type,
		MatchResult res ,std::chrono::system_clock::time_point start, std::chrono::system_clock::time_point end);
	std::int64_t hID() const noexcept;
	std::int64_t hostID() const noexcept;
	std::int64_t guestID() const noexcept;
	GameType game() const noexcept;
	MatchResult result() const noexcept;
	const std::chrono::system_clock::time_point& startTime() const noexcept;
	const std::chrono::system_clock::time_point& endTime() const noexcept;
	std::chrono::seconds duration() const;
};