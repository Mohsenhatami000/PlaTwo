#ifndef DOTSRULEENGINE_H
#define DOTSRULEENGINE_H

#include "../iruleengine.h"
#include <utility>
#include <vector>

class DotsRuleEngine : public IRuleEngine
{
public:

    DotsRuleEngine();
    bool validateMove(IMove &move, IBoard &board);
    bool isCompleteEmptyBox(int X, int Y, IBoard &board);
    std::vector<std::pair<int, int>> findCompleteBoxes(IMove &move, IBoard &board);
};

#endif // DOTSRULEENGINE_H
