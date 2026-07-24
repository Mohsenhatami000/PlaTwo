#include "iboard.h"

IBoard::IBoard(int height, int width){
    height_ = height;
    width_ = width;
}

int IBoard::width() const{
    return width_;
}

int IBoard::height() const{
    return height_;
}
