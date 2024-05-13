#include "game.h"
#include "ball.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include "blocks.h"
#include <QScreen>


Game::Game(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(0, 0, 67*3*levels, 800); // 600 horizontally, 800 vertically
    scene->setBackgroundBrush(QBrush(Qt::black));
    setScene(scene);

    // Disable scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Resize the view to match the scene size
    setFixedSize(scene->width(), scene->height());
}

void Game:: startgame(){
    Ball *ball= new Ball(":/resources/Resources/Ball.png");
    ball->setPos((67*3*levels)/2,700);
    scene->addItem(ball);
    Player *player= new Player;
    player->setPos((((67*3*levels)/2)-100)/2,775);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    health=new Health;
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    createbl();
}

void Game::createbl(){
   QColor colors[] = {Qt::red, Qt::green, Qt::yellow, Qt::blue, Qt::cyan, Qt::magenta};
    for(int i=0;i<(levels*3);i++){//change according to level
        for(int j=0;j<(levels*2);j++){
           QColor color = colors[(i + j) % 6];
            Blocks *block = new Blocks(color);
            block->setPos(i*64,j*64);
            scene ->addItem(block);
        }
    }
}
bool Game::allblocksremoved(){
    QList<QGraphicsItem *> items = scene->items();
    for (int i = 0; i < items.size(); ++i) {
        if (dynamic_cast<Blocks *>(items[i])) {
            // If any block is found, return false
            return false;
        }
    }
    // If no blocks are found, return true
    return true;
}
void Game::nextlevel(){
    levels++;
    //close game instance
    //open a new one
}
void Game::exitgame(){
    //handle exiting the game
}
