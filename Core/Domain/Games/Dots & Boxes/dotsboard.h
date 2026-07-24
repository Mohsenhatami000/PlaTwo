#ifndef DOTSBOARD_H
#define DOTSBOARD_H

#include "Domain/Games/iboard.h"
#include "Domain/Enums/Enums.h"
#include "../Imove.h"
#include <cstdint>
#include <vector>

class DotsBoard : public IBoard
{

    std::vector<std::vector<std::uint8_t>> lineX_;
    std::vector<std::vector<std::uint8_t>> lineY_;
    std::vector<std::vector<std::uint8_t>> boxes_;


public:

    DotsBoard(int height, int width);
    void drawEdge(IMove *move);
    void drawBoxes(std::vector<std::pair<int, int>> coordinate, Turn turn);
    std::vector<std::vector<std::uint8_t>> lineX() const;
    std::vector<std::vector<std::uint8_t>> lineY() const;
    std::vector<std::vector<std::uint8_t>> boxes() const;
};

#endif // DOTSBOARD_H
