#ifndef IBOARD_H
#define IBOARD_H

class IBoard
{
    int width_;
    int height_;


public:

    IBoard(int height, int width);
    virtual ~IBoard() = default;
    int width() const;
    int height() const;
};

#endif // IBOARD_H
