//
//  tanks.cpp
//  tranckFighting
//
//  Created by 王紫叶 on 14-8-30.
//
//

#include "tanks.h"
#include "GameScene.h"
#include "Map.h"

tanks * tanks::instance = nullptr;

tanks * tanks::getInstance()
{
    
    if (!instance) {
        instance = tanks::create();
        instance->setPosition(100, 50);

    }
     return instance;
}


void tanks::addFire(){
    
    _pTank->setPosition(_pTank->getPosition());
    _pTank->setRotation(_pTank->getRotation());
}

void tanks::mineTankDie(){
    
    
    
}

Rect tanks::getBoundingBox()
{
    auto tCurPos = getPosition();
    auto tSize = _pTank->getContentSize();
    return Rect(tCurPos.x, tCurPos.y, tSize.width, tSize.height);
}

void tanks::up(){
    
    _pTank->setRotation(0);
    if(judge())
        return ;
    setPositionY(getPositionY()+1);
    Size s = Director::getInstance()->getVisibleSize();
    Size sps = _pTank->getContentSize();
    if (getPositionY() >= (s.height - sps.height/2)) {
        
        setPositionY(s.height - sps.height/2);
    }


}

void tanks::down(){
    _pTank->setRotation(180);
    if(judge())
        return ;

    setPositionY(getPositionY()-1);
    Size sps = _pTank->getContentSize();
    if (getPositionY() < sps.height/2) {
        
        setPositionY(sps.height/2);
    }
}
void tanks::left(){
 
    _pTank->setRotation(270);
    if(judge())
        return ;

    setPositionX(getPositionX()-1);
    Size sps = _pTank->getContentSize();
    if (getPositionX() < sps.width/2) {
        setPositionX(sps.width/2);
    }

}
void tanks::right(){

    _pTank->setRotation(90);
    if(judge())
        return ;
    setPositionX(getPositionX()+1);
    Size s = Director::getInstance()->getVisibleSize();
    Size sps = _pTank->getContentSize();
    if (getPositionX() >= (s.width-sps.width/2 )) {
        setPositionX(s.width-sps.width/2);
    }

}

bool tanks::judge()
{
    auto tBg = (dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene()))->getMap()->m_bg;
    
    auto tRotate = _pTank->getRotation();
    
    auto px = 0;
    auto py = 0;
    
    if(tRotate == 0.0f)
    {
        py = (getPositionY() + _pTank->getContentSize().width / 2 + 16) / 16;
        px = getPositionX() / 16;
    }
    
    if(tRotate == 90.0f)
    {
        py = getPositionY() / 16;
        px = (getPositionX() + _pTank->getContentSize().width / 2 + 16) / 16;
    }
    
    if(tRotate == 180.0f)
    {
        py = (getPositionY() - (_pTank->getContentSize().width / 2 + 16)) / 16;
        px = getPositionX() / 16;
    }
    
    if(tRotate == 270.0f)
    {
        py = getPositionY() / 16;
        px = getPositionX() / 16;
    }
    
    if(px >= 59.0f)
    {
        px = 59.0f;
    }
    
    if(py >= 39.0f)
    {
        py = 39.0f;
    }
    
    if(tBg->getTileGIDAt(Vec2(px - 1, 40 - py - 1)))
    {
        return true;
    }
    
    return false;
}


