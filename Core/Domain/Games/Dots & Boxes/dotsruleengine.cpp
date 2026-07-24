#include "dotsruleengine.h"
#include "dotsmove.h"
#include "dotsboard.h"


DotsRuleEngine::DotsRuleEngine() {}

bool DotsRuleEngine::isCompleteEmptyBox(int X, int Y, IBoard &board){
    DotsBoard &dotsBoard = dynamic_cast<DotsBoard&>(board);

    if(dotsBoard.lineX()[X][Y]
        && dotsBoard.lineX()[X+1][Y]
        && dotsBoard.lineY()[X][Y]
        && dotsBoard.lineY()[X][Y+1]
        && (!dotsBoard.boxes()[X][Y])){
        return true;
    }
    else
        return false;
}


bool DotsRuleEngine::validateMove(IMove &move, IBoard &board){

    DotsMove &dotsMove = dynamic_cast<DotsMove&>(move);
    DotsBoard &dotsBoard = dynamic_cast<DotsBoard&>(board);

    if(dotsMove.moveDirection() == Direction::Horizontal){
        if(!(dotsBoard.lineX()[dotsMove.row()][dotsMove.column()]))
            return true;
        else
            return false;
    }
    else if(dotsMove.moveDirection() == Direction::Vertical){
        if(!(dotsBoard.lineY()[dotsMove.row()][dotsMove.column()]))
            return true;
        else
            return false;
    }
    else
        return false;
}

std::vector<std::pair<int, int>> DotsRuleEngine::findCompleteBoxes(IMove &move, IBoard &board){

    DotsMove &dotsMove = dynamic_cast<DotsMove&>(move);
    DotsBoard &dotsBoard = dynamic_cast<DotsBoard&>(board);
    std::vector<std::pair<int, int>> pos;

    if(dotsMove.moveDirection() == Direction::Horizontal){

        int Y = dotsMove.column();
        int X = dotsMove.row();

        if(!((Y < 0) || (Y > dotsBoard.width()))){

            if(!(X < 0 || X > dotsBoard.height())){
                if(isCompleteEmptyBox(X, Y, board)){

                    pos.push_back({X, Y});
                }
            }
            X -= 1;
            if(!(X < 0 || X > dotsBoard.height())){

                if(isCompleteEmptyBox(X, Y, board)){

                    pos.push_back({X, Y});
                }
            }
        }
    }

    else if(dotsMove.moveDirection() == Direction::Vertical){

        int Y = dotsMove.column();
        int X = dotsMove.row();

        if(!((X < 0) || (X > dotsBoard.height()))){

            if(!(Y < 0 || Y > dotsBoard.width())){
                if(isCompleteEmptyBox(X, Y, board)){
                    pos.push_back({X, Y});
                }
            }
            Y -= 1;
            if(!(Y < 0 || Y > dotsBoard.width())){

                if(isCompleteEmptyBox(X, Y, board)){

                    pos.push_back({X, Y});
                }
            }
        }
    }

    return pos;
}

