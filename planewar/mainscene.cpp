#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>


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

    //发射红球
    m_maimai.shootball();

    //更新坐标
    for (int i=0;i<ballnum;i++)
    {
        if(m_maimai.m_balls[i].b_free==false)
        {
            m_maimai.m_balls[i].position();
        }
    }




}

void Mainscene::paintEvent(QPaintEvent *)
{
 QPainter painter(this);

 //显示地图
 painter.drawPixmap(0, map.map1_posy,map.map1);
 painter.drawPixmap(0, map.map2_posy,map.map2);

 //显示麦麦
 painter.drawPixmap(m_maimai.m_x,m_maimai.m_y,m_maimai.m_maimai);

 //显示红球
 for (int i=0;i<ballnum;i++)
 {
     if(m_maimai.m_balls[i].b_free==false)
     {
   painter.drawPixmap(m_maimai.m_balls[i].b_x,m_maimai.m_balls[i].b_y,m_maimai.m_balls[i].pball );
     }
 }

}

void Mainscene::mouseMoveEvent(QMouseEvent * event)
{
int x= event->x()-m_maimai.m_rect.width()*0.5;
int y= event->y()-m_maimai.m_rect.height()*0.5;

//防止飞机出边界，设置边界检测
if(x<=0)
{
  x=0;
}
if(x>=game_width-m_maimai.m_rect.width())
{
  x=game_width-m_maimai.m_rect.width();
}
if(y<=0)
{
   y=0;
}
if(y>=game_height-m_maimai.m_rect.height())
{
   y=game_height-m_maimai.m_rect.height();
}

m_maimai.position(x,y);
}
