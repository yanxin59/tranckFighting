//
//  Entity.cpp
//  tranckFighting
//
//  Created by Yan on 14-9-1.
//
//

#include "Entity.h"

void Entity::doDead()
{
}

void Entity::doAction()
{
}

Entity::~Entity()
{
    CC_SAFE_RELEASE_NULL(_pSprite);
}