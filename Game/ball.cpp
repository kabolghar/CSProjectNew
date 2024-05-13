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

Ball::Ball(const QString& imagePath, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(QPixmap(imagePath).scaled(35, 35), parent){
    moveX=0;
    moveY=-7;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
}
double Ball::getcenter(){
    return x() + pixmap().width() / 2.0;
}
void Ball::blockcollision(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i) {
        Blocks* block = dynamic_cast<Blocks*>(colliding_items[i]);
        if (block) {
            qDebug() << "Ball collided with block";
            // Remove block from scene if it exists in the scene
            if (block->scene()) {
                qDebug() << "block removed from scene";
                game->scene->removeItem(block);
                delete block;
            }
            moveY = -moveY;
            //if it collides from the side chanve movex
            if (pos().x() > (block->pos().x() + 10) || block->pos().x() > (pos().x()+10) ){
                moveX = - moveX;
            }
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
        moveY = -moveY;
    }

    if (pos().y() <= 0) {
        moveY = -moveY; // Reverse vertical direction
    }
    if (pos().x() <= 0 || pos().x() >= game->width()) {
        moveX = -moveX; // Reverse horizontal direction
    }
    if (game->allblocksremoved()) {
        qDebug() << "Player wins!";
    }
    moveBy(moveX,moveY);
}
