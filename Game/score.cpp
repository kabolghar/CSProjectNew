#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score=0;
    //display the text
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",14));

}
void Score::increase(){
    score++;
    setPlainText("Score: " + QString::number(score));
}
int Score::getscore(){
    return score;
}
