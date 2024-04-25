/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QLabel *logolabel;
    QSplitter *splitter;
    QPushButton *startButton;
    QPushButton *exitButton;

    void setupUi(QDialog *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(715, 469);
        logolabel = new QLabel(MainMenu);
        logolabel->setObjectName("logolabel");
        logolabel->setGeometry(QRect(50, 10, 701, 321));
        splitter = new QSplitter(MainMenu);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(320, 370, 71, 71));
        splitter->setOrientation(Qt::Vertical);
        startButton = new QPushButton(splitter);
        startButton->setObjectName("startButton");
        splitter->addWidget(startButton);
        exitButton = new QPushButton(splitter);
        exitButton->setObjectName("exitButton");
        splitter->addWidget(exitButton);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QDialog *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Dialog", nullptr));
        logolabel->setText(QCoreApplication::translate("MainMenu", "Logo Here", nullptr));
        startButton->setText(QCoreApplication::translate("MainMenu", "Start", nullptr));
        exitButton->setText(QCoreApplication::translate("MainMenu", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
