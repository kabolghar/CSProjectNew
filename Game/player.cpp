#include "player.h"
#include "QtGui/qevent.h"
#include <QBrush>
#include <QGraphicsScene>
#include <QKeyEvent>

Player::Player(QGraphicsItem *parent){
    // draw rect
    setRect(0,0,100,10);
    QBrush brush;
    brush.setColor(Qt::white);
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
   /* else if(event->key()== Qt::Key_Up)

    {
        if(y()>0)
            setPos(x(),y()-10);
    }
    else if(event->key()== Qt::Key_Down)
        if(y()+80<600)
            setPos(x(),y()+10);*/ //player only moves horizontally
    }
