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
extern Game * game;

Ball::Ball(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    setRect(0,0,30,30);
    QBrush bluebrush(Qt::blue);
    setBrush(bluebrush);
    QPen redpen(Qt::red);
    redpen.setWidth(3);
    moveX=0;
    moveY=0;//start position

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
double Ball::getcenter(){
    return x() + rect().width()/2;
}
void Ball::reverseball(){
    //check if a ball is out of bound
    double width = game->width();
    double height = game->height();
    //check from the top
    if(pos().y()<=0){
        moveY=-1*moveY;
    }
    //left edge
    if(pos().x()<=0){
        moveX=-1*moveX;
    }
    //right edge
    if(pos().x()>=width){
        moveX=-1*moveX;
    }
}

void Ball::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    double height = game->height();
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
        Blocks* block = dynamic_cast<Blocks*>(colliding_items[i]);
        Player* player = dynamic_cast<Player*>(colliding_items[i]);
        if(block){
            game->score->increase();//need to create a score object in game class
            double by= block->pos().y();
            double bx= block->pos().x();
            if (pos().y()>by+10 || pos().y()<by+10){
                moveY=-1*moveY;
            }
            if (pos().x()>bx+10 || pos().x()<bx+10){
                moveX=-1*moveX;
            }

            // delete block(s)
            game->scene->removeItem(block);
            delete block;
        }
        if(player){
            moveY=-1*moveY;// vertical direction
            //get horizontal direction
            moveX=(getcenter()-player->getMidPoint());//check if this works well
            return;
        }
        if (pos().y()>height){
            game->health->decrease();//recheck when health decreases
        }
    }

    reverseball();
    moveBy(moveX,moveY);
}

