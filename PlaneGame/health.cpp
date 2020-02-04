#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 7;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: n
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: n-1
}

int Health::getHealth()
{
    return health;
}

