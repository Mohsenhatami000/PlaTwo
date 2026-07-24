#include "igame.h"

IGame::IGame(Turn currentTurn){
    currentTurn_ = currentTurn;
}

Turn IGame::currentTurn() const{
    return currentTurn_;
}



void IGame::switchTurn(){
    if(currentTurn_ == Turn::Guest){
        currentTurn_ = Turn::Host;
    }
    else{
        currentTurn_ = Turn::Guest;
    }
}