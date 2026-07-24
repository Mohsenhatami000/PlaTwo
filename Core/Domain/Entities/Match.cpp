#include "Match.h"
#include "Domain/Exceptions/Exceptions.h"
#include "Domain/Games/Dots & Boxes/dotsgame.h"

Match::Match(std::int64_t id, const Player& host, const Player& guest, GameSetting setting)
    :matchID_(id)
    , host_(host)
    , guest_(guest)
    , status_(MatchStatus::NotStarted)
    , setting_(setting)
    , game_(nullptr){
    if(setting_.gameType() == GameType::DotsAndBoxes){
        game_ = new DotsGame(DotsBoard(setting_.height(), setting_.width()), Turn::Host);
    }
}


std::int64_t Match::mID() const noexcept {
    return matchID_;
}
const Player& Match::host() const noexcept {
    return host_;
}
IGame* Match::game() noexcept {
    return game_;
}
MatchStatus Match::status() const noexcept {
    return status_;
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