#ifndef BOMB_H
#define BOMB_H
#include "config.h"
#include <QPixmap>
#include <QVector>


class bomb
{
public:
    bomb();

    //更新爆炸信息
    void information();

public:
    //爆炸资源数组
    QVector<QPixmap> b_arr;

    //爆炸坐标
    int b_x;
    int b_y;

    //爆炸状态
    bool b_free;

    //爆炸切图时间间隔
    int b_recorder;

    //爆炸加载图片下标
    int b_index;
};

#endif // BOMB_H
