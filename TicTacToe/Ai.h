#pragma once


#include "Globals.h"


class Ai
{
private:
    enum { WIN_SCORE = 100, TIE_SCORE = 0, INF = 100000 };

public:
    Move Search(int player);
};

extern Ai ai;
