#pragma once
#include <cstdint>
class Player
{
private:
	std::int64_t p_ID_; //equal with u_ID_
	int p_score_;
	bool p_isReady_;
	
public:
	Player() = default;
	Player(std::int64_t id);
	const std::int64_t pID() const noexcept;
	int pScore() const noexcept;
	bool pIsReady() const noexcept;
	void ready();
	void unready();
	void addScore(int);
	void decreaseScore(int);
	void resetScore();
	bool operator==(const Player&) const;

};