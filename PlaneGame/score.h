#ifndef SCORE_H
#define SCORE_H
#include <QByteArray>
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
   Score(QGraphicsTextItem * parent=0);
   QString Get_Best_Score();
   void Set_Best_Score(QGraphicsTextItem * parent=0);
   void increase();
   int getscore();
private:
    int score;
    QByteArray data;
};

#endif // SCORE_H
