#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
//定时器
#include<QTimer>
#include "map.h"
#include "maimai.h"
#include "ball.h"
#include "popcorn.h"
#include "bomb.h"
#include <QPushButton>


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

    //爆米花出场
    void popcornappear();

    //爆米花数组
    popcorn p_popcorns[popcornnum];

    //爆米花出场时间间隔
    int p_recorder;

    //检测碰撞
    void collision();

    //爆炸数组
    bomb bombs[bombnum];

    //背景定时器
    QTimer timer;

private:
    QPushButton *startButton;
    // 添加函数声明
        private slots:
            void onStartGameClicked();
};

#endif // MAINSCENE_H
