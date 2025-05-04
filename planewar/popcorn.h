#ifndef POPCORN_H
#define POPCORN_H
#include <QPixmap>

class popcorn
{
public:
    popcorn();

    //设置坐标
    void position();

public:
    //设置爆米花
    QPixmap p_popcorn;

    //设置位置坐标
    int p_x;
    int p_y;

    //判定范围
    QRect p_rect;

    //是否闲置
    bool p_free;

    //爆米花速度
    int p_speed;
};


#endif // POPCORN_H
