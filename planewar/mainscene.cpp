#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <QWidget>
#include <ctime>
#include <QMessageBox>



Mainscene::Mainscene(QWidget *parent)
    : QWidget(parent)
{

    startButton = new QPushButton("开始游戏", this);


        startButton->move(100, 100);

        setStyleSheet("background-image: url(:/new/prefix1/resource/background3.jpg);");
        setStyleSheet("background-image: url(:/new/prefix1/resource/background3.jpg); background - repeat: no - repeat; background - size: cover;");

        connect(startButton, &QPushButton::clicked, this, &Mainscene::onStartGameClicked);
    }

    void Mainscene::onStartGameClicked()
    {
        QMessageBox::information(this, "提示", "游戏即将开始！");
        startButton->hide(); // 隐藏“开始游戏”按钮
        // 实际开始游戏的逻辑代码

        //对初始化游戏场景的调用
            initscene();
            //调用启动游戏
            play();

}

Mainscene::~Mainscene()
{
 delete startButton;
}

void Mainscene::initscene()
{
    //设置游戏场景窗口宽度高度
    setFixedSize(game_width,game_height);

    //设置游戏窗口标题
    setWindowTitle(game_title);

   //设置定时器
    timer.setInterval(game_rate);

    //初始化爆米花出场间隔
    p_recorder=0;

    //随机数种子
    srand((unsigned int)time(NULL));


}

void Mainscene::play()
{
    //启动定时器
    timer.start();

    //接受定时器信号条
    connect(&timer , &QTimer::timeout,[=](){
        //爆米花出场
        popcornappear();

        //更新坐标并显示
        updatepos();
        update();

        //碰撞检测
        collision();
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

   //爆米花出场
    for (int i=0;i<popcornnum;i++)
    {
       if(p_popcorns[i].p_free==false)
       {
           p_popcorns[i].position();
       }
    }

    //计算爆炸照片
    for (int i =0;i<bombnum;i++)
    {
        if(bombs[i].b_free==false)
        {
            bombs[i].information();
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

  //显示爆米花
 for (int i=0;i<popcornnum;i++)
 {
    if(p_popcorns[i].p_free==false)
    {
        painter.drawPixmap(p_popcorns[i].p_x,p_popcorns[i].p_y,p_popcorns[i].p_popcorn);
    }
 }

 //显示爆炸
 for (int i =0;i<bombnum;i++)
 {
     if(bombs[i].b_free==false)
     {
         painter.drawPixmap(bombs[i].b_x,bombs[i].b_y
                            ,bombs[i].b_arr[bombs[i].b_index]);
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
//爆米花
void Mainscene::popcornappear()
{
    p_recorder++;
    if(p_recorder<30)
    {
            return;
    }
      p_recorder=0;
            for (int i =0;i<popcornnum;i++)
    {
        if(p_popcorns[i].p_free)
    {
        p_popcorns[i].p_free =false;

        p_popcorns[i].p_x=rand()%(game_width - p_popcorns[i].p_rect.width());
        p_popcorns[i].p_y=-p_popcorns[i].p_rect.height();
        break;
    }
  }
}

void Mainscene::collision()
{
  //遍历所有非空闲爆米花
    for (int i=0;i<popcornnum;i++)
    {
        //如果空闲继续循环寻找非空闲
        if(p_popcorns[i].p_free)
        {
        continue;
        }
   //红球
        for (int j =0;j<ballnum;j++)
        {
            if(m_maimai.m_balls[j].b_free)
            {
                continue;
            }

            //红球爆米花相碰
            if(p_popcorns[i].p_rect.intersects(m_maimai.m_balls[j].b_rect))
            {
                p_popcorns[i].p_free=true;
                m_maimai.m_balls[j].b_free=true;

                //进行爆炸
                for (int k=0;k<bombnum;k++)
                {
                    if(bombs[k].b_free)
                    {
                        bombs[k].b_free=false;
                        //更新爆炸坐标
                        bombs[k].b_x=p_popcorns[i].p_x;
                        bombs[k].b_y=p_popcorns[i].p_y;
                        break;
                }
            }
        }
    }
}
}
