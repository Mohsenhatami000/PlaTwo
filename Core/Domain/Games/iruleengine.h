#ifndef IRULEENGINE_H
#define IRULEENGINE_H

#include "Imove.h"
#include "iboard.h"

class IRuleEngine
{


public:

    IRuleEngine();
    virtual bool validateMove(IMove &move, IBoard &board) = 0;
};

#endif // IRULEENGINE_H
