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
using namespace cocos2d;

class tanks:public Node{
    
private:
    
    tanks()
    
        {
            sp = Sprite::create("monster_59.png",Rect(0,0,64,96));
            this->addChild(sp);
        }
    
    
    tanks(const tanks & anotherTank)
    {
    
    
    }
    tanks operator = (const tanks & anotherTank)
    {
    
        return anotherTank;
    
    }
    
protected:
    
    Sprite * sp;

    static tanks * instance;
    
    CREATE_FUNC(tanks);
    
    virtual void mineTankDie();

    Vec2 position;
  
    int rotation;
    
public:
    

    
    static tanks * getInstance();

    virtual void mineFireEnemy();
    
    virtual void up();
    
    virtual void down();
    
    virtual void left();
    
    virtual void right();

    virtual void playdownAnimation();
    
    virtual void playupAnimation();
    
    virtual void playleftAnimation();
    
    virtual void playrightAnimation();
    
    


};





#endif /* defined(__tranckFighting__tanks__) */
