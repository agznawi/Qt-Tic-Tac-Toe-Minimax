#pragma once

#include "Board.h"
#include "Ai.h"
#include <QDialog>
#include <QPainter>

class Game : public QDialog
{
    Q_OBJECT

public:
    Game(QWidget *parent = 0);
    ~Game();

private:
    bool userTurn;
    int player;

    QPainter *painter;
    QRect boardRects[9];

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    GameState CheckGame();
    void Reset();
    void Tie();
    void Lose();
    void Win();
    void PlayAi();
};

