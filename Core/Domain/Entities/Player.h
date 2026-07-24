#pragma once
#include <cstdint>
#include "Domain/ValueObjects/UserName.h"

class Player
{
private:
	std::int64_t p_ID_; //equal with u_ID_
    UserName p_username_;
	int p_score_;
	bool p_isReady_;
	
public:
	Player(std::int64_t id);
	const std::int64_t pID() const noexcept;
	int pScore() const noexcept;
	bool pIsReady() const noexcept;
    const UserName& pUserName() const noexcept;
	void ready();
	void unready();
	void addScore(int);
	void decreaseScore(int);
	void resetScore();
	bool operator==(const Player&) const;

};