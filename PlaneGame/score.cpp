#include "score.h"
#include <QFont>
#include <QFile>
#include <QByteArray>

Score::Score(QGraphicsTextItem *parent) :QGraphicsTextItem (parent)
{
    score=0;
    setPlainText("Score:"+QString::number(score)+"  Best Score: "+Get_Best_Score());
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

QString Score::Get_Best_Score()
{
    QFile file("text.txt"); // создаем объект класса QFile
        if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
            return "0"; // если это сделать невозможно, то завершаем функцию
        data = file.readAll();
        file.close();
    return  data;
}

void Score::Set_Best_Score(QGraphicsTextItem *parent)
{
   if (data.toInt()<score)
   {
       QFile file("text.txt");
       if (!file.open(QIODevice::WriteOnly)) // Проверяем, возможно ли открыть наш файл для чтения
           return;
       data.setNum(score);
       file.write(data);
       file.close();
   }
}
void Score::increase()
{
    score++;
    setPlainText("Score:"+QString::number(score)+"  Best Score: "+Get_Best_Score());
}

int Score::getscore()
{
    return score;
}
