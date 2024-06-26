#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include "ball.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "score.h"
#include "health.h"
#include "player.h"

extern int levels;
class Game:public QGraphicsView
{
public:
    Game(QWidget *parent=0);
    QGraphicsScene *scene;
    Score *score;
    Health *health;
    void startgame();
    void genblocks(int gen);
    void createbl();
    bool allblocksremoved();
    static void nextlevel();
    static void exitgame();
};

#endif // GAME_H
