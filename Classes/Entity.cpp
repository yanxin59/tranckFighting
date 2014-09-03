//
//  Entity.cpp
//  tranckFighting
//
//  Created by Yan on 14-9-1.
//
//

#include "Entity.h"

Entity::Entity():_pSprite(nullptr), _isDead(false), _iSpeed(0), _entityType(1){}

Entity::~Entity()
{
    CC_SAFE_RELEASE_NULL(_pSprite);
}

void Entity::doDead()
{
    doAction();
}



