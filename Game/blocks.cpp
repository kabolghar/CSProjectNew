#include "blocks.h"
#include <QBrush>

Blocks::Blocks(QGraphicsItem* parent): QGraphicsRectItem(parent){

    setRect(0,0,60,30);//adjust starting position
    QBrush redbrush(Qt::red);
    setBrush(redbrush);
}
