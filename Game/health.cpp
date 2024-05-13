#include "health.h"
#include <QFont>
#include <QMessageBox>
#include "game.h"
#include "score.h"
extern Game * game;
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    health=3;
    //display the text
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",14));

}
void Health::decrease() {
    qDebug() << "Current health: " << health;
    health--;
    qDebug() << "health after decrementing: " << health;
    setPlainText("Health: " + QString::number(health));

    if (health < 1) {
        msg->setWindowTitle("You have no health left"); // Set the window title
        msg->exec();
        //game->scene->clear();
    } else {
        // Create a new ball
        Ball *ball = new Ball;
        ball->setPos(300, 700);
        game->scene->addItem(ball);
    }

    // Remove and delete the existing ball
    QList<QGraphicsItem *> items = game->scene->items();
    for (int i = 0; i < items.size(); ++i) {
        Ball *ball = dynamic_cast<Ball *>(items[i]);
        if (ball) {
            game->scene->removeItem(ball);
            delete ball;
            break;
        }
    }
}

int Health::gethealth(){
    return health;
}
