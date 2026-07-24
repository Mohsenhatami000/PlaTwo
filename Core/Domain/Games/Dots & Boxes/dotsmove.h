#ifndef DOTSMOVE_H
#define DOTSMOVE_H

#include "../Imove.h"
#include "Domain/Enums/Enums.h"

class DotsMove : public IMove
{
    int row_;
    int column_;
    Direction moveDirection_;


public:    
    DotsMove(int row, int column, Direction moveDirection);
    int row() const;
    int column() const;
    const Direction moveDirection() const;
};

#endif // DOTSMOVE_H
