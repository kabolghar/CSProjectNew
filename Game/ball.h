#ifndef BALL_H
#define BALL_H
#include <QGraphicsRectItem>
#include <QObject>

class Ball:  public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Ball(QGraphicsItem* parent=nullptr);
    void reverseball();
    double getcenter();
    void playercollision();
    void blockcollision();

public slots:
    void move();
private:
    double moveX;
    double moveY;
};

#endif // BALL_H
