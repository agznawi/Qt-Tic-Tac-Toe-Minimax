#pragma once
#include "Globals.h"


class Board
{
public:
    int board[9];
    void Init();
    void SetSquare(int location, int player);
    void UnsetSquare(int location);
    int GetSquare(int location);
    GameState Evaluate(int player);
};

extern Board board;
