#include "Player.h"
Player::Player(std::int64_t id):p_ID_(id),p_score_(0),p_isReady_(false){

}
const std::int64_t Player::pID() const noexcept {
	return p_ID_;
}
int Player::pScore() const noexcept {
	return p_score_;
}
bool Player::pIsReady() const noexcept {
	return p_isReady_;
}
void Player::ready() {
	p_isReady_ = true;
}
void Player::unready() {
	p_isReady_ = false;
}
void Player::addScore(int s) {
	p_score_ += s;
}
void Player::decreaseScore(int s) {
	p_score_ -= s;
}
void Player::resetScore() {
	p_score_ = 0;
}
bool Player::operator==(const Player& player) const {
	return player.pID() == p_ID_;
}

const UserName& Player::pUserName() const noexcept {
    return p_username_;
}