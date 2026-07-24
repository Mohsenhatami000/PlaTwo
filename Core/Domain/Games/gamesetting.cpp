#include "gamesetting.h"

GameSetting::GameSetting(int width, int height, int timeLimit, GameType gameType){
    width_ = width;
    height_ = height;
    timeLimit_ = timeLimit;
    gameType_ = gameType;
}


int GameSetting::width() const{
    return width_;
}

int GameSetting::height() const{
    return height_;
}

int GameSetting::timeLimit() const{
    return timeLimit_;
}

GameType GameSetting::gameType() const{
    return gameType_;
}
