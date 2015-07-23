#include "game.h"
#include "board.h"
#include "ai.h"
#include "globals.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

/***************************************
 * Constructor                         *
 ***************************************/
Game::Game(QWidget *parent) : QDialog(parent)
{
    // Set window title and fixed size
    this->setWindowTitle("Tic Tac Toe");
    this->setFixedSize(300, 300);

    // Create the gameboard as a matrix of
    // 9 rects each of 100 x 100 size
    QSize size(100, 100);
    boardRects[0] = QRect(QPoint(0, 0), size);
    boardRects[1] = QRect(QPoint(0, 100), size);
    boardRects[2] = QRect(QPoint(0, 200), size);
    boardRects[3] = QRect(QPoint(100, 0), size);
    boardRects[4] = QRect(QPoint(100, 100), size);
    boardRects[5] = QRect(QPoint(100, 200), size);
    boardRects[6] = QRect(QPoint(200, 0), size);
    boardRects[7] = QRect(QPoint(200, 100), size);
    boardRects[8] = QRect(QPoint(200, 200), size);

    // Set player symbol to X
    player = X;

}

/***************************************
 * Destructor                          *
 ***************************************/
Game::~Game()
{

}

/***************************************
 * paintEvent function                 *
 ***************************************/
void Game::paintEvent(QPaintEvent *e)
{
    painter = new QPainter(this);

    painter->fillRect(this->rect(), QColor(186, 168, 210));

    QPen borderPen(Qt::yellow);
    borderPen.setWidth(4);

    painter->setPen(borderPen);
    painter->drawRects(boardRects, 9);

    for(int i = 0; i < 9; i++)
    {
        QString path;
        switch(displayBoard[i])
        {
        case EMPTY: path = ""; break;
        case X: path = ":/images/X.png"; break;
        case O: path = ":/images/O.png"; break;
        }

        painter->drawPixmap(boardRects[i].x()+10, boardRects[i].y()+10,
                           boardRects[i].width()-20, boardRects[i].height()-20,
                           QPixmap(path));
    }
}

/***************************************
 * mousePressEvent() is called when    *
 * the player presses a mouse button.  *
 * It contains the game loop           *
 ***************************************/
void Game::mousePressEvent(QMouseEvent *e)
{
    for(int i = 0; i < 9; i++)
    {
        if(boardRects[i].contains(e->pos()) && displayBoard[i] == EMPTY)
        {
            if(CheckGame() == PLAY)
            {
                board.SetSquare(i, currentPly.player);
                displayBoard[i] = currentPly.player;
                QWidget::update();
            }

            if(CheckGame() == WIN)
            {
                if(currentPly.player == player)
                    Win();
                else
                    Lose();
                return;
            }
            if(CheckGame() == LOSE)
            {
                if(currentPly.player == player)
                    Lose();
                else
                    Win();
                return;
            }
            if(CheckGame() == TIE)
            {
                Tie();
                return;
            }
            if(CheckGame() == PLAY)
            {
                currentPly.Toggle();

                PlayAi();
                QWidget::update();
            }

            if(CheckGame() == WIN)
            {
                if(currentPly.player == player)
                    Win();
                else
                    Lose();
                return;
            }
            if(CheckGame() == LOSE)
            {
                if(currentPly.player == player)
                    Lose();
                else
                    Win();
                return;
            }
            if(CheckGame() == TIE)
            {
                Tie();
                return;
            }

            if(CheckGame() == PLAY)
            {
                currentPly.Toggle();
                return;
            }

            break;
        }
    }
}

/***************************************
 * Shows "tie" message                 *
 ***************************************/
void Game::Tie()
{
    QMessageBox tie;
    tie.setWindowTitle("Result");
    tie.setText("Tie");
    tie.setFixedSize(400, 400);
    tie.exec();
    Reset();
}

/***************************************
 * Shows "lose" message, when player   *
 * loses the game                      *
 ***************************************/
void Game::Lose()
{
    QMessageBox lose;
    lose.setWindowTitle("Result");
    lose.setText("You lose");
    lose.setFixedSize(400, 400);
    lose.exec();
    Reset();
}

/***************************************
 * Shows "win" message, when player    *
 * wins the game. No way this function *
 * will be called in a perfect search. *
 ***************************************/
void Game::Win()
{
    QMessageBox win;
    win.setWindowTitle("Result");
    win.setText("You win");
    win.setFixedSize(400, 400);
    win.exec();
    Reset();
}

/***************************************
 * CheckGame() checks the game status  *
 * using board.Evaluate() to control   *
 * the game flow appropriately         *
 ***************************************/
GameState Game::CheckGame()
{
    return board.Evaluate(currentPly.player);
}

/****************************************
 * Resets the game for a new match      *
 ****************************************/
void Game::Reset()
{
    painter->end();
    board.Init();
    currentPly.player = X;
    for(int i = 0; i < 9; i++)
    {
        displayBoard[i] = EMPTY;
    }
}

/****************************************
 * plays AI turn                        *
 ****************************************/
void Game::PlayAi()
{
    Move bestMove = ai.Search(currentPly.player);
    board.SetSquare(bestMove.location, currentPly.player);
    displayBoard[bestMove.location] = currentPly.player;
}
