//
//  tanks.h
//  tranckFighting
//
//  Created by 王紫叶 on 14-8-30.
//
//

#ifndef __tranckFighting__tanks__
#define __tranckFighting__tanks__

#include <iostream>
#include "cocos2d.h"
//坦克单例
using namespace cocos2d;
class tanks:public Node{
private:
<<<<<<< HEAD
    
    tanks()
    
    {
        sp = Sprite::create("p1-a-cell-hd.png");
        
        sp->setPosition(Vec2(480,320));
        
        this->addChild(sp);
    
    }
    
    tanks(const tanks & anotherTank)
    {
    
    
    }
    tanks operator = (const tanks & anotherTank)
    {
    
=======
    tanks(){
        
            _pTank = Sprite::create("p1-a-cell.png");
            this->addChild(_pTank);
        }
    tanks(const tanks & anotherTank){}//拷贝构造函数:防止单例被构造另一个
    tanks operator = (const tanks & anotherTank){
        
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
        return anotherTank;
    }//等号运算符重载:防止单例被复制另一个
protected:
<<<<<<< HEAD
    
    Sprite * sp;
    
=======
    Sprite * _pTank;
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
    static tanks * instance;
    CREATE_FUNC(tanks);
<<<<<<< HEAD
    
    virtual void mineTankDie();
    
    Vec2 position;
  
=======
    virtual void mineTankDie();//主坦克死亡
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
    int rotation;
public:
    static tanks * getInstance();//获得子弹单例
    virtual void addFire();//坦克开火(己放坦克打敌方坦克)
    virtual void up();//坦克向上移动方法
    virtual void down();//坦克向下移动方法
    virtual void left();//坦克向左移动方法
    virtual void right();//坦克向右移动方法

<<<<<<< HEAD
=======
    

>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d

};





#endif /* defined(__tranckFighting__tanks__) */
