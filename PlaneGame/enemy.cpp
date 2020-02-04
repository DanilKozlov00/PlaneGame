#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand()
#include "game.h"
#include "enemy_bullet.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int random_number = rand() % 700;
    setPos(random_number,0);
    setPixmap(QPixmap(":/image/Enemy (2).png"));
    setTransformOriginPoint(50,50);
    setRotation(180);
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
    QTimer * timer_fire = new QTimer(this);
    connect(timer_fire,SIGNAL(timeout()),this,SLOT(fire()));
    timer_fire->start(1500);
}

void Enemy::fire()
{
    Enemy_Bullet  * bullet = new Enemy_Bullet();
    bullet->setPos(x()+55,y()+100);
    scene()->addItem(bullet);
}


void Enemy::move()
{
    setPos(x(),y()+5);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            game->score->increase();
            scene()->removeItem(this);
            delete this;
        }
    }
    if (pos().y() > 600)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
