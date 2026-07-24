#ifndef IGAME_H
#define IGAME_H

#include "Domain/Enums/Enums.h"
#include "Domain/Games/Imove.h"

class IGame
{
    Turn currentTurn_;

public:
    IGame(Turn currentTurn);
    virtual ~IGame() = default;
    virtual bool makeMove(IMove &move) = 0;
    Turn currentTurn() const;
    void switchTurn();

};

#endif // IGAME_H
