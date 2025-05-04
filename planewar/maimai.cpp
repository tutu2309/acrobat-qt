#include "maimai.h"
#include "config.h"

maimai::maimai()
{
    //初始化麦麦资源
    m_maimai.load(maimaiphoto);

    //初始化坐标
    m_x =( game_width - m_maimai.width())* 0.5 ;
    m_y =game_height - m_maimai.height();

    //初始化范围边框
    m_rect.setWidth(m_maimai.width());
    m_rect.setHeight(m_maimai.height());
    m_rect.moveTo(m_x,m_y);
}

void maimai::shootball()
{
    //累加时间间隔记录
    b_recorder++;

    if(b_recorder<20)
    {
       return;
    }
    //发射红球
    b_recorder=0;
    for (int i=0;i<ballnum;i++)
    {
      if(m_balls[i].b_free)
    {
            m_balls[i].b_free =false;
            m_balls[i].b_x=m_x +55;
            m_balls[i].b_y=m_y -10;
            break;
}

    }
}

void maimai::position(int x, int y)
{
    m_x = x;
    m_y = y;
    m_rect.moveTo(m_x,m_y);

}
