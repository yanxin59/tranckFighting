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
    
    virtual ~Entity();
    
protected:
    
    virtual void move();
    
    virtual void doAction() = 0;
    
    CC_SYNTHESIZE_PASS_BY_REF(bool, _isDead, IsDead);
    
    CC_SYNTHESIZE_PASS_BY_REF(int, _iSpeed, ISpeed);
    
    CC_SYNTHESIZE_RETAIN(Sprite*, _pSprite, bindSprite);
    
    CC_SYNTHESIZE_PASS_BY_REF(int, _entityType, EntityType);
};

#endif /* defined(__tranckFighting__Entity__) */
