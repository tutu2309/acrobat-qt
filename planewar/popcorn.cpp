#include "popcorn.h"
#include "config.h"

popcorn::popcorn()
{
    //初始化爆米花资源
    p_popcorn.load(popcornphoto);

    //初始化位置
    p_x=0;
    p_y=0;

    //初始化状态
    p_free = true;

    //设置速度
    p_speed=5;

    //边框范围
    p_rect.setWidth(p_popcorn.width());
    p_rect.setHeight(p_popcorn.height());
    p_rect.moveTo(p_x,p_y);
}

void popcorn::position()
{
    //空闲状态
    if(p_free)
    {
        return;
    }

    p_y+=p_speed;
    p_rect.moveTo(p_x,p_y);

    //若爆米花超出下界则重置,让其完全飞出去
    if(p_y >= game_height + p_rect.height())
    {
        p_free = true;
    }
}
