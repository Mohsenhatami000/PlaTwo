#pragma once
#include <string>
#include <chrono>
#include "Domain/Enums/Enums.h"
class GameSession //Edits for miniGames
{
private:
    std::int64_t sessionID_;//equal with matchID_
    Turn turn_;
    std::chrono::system_clock::time_point lastSave_;

public:
    GameSession(std::int64_t id , Turn turn);
    std::int64_t sessionID() const noexcept;
    Turn turn() const noexcept;
    const std::chrono::system_clock::time_point& lastSaveTime() const noexcept;
    void switchTurn();
    void update();

};