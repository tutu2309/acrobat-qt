#ifndef MAP_H
#define MAP_H
#include <QPixmap>


class map
{
public:
    //构造背景函数
    map();
    //背景滚动坐标计算
    void mapPosition();
public:
    //背景图片
    QPixmap map1;
    QPixmap map2;

    //背景y轴坐标
    int map1_posy;
    int map2_posy;

    //背景滚动幅度
    int scroll_speed;
};

#endif // MAP_H
