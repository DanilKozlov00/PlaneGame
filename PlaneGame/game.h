#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "score.h"
#include "health.h"
#include "QMediaPlayer"

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    QMediaPlayer *m;
};

#endif // GAME_H
