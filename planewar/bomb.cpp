#include "bomb.h"

bomb::bomb()
{
    //放入数组
    for (int i=1;i<=bombmax;i++)
    {
        QString str =QString(bombphoto).arg(i);
        b_arr.push_back(QPixmap(str));
    }

    //坐标初始化
    b_x=0;
    b_y=0;

    //空闲状态
    b_free=true;

    //当前播放图片下标
    b_index=0;

    //间隔记录
    b_recorder=0;
}

void bomb::information()
{
    //空闲状态
    if(b_free)
    {
        return;
    }
    b_recorder++;
    //未达爆炸间隔
    if(b_recorder<20)
    {
        return;
    }
    //重置
    b_recorder=0;

    //切换下标
    b_index++;

    //计算下标
        if(b_index >bombmax-1)
    {
        b_index =0;
        b_free=true;
    }

}
