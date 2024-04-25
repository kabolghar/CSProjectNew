#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMessageBox>
class Health: public QGraphicsTextItem {
public:
    Health(QGraphicsItem *parent = nullptr);
    void decrease();
    int gethealth();
private:
    int health;
    QMessageBox* msg = new QMessageBox;
};


#endif // HEALTH_H
