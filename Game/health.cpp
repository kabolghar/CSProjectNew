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
void Health::decrease(){
    health--;
    setPlainText("Health: " + QString::number(health));

    if (health<1){
        msg->setWindowTitle("Game is over"); // Set the window title
        int s=game->score->getscore();
        msg->setText("your score is: "+QString::number(s)); // Set the main message text
        msg->exec();
        game->scene->clear();
    }

}
int Health::gethealth(){
    return health;
}
