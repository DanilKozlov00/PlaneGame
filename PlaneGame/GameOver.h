#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QObject>


class GameOver: public QObject
{
    Q_OBJECT
public:
    GameOver();
public slots:
    bool Over();
};

#endif // GAMEOVER_H
