#pragma once
#include <optional>
#include <chrono>
#include "Player.h"
#include "Domain/Enums/Enums.h"
#include "Domain/Games/igame.h"
#include "Domain/Games/gamesetting.h"

class Match
{
private:
	std::int64_t matchID_;// equal with roomID_
	Player host_;
	Player guest_;
	GameType gameType_;
    IGame *game_;
    GameSetting setting_;
	MatchStatus status_;
	std::chrono::system_clock::time_point startTime_;
	std::optional<std::chrono::system_clock::time_point> endTime_;
	
public:
    Match(std::int64_t id, const Player& host, const Player& guest, GameSetting setting);
	std::int64_t mID() const noexcept;
	const Player& host() const noexcept;
	const Player& guest() const noexcept;
    IGame* game() noexcept;
	MatchStatus status() const noexcept;
	void start();
	void end();
	bool isEnded() const;
	const std::chrono::system_clock::time_point& startTime() const noexcept;
	const std::optional<std::chrono::system_clock::time_point>& endTime() const noexcept;

};