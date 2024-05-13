#ifndef BLOCKS_H
#define BLOCKS_H
#include <QGraphicsRectItem>
class Blocks: public QGraphicsRectItem{

public:
    Blocks(QColor color, QGraphicsItem* parent=nullptr);
};

#endif // BLOCKS_H
