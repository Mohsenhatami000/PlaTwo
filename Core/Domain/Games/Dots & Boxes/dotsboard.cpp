#include "dotsboard.h"
#include "dotsmove.h"

#include <stdexcept>


DotsBoard::DotsBoard(int height, int width): IBoard(height, width)
    ,lineX_(height + 1, std::vector<std::uint8_t>(width, 0))
    ,lineY_(height, std::vector<std::uint8_t>(width + 1, 0))
    ,boxes_(height, std::vector<std::uint8_t>(width, 0)){};

void DotsBoard::drawEdge(IMove *move){
    DotsMove *dotsMove = dynamic_cast<DotsMove*>(move);
    if(!dotsMove){
        throw std::out_of_range("cast Failed!");
    }
    int row = dotsMove->row();
    int column = dotsMove->column();
    Direction moveDirection = dotsMove->moveDirection();

    if(moveDirection == Direction::Horizontal){
        lineX_[row][column] = 1;
    }
    else if(moveDirection == Direction::Vertical){
        lineY_[row][column] = 1;
    }

}

void DotsBoard::drawBoxes(std::vector<std::pair<int, int>> coordinate, Turn turn){
    if(coordinate.size() == 0){
        return;
    }
    else if(coordinate.size() == 1){
        if(turn == Turn::Host){
            boxes_[coordinate[0].first][coordinate[0].second] = 1;
        }
        else if(turn == Turn::Guest){
            boxes_[coordinate[0].first][coordinate[0].second] = 2;
        }
    }
    else{
        if(turn == Turn::Host){
            boxes_[coordinate[0].first][coordinate[0].second] = 1;
            boxes_[coordinate[1].first][coordinate[1].second] = 1;
        }
        else if(turn == Turn::Guest){
            boxes_[coordinate[0].first][coordinate[0].second] = 2;
            boxes_[coordinate[1].first][coordinate[1].second] = 2;
        }
    }
}

std::vector<std::vector<std::uint8_t>> DotsBoard::lineX() const{
    return lineX_;
}

std::vector<std::vector<std::uint8_t>> DotsBoard::lineY() const{
    return lineY_;
}

std::vector<std::vector<std::uint8_t>> DotsBoard::boxes() const{
    return boxes_;
}