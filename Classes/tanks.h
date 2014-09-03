//
//  tanks.h
//  tranckFighting
//
//  Created by 王紫叶 on 14-8-30.
//
//

#ifndef __tranckFighting__tanks__
#define __tranckFighting__tanks__


#include "cocos2d.h"
//坦克单例
using namespace cocos2d;

enum Rotation
{
    en_Up = 0,
    en_Right = 90,
    en_Down = 180,
    en_Left = 270
};

#define TANK_SPEED 2

#define SEGMENTSIZE 16

#include "Entity.h"
class tanks:public Entity {
private:
    
    tanks();
    
    tanks(const tanks & anotherTank){}//拷贝构造函数:防止单例被构造另一个
    
    tanks operator = (const tanks & anotherTank){
        
        return anotherTank;
    }//等号运算符重载:防止单例被复制另一个
    
    CREATE_FUNC(tanks);
    
private:
    
    Size _tankSize;
    
private:
    
    static tanks * instance;
    
protected:
    
//    Sprite * _pTank;//成员变量只为了加入图片
//    virtual void mineTankDie();//主坦克死亡
    
    virtual bool judge();//判断前方是否有障碍物
    
    virtual void up();//坦克向上移动方法
    
    virtual void down();//坦克向下移动方法
    
    virtual void left();//坦克向左移动方法
    
    virtual void right();//坦克向右移动方法
    
    virtual void doAction();

public:
    
    static tanks * getInstance();//获得子弹单例
    
    virtual void addFire();//坦克开火(己放坦克打敌方坦克)
    
    virtual Rect getBoundingBox();
    
    virtual void move(const Rotation &rRotation);
    
    virtual void move();
    
    virtual void doDead();
};
#endif /* defined(__tranckFighting__tanks__) */
