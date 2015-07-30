#include "Board.h"
#include "Globals.h"


void Board::Init()
{
    for(int i = 0; i < 9; i++)
        board[i] = EMPTY;
}


void Board::SetSquare(int location, int player)
{
    board[location] = player;
}


int Board::GetSquare(int location)
{
    return board[location];
}


void Board::UnsetSquare(int location)
{
    board[location] = EMPTY;
}


GameState Board::Evaluate(int player)
{
    // Raws
    if (board[0] != EMPTY && board[0] == board[1] && board[1] == board[2]) return (board[0] == player)? WIN : LOSE;
    if (board[3] != EMPTY && board[3] == board[4] && board[4] == board[5]) return (board[3] == player)? WIN : LOSE;
    if (board[6] != EMPTY && board[6] == board[7] && board[7] == board[8]) return (board[6] == player)? WIN : LOSE;
    // Columns
    if (board[0] != EMPTY && board[0] == board[3] && board[3] == board[6]) return (board[0] == player)? WIN : LOSE;
    if (board[1] != EMPTY && board[1] == board[4] && board[4] == board[7]) return (board[1] == player)? WIN : LOSE;
    if (board[2] != EMPTY && board[2] == board[5] && board[5] == board[8]) return (board[2] == player)? WIN : LOSE;
    // Diagonals
    if (board[0] != EMPTY && board[0] == board[4] && board[4] == board[8]) return (board[0] == player)? WIN : LOSE;
    if (board[2] != EMPTY && board[2] == board[4] && board[4] == board[6]) return (board[2] == player)? WIN : LOSE;

    // Check for playing
    for(int i = 0; i < 9; i++)
        if (board[i] == EMPTY)
            return PLAY;

    // If we got to here it's tie
    return TIE;
}
