#include "game.h"
#include "globals.h"
#include <QApplication>


int displayBoard[9]; // = {X, O, X, O, X, O, X, O, X};
CurrentPly currentPly;
Board board;
Ai ai;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Game game;

    game.show();

    return app.exec();
}
