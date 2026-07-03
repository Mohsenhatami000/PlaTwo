#pragma once
#include <optional>
#include <chrono>
#include "Player.h"
#include "Domain/Enums/Enums.h"
class Match
{
private:
	std::int64_t matchID_;// equal with roomID_
	Player host_;
	Player guest_;
	GameType gameType_;
	MatchStatus status_;
	std::chrono::system_clock::time_point startTime_;
	std::optional<std::chrono::system_clock::time_point> endTime_;
	
public:
	Match(std::int64_t id, const Player& host, const Player& guest, GameType type);
	std::int64_t mID() const noexcept;
	const Player& host() const noexcept;
	const Player& guest() const noexcept;
	GameType game() const noexcept;
	MatchStatus status() const noexcept;
	void start();
	void end();
	bool isEnded() const;
	const std::chrono::system_clock::time_point& startTime() const noexcept;
	const std::optional<std::chrono::system_clock::time_point>& endTime() const noexcept;

};