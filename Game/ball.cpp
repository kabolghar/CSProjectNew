#include <QGraphicsRectItem>
#include <QObject>
#include "ball.h"
#include <QTimer>
#include <QList>
#include <QDebug>
#include "score.h"
#include "game.h"
#include "blocks.h"
#include <QBrush>
#include "player.h"
extern Game * game;

Ball::Ball(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    setRect(0,0,30,30);//adjust starting position
    QBrush bluebrush(Qt::blue);
    setBrush(bluebrush);
    moveX=0;
    moveY=0;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Ball::reverseball(){
    //check if ball is out of bound
    //check from the top
    if(pos().y()<=0){
        moveY=-1*moveY;
    }
    //left edge
    if(pos().x()<=0){
        moveX=-1*moveX;
    }
    //right edge
    if(pos().x()>=800){
        moveX=-1*moveX;
    }
}

void Ball::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
        Blocks* block = dynamic_cast<Blocks*>(colliding_items[i]);
        if(block){
            game->score->increase();//need to create a score object in game class
            moveY=-1*moveY;
            moveX=-1*moveX;

            // delete block(s)
            game->scene->removeItem(block);
            delete block;
        }
        Player* player = dynamic_cast<Player*>(colliding_items[i]);
        if(player){
            moveY=-1*moveY;
        }
        if (pos().y()>600){
            game->health->decrease();
        }
    }

    reverseball();
    moveBy(moveX,moveY);
}

