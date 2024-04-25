#include "player.h"
#include "QtGui/qevent.h"
#include <QBrush>

Player::Player(QGraphicsItem *parent){
    // draw rect
    setRect(0,0,60,10);
    QBrush brush;
    brush.setColor(Qt::white);
    setBrush(brush);
}

double Player::getMidPoint(){
    return x()+rect().width()/2;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left || event->key() == Qt::Key_A)
    {
        if(x()>0)
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right || event->key() == Qt::Key_D)

    {
        if(x()+80<800)
            setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Up || event->key() == Qt::Key_W)

    {
        if(y()>0)
            setPos(x(),y()-10);
    }
    else if(event->key()== Qt::Key_Down || event->key() == Qt::Key_S)


        if(y()+80<600)
            setPos(x(),y()+10);
    }
