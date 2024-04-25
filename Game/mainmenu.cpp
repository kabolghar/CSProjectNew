#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "game.h"

Game *game;

MainMenu::MainMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->logolabel->setPixmap(QPixmap(":/resources/Resources/Breakout Game Logo.png"));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_startButton_clicked()
{
    this->~MainMenu();
    game = new Game();
    game->show();
    game->startgame();

}


void MainMenu::on_exitButton_clicked()
{
    this->~MainMenu();
}

