#ifndef GAMESETTING_H
#define GAMESETTING_H

#include "Domain/Enums/Enums.h"

class GameSetting
{
    int width_;
    int height_;
    int timeLimit_;
    GameType gameType_;

public:
    GameSetting(int width, int height, int timeLimit, GameType gameType);

    int width() const;
    int height() const;
    int timeLimit() const;
    GameType gameType() const;


};


#endif // GAMESETTING_H
