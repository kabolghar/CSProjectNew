#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Player: public QGraphicsRectItem{
public:

    Player(QGraphicsItem* parent=NULL);
    double getMidPoint();
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
