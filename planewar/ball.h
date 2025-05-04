#ifndef BALL_H
#define BALL_H
#include "config.h"
#include <QPixmap>

class ball
{
public:
    ball();

    //设置红球坐标
    void position();

public:
    //红球资源
    QPixmap pball;

    //红球坐标
    int b_x;
    int b_y;

    //发射速度
    int b_speed;

    //红球是否闲置（设置n个红球待发）
    bool b_free;

    //判定范围
    QRect b_rect;

};

#endif // BALL_H
