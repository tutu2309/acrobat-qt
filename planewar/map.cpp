#include "map.h"
#include "config.h"

map::map()
{
    //初始化背景
    map1.load(mappath);
    map2.load(mappath);

    //初始化y轴坐标
    map1_posy = -game_height;
    map2_posy = 0;

    //背景滚动速度
    scroll_speed = 2;
}

void map::mapPosition()
{
//对第一张背景处理
    map1_posy += scroll_speed;
    if(map1_posy >=0)
    {
        map1_posy = -game_height;
    }
//处理第二张背景
    map2_posy += scroll_speed;
    if(map2_posy >= game_height)
    {
        map2_posy = 0;
    }

}
