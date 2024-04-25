#include <QApplication>
#include "mainmenu.h"
#include "ui_mainmenu.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainMenu * open = new MainMenu();
    open->show();
    return a.exec();
}
