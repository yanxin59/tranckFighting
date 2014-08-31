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
<<<<<<< HEAD



void tanks::mineFireEnemy(){
    
    sp->setPosition(sp->getPosition());
    
    sp->setRotation(sp->getRotation());

    
    
=======
void tanks::addFire(){
    
    _pTank->setPosition(_pTank->getPosition());
    _pTank->setRotation(_pTank->getRotation());
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
}

void tanks::mineTankDie(){
    
    
    
}
void tanks::up(){
    
<<<<<<< HEAD
    sp->setPositionY(sp->getPositionY()+sp->getContentSize().height/2);
    
    Size s = Director::getInstance()->getVisibleSize();
    
    Size sps = sp->getContentSize();
    
    
    if (sp->getPositionY() >= (s.height - sps.height/2)) {
        
        sp->setPositionY(s.height - sps.height/2);
        
    }
             sp->setRotation(0);
=======
    setPositionY(getPositionY()+1);
    Size s = Director::getInstance()->getVisibleSize();
    Size sps = _pTank->getContentSize();
    if (getPositionY() >= (s.height - sps.height/2)) {
        
        setPositionY(s.height - sps.height/2);
    }
    _pTank->stopAllActions();
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
    
    _pTank->setRotation(0);
}
void tanks::down(){
    
<<<<<<< HEAD
    sp->setPositionY(sp->getPositionY()-sp->getContentSize().height/2);
    
 
    
    Size sps = sp->getContentSize();
    
    if (sp->getPositionY() < sps.height/2) {
=======
    setPositionY(getPositionY()-1);
    Size sps = _pTank->getContentSize();
    if (getPositionY() < sps.height/2) {
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
        
        sp->setPositionY(sps.height/2);
    }
<<<<<<< HEAD

    
    sp->setRotation(180);
=======
    _pTank->stopAllActions();
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
    
    _pTank->setRotation(180);
}
void tanks::left(){
    
<<<<<<< HEAD
    
    sp->setPositionX(sp->getPositionX()-sp->getContentSize().width/2);
    
       Size sps = sp->getContentSize();
    
    if (sp->getPositionX() < sps.width/2) {
        
        sp->setPositionX(sps.width/2);
    }

    
    sp->setRotation(270);
    
=======
    setPositionX(getPositionX()-1);
       Size sps = _pTank->getContentSize();
    if (getPositionX() < sps.width/2) {
        setPositionX(sps.width/2);
    }
    _pTank->stopAllActions();
    _pTank->setRotation(270);
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
}
void tanks::right(){
<<<<<<< HEAD
    
    
    sp->setPositionX(sp->getPositionX()+sp->getContentSize().width/2);
    
    Size s = Director::getInstance()->getVisibleSize();
    
    Size sps = sp->getContentSize();

    
    if (sp->getPositionX() >= (s.width-sps.width/2 )) {
        
        sp->setPositionX(s.width-sps.width/2);
    }
    

    
    sp->setRotation(90);
    
}
=======
 
    setPositionX(getPositionX()+1);
    Size s = Director::getInstance()->getVisibleSize();
    Size sps = _pTank->getContentSize();
    if (getPositionX() >= (s.width-sps.width/2 )) {
        setPositionX(s.width-sps.width/2);
    }
    _pTank->setRotation(90);
}
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
