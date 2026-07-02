#include "Match.h"
#include "Exceptions/Exceptions.h"
Match::Match(std::int64_t id, const Player& host, const Player& guest, GameType type,Turn turn):matchID_(id),host_(host)
            ,guest_(guest),gameType_(type),status_(MatchStatus::NotStarted),turn_(turn){

}
std::int64_t Match::mID() const noexcept {
    return matchID_;
}
const Player& Match::host() const noexcept {
    return host_;
}
GameType Match::game() const noexcept {
    return gameType_;
}
MatchStatus Match::status() const noexcept {
    return status_;
}
Turn Match::turn() const noexcept {
    return turn_;
}
void Match::start() {
    if (status_ != MatchStatus::NotStarted) {
        throw Exceptions(DomainError::MatchAlreadyStarted);
    }
    startTime_ = std::chrono::system_clock::now();
    status_ = MatchStatus::Playing;
}
void Match::end() {
    if (status_ != MatchStatus::Playing) {
        throw Exceptions(DomainError::MatchIsNotPlaying);
    }
    endTime_ = std::chrono::system_clock::now();
    status_ = MatchStatus::Ended;
}
void Match::switchTurn() {
    if (status_ != MatchStatus::Playing) {
        throw Exceptions(DomainError::MatchIsNotPlaying);
    }
    turn_ = turn_ == Turn::Host ? Turn::Guest : Turn::Host;
}
bool Match::isEnded() const {
    return status_ == MatchStatus::Ended;
}
const Player& Match::guest() const noexcept {
    return guest_;
}
const std::chrono::system_clock::time_point& Match::startTime() const noexcept {
    return startTime_;
}
const std::optional<std::chrono::system_clock::time_point>& Match::endTime() const noexcept {
    return endTime_;
}