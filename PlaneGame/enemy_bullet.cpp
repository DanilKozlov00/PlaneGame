#include "enemy_bullet.h"
#include "QTimer"
#include "game.h"
#include "QThread"


extern Game *game;

Enemy_Bullet::Enemy_Bullet(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/image/Bullet (2).png"));
    QTimer * timer_bullet = new QTimer(this);
    connect(timer_bullet,SIGNAL(timeout()),this,SLOT(move()));
    timer_bullet->start(50);
}

void Enemy_Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()+10);
   if (pos().y()>600)
   {
        scene()->removeItem(this);
        delete this;
    }
}
