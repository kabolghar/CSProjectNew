#include "player.h"
#include "QtGui/qevent.h"
#include <QBrush>
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent){
    // draw rect
    setRect(0,0,100,10);
    QBrush brush(Qt::white);
    setBrush(brush);
}

double Player::getMidPoint(){
    return x()+rect().width()/2;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)
    {
        if(x()+80<800)
            setPos(x()+10,y());
    }

}
