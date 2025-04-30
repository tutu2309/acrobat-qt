#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>


Mainscene::Mainscene(QWidget *parent)
    : QWidget(parent)
{
    //对初始化游戏场景的调用
    initscene();
    //调用启动游戏
    play();

}

Mainscene::~Mainscene()
{

}

void Mainscene::initscene()
{


    //设置游戏场景窗口宽度高度
    setFixedSize(game_width,game_height);

    //设置游戏窗口标题
    setWindowTitle(game_title);

   //设置定时器
    timer.setInterval(game_rate);


}

void Mainscene::play()
{
    //启动定时器
    timer.start();

    //接受定时器信号条
    connect(&timer , &QTimer::timeout,[=](){

        //更新坐标并显示
        updatepos();
        update();
           } );
}

void Mainscene::updatepos()
{
    //更新坐标
    map.mapPosition();
}

void Mainscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //显示地图
    painter.drawPixmap(0, map.map1_posy,map.map1);
    painter.drawPixmap(0, map.map2_posy,map.map2);
}
