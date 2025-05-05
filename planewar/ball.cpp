#include "ball.h"

ball::ball()
{
    //初始化红球资源
   pball.load(ballphoto);

   //红球坐标
   b_x=game_width * 0.5 - pball.width() * 0.5;
   b_y=game_height;

   //红球状态空闲或在发射
   b_free =true;

   //红球速度
   b_speed =7;

   //红球边框范围
   b_rect.setWidth(pball.width());
   b_rect.setHeight(pball.height());
   b_rect.moveTo(b_x,b_y);


}

void ball::position()
{
    //空闲时红球为默认，无需计算坐标
   if(b_free)
   {
       return;
   }

   //移动红球
   b_y -= b_speed;
   b_rect.moveTo(b_x,b_y);

   //红球移动超过背景时重回空闲状态
   if(b_y<=-b_rect.height())
   {
       b_free=true;
   }
}
