#ifndef DOTSGAME_H
#define DOTSGAME_H

#include "../igame.h"
#include "dotsboard.h"
#include "dotsruleengine.h"
#include "optional"


class DotsGame : public IGame
{
    DotsBoard board_;
    DotsRuleEngine ruleEngine_;
    int hostScore_;
    int guestScore_;

public:

    DotsGame(DotsBoard board, Turn turn);
    bool makeMove(IMove &move) override;
    void updateScore(int amount);
    bool isFinished() const;
    int hostScore() const;
    int guestScore() const;
    std::optional<Turn> winner() const;
    DotsBoard& board();

};

#endif // DOTSGAME_H
