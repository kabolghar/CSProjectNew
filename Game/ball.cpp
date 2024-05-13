#include "ball.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QList>
#include <QDebug>
#include "score.h"
#include "game.h"
#include "blocks.h"
#include <QBrush>
#include "player.h"
#include <QGraphicsScene>
#include <QDebug>
extern Game * game;

Ball::Ball(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    setRect(0,0,30,30);
    QBrush bluebrush(Qt::blue);
    setBrush(bluebrush);
    QPen redpen(Qt::red);
    redpen.setWidth(3);
    moveX=0;
    moveY=-5;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
double Ball::getcenter(){
    return x() + rect().width()/2;
}
void Ball::blockcollision(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i) {
        Blocks* block = dynamic_cast<Blocks*>(colliding_items[i]);
        if (block) {
            qDebug() << "Ball collided with block";
            //game->score->increase();//this line causes a crash
            // Remove block from scene if it exists in the scene
            if (block->scene()) {
                qDebug() << "block removed from scene";
                game->scene->removeItem(block);
                delete block;
            }
            moveY = -moveY;
            return;
        }
    }
}
void Ball::playercollision(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i) {
        Player* player = dynamic_cast<Player*>(colliding_items[i]);
        if (player) {
            moveY = -moveY;
            moveX=(moveX+getcenter()-player->getMidPoint())/10;
            return;
        }
    }
}
void Ball::move(){
    double height = game->height();
    blockcollision();
    playercollision();
    // Handle out of bounds and continue movement
    if (pos().y()>height){
        qDebug() << "health decrease is called " ;
        game->health->decrease();//recheck when health decreases

    }
    if (pos().y() <= 0) {
        moveY = -moveY; // Reverse vertical direction
    }
    if (pos().x() <= 0 || pos().x() >= game->width()) {
        moveX = -moveX; // Reverse horizontal direction
    }

    moveBy(moveX,moveY);
}
