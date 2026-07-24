#include "dotsmove.h"

DotsMove::DotsMove(int row, int column, Direction moveDirection){
    row_ = row;
    column_ = column;
    moveDirection_ = moveDirection;
}


int DotsMove::row() const{
    return row_;
}

int DotsMove::column() const{
    return column_;
}

const Direction DotsMove::moveDirection() const{
    return moveDirection_;
}