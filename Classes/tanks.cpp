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



void tanks::mineFireEnemy(){
    
    sp->setPosition(sp->getPosition());
    
    sp->setRotation(sp->getRotation());

    
    
}

void tanks::mineTankDie(){
    
    
    
}



void tanks::up(){
    
    sp->setPositionY(sp->getPositionY()+sp->getContentSize().height/2);
    
    Size s = Director::getInstance()->getVisibleSize();
    
    Size sps = sp->getContentSize();
    
    
    if (sp->getPositionY() >= (s.height - sps.height/2)) {
        
        sp->setPositionY(s.height - sps.height/2);
        
    }
             sp->setRotation(0);
    
}

void tanks::down(){
    
    sp->setPositionY(sp->getPositionY()-sp->getContentSize().height/2);
    
 
    
    Size sps = sp->getContentSize();
    
    if (sp->getPositionY() < sps.height/2) {
        
        sp->setPositionY(sps.height/2);
    }

    
    sp->setRotation(180);
    
}

void tanks::left(){
    
    
    sp->setPositionX(sp->getPositionX()-sp->getContentSize().width/2);
    
       Size sps = sp->getContentSize();
    
    if (sp->getPositionX() < sps.width/2) {
        
        sp->setPositionX(sps.width/2);
    }

    
    sp->setRotation(270);
    
}

void tanks::right(){
    
    
    sp->setPositionX(sp->getPositionX()+sp->getContentSize().width/2);
    
    Size s = Director::getInstance()->getVisibleSize();
    
    Size sps = sp->getContentSize();

    
    if (sp->getPositionX() >= (s.width-sps.width/2 )) {
        
        sp->setPositionX(s.width-sps.width/2);
    }
    

    
    sp->setRotation(90);
    
}
