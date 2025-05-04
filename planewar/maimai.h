#ifndef MAIMAI_H
#define MAIMAI_H
#include <QPixmap>
    //矩形
#include <QRect>
#include "ball.h"

class maimai
{
public:
    maimai();

    //发射爆米花
    void shootball();
    //设置麦麦位置
    void position(int x,int y);

public:
    //设置麦麦
    QPixmap  m_maimai;

    //位置坐标
    double m_x;
    double m_y;

    //判定范围
   QRect m_rect;

   //红球数量
   ball m_balls[ballnum];

   //发射间隔
   int b_recorder;
};

#endif // MAIMAI_H
