#include "GameOver.h"
#include <QTimer>
#include "game.h"
#include "menu.h"
#include <QApplication>
#include <QProcess>
#include <mainwindow.h>


extern Game *game;
MainWindow *m;
Menu *menu;

bool check=false;
GameOver::GameOver(): QObject()
{
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Over()));
    timer->start(1);
}

bool GameOver::Over()
{
    if (check==false)
    {
    if (game->health->getHealth()<=0)
    {
     check=true;
     game->score->Set_Best_Score();
     delete game;
     game->m->stop();

    }
    }
    return 0;
}
