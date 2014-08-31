//
//  tanks.cpp
//  tranckFighting
//
//  Created by 王紫叶 on 14-8-30.
//
//

#include "tanks.h"
tanks * tanks::instance = nullptr;
tanks * tanks::getInstance() {
    
    if (!instance) {
        instance = tanks::create();
    }
     return instance;
}
void tanks::addFire(){
    
    _pTank->setPosition(_pTank->getPosition());
    _pTank->setRotation(_pTank->getRotation());
}

void tanks::mineTankDie(){
    
    
    
}
void tanks::up(){
    
    setPositionY(getPositionY()+1);
    Size s = Director::getInstance()->getVisibleSize();
    Size sps = _pTank->getContentSize();
    if (getPositionY() >= (s.height - sps.height/2)) {
        
        setPositionY(s.height - sps.height/2);
    }
    _pTank->stopAllActions();
    
    _pTank->setRotation(0);
}
void tanks::down(){
    
    setPositionY(getPositionY()-1);
    Size sps = _pTank->getContentSize();
    if (getPositionY() < sps.height/2) {
        
        setPositionY(sps.height/2);
    }
    _pTank->stopAllActions();
    
    _pTank->setRotation(180);
}
void tanks::left(){
    
    setPositionX(getPositionX()-1);
       Size sps = _pTank->getContentSize();
    if (getPositionX() < sps.width/2) {
        setPositionX(sps.width/2);
    }
    _pTank->stopAllActions();
    _pTank->setRotation(270);
}
void tanks::right(){
 
    setPositionX(getPositionX()+1);
    Size s = Director::getInstance()->getVisibleSize();
    Size sps = _pTank->getContentSize();
    if (getPositionX() >= (s.width-sps.width/2 )) {
        setPositionX(s.width-sps.width/2);
    }
    _pTank->setRotation(90);
}