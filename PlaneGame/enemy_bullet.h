#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H
#include <QObject>
#include "bullet.h"
#include <QGraphicsPixmapItem>


class Enemy_Bullet: public Bullet
{
    Q_OBJECT
public:
    Enemy_Bullet(QGraphicsItem *parent=0);
public slots:
    void move();
};

#endif // ENEMY_BULLET_H
