//
//  Entity.h
//  tranckFighting
//
//  Created by Yan on 14-9-1.
//
//

#ifndef __tranckFighting__Entity__
#define __tranckFighting__Entity__

#include "config.h"

class Entity:public Node
{
public:
    
    Entity();
    
    virtual void doDead();
    
    virtual ~Entity();
    
protected:
    
    virtual void move() = 0;
    
    virtual void doAction() = 0;
    
    CC_SYNTHESIZE_PASS_BY_REF(bool, _isDead, IsDead);
    
    CC_SYNTHESIZE_PASS_BY_REF(int, _iSpeed, ISpeed);
    
    CC_SYNTHESIZE_RETAIN(Sprite*, _pSprite, bindSprite);
    
    CC_SYNTHESIZE_PASS_BY_REF(int, _entityType, EntityType);
};

#endif /* defined(__tranckFighting__Entity__) */
