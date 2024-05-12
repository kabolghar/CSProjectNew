#include "game.h"
#include "ball.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include "blocks.h"

Game::Game(QWidget *parent):QGraphicsView(parent){
    scene = new QGraphicsScene(0,0,600,800);//600 horizontally, 800 vertically
    setScene(scene);
   // setMouseTracking(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void Game:: startgame(){
    Ball *ball= new Ball;
    ball->setPos(300,700);
    scene->addItem(ball);
    Player *player= new Player;
    player->setPos(250,775);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    createbl();
}

void Game::createbl(){
   for(int i=0;i<13;i++){
        for(int j=0;j<6;j++){
            Blocks *block = new Blocks();
            block->setPos(i*64,j*64);
            scene ->addItem(block);
        }
    }
}
