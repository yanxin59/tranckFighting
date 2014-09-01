//
//  Entity.h
//  tranckFighting
//
//  Created by Yan on 14-9-1.
//
//

#ifndef __tranckFighting__Entity__
#define __tranckFighting__Entity__

#include "cocos2d.h"

using namespace cocos2d;

class Entity:public Node
{
public:
    
    virtual void doDead();
    
protected:
    
    virtual void doAction();
    
    CC_SYNTHESIZE_PASS_BY_REF(bool, _isDead, IsDead);
    
    CC_SYNTHESIZE_PASS_BY_REF(int, _iSpeed, ISpeed);
    
    
};

#endif /* defined(__tranckFighting__Entity__) */
