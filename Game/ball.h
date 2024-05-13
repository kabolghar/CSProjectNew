#ifndef BALL_H
#define BALL_H
#include <QGraphicsRectItem>
#include <QObject>

extern int levels;
class Ball:  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ball(const QString& imagePath, QGraphicsItem* parent=nullptr);
    double getcenter();
    void blockcollision();
    void playercollision();

public slots:
    void move();
private:
    double moveX;
    double moveY;
};

#endif // BALL_H
