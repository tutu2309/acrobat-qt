#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
//定时器
#include<QTimer>
#include "map.h"
#include "maimai.h"
#include "ball.h"

class Mainscene : public QWidget
{
    Q_OBJECT

public:
    Mainscene(QWidget *parent = 0);
    ~Mainscene();

    //初始化游戏场景
    void initscene();

    //开始游戏
    void play();

    //更新游戏坐标
    void updatepos();

    //传到屏幕上
    void paintEvent(QPaintEvent *);

    //设置背景
    map map;

    //设置麦麦
    maimai m_maimai;

    //拖拽鼠标移动麦麦，捕获鼠标信息
    void mouseMoveEvent(QMouseEvent *);

    //设置红球
    ball tempball;


    //背景定时器
    QTimer timer;
};

#endif // MAINSCENE_H
