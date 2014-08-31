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
    
    setPositionY(getPositionY()+sp->getContentSize().height/2);
    
    Size s = Director::getInstance()->getVisibleSize();
    
    Size sps = sp->getContentSize();
    
    
    if (getPositionY() >= (s.height - sps.height/2)) {
        
        setPositionY(s.height - sps.height/2);
        
    }
    sp->stopAllActions();
    
    playupAnimation();
    
}

void tanks::down(){
    
    setPositionY(getPositionY()-sp->getContentSize().height/2);
    
    Size sps = sp->getContentSize();
    
    if (getPositionY() < sps.height/2) {
        
        setPositionY(sps.height/2);
    }

   sp->stopAllActions();
    
    playdownAnimation();
    
}

void tanks::left(){
    
    
    setPositionX(getPositionX()-sp->getContentSize().width/2);
    
       Size sps = sp->getContentSize();
    
    if (getPositionX() < sps.width/2) {
        
        setPositionX(sps.width/2);
    }

    sp->stopAllActions();
    
    playleftAnimation();
    
}

void tanks::right(){
    
    
    setPositionX(getPositionX()+sp->getContentSize().width/2);
    
    Size s = Director::getInstance()->getVisibleSize();
    
    Size sps = sp->getContentSize();

    
    if (getPositionX() >= (s.width-sps.width/2 )) {
        
        setPositionX(s.width-sps.width/2);
    }

    sp->stopAllActions();
    
    playrightAnimation();
    
}


void tanks::playdownAnimation(){
    
    auto anim = Animation::create();
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(0,0,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(64,0,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(128,0,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(192,0,64,96)));
                         
    anim->setDelayPerUnit(0.2);
                         
    anim->setLoops(-1);
                         
    sp->runAction(Animate::create(anim));
                         
    
}

void tanks::playupAnimation(){
    
    
    
    auto anim = Animation::create();
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(0,288,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(64,288,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(128,288,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(192,288,64,96)));
    
    anim->setDelayPerUnit(0.2);
    
    anim->setLoops(-1);
    
    sp->runAction(Animate::create(anim));
    
    
}

void tanks::playleftAnimation(){
    
    
    
    auto anim = Animation::create();
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(0,96,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(64,96,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(128,96,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(192,96,64,96)));
    
    anim->setDelayPerUnit(0.2);
    
    anim->setLoops(-1);
    
    sp->runAction(Animate::create(anim));
    
    
}

void tanks::playrightAnimation(){
    
    
    
    auto anim = Animation::create();
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(0,192,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(64,192,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(128,192,64,96)));
    
    anim->addSpriteFrame(SpriteFrame::create("monster_59.png",Rect(192,192,64,96)));
    
    anim->setDelayPerUnit(0.2);
    
    anim->setLoops(-1);
    
    sp->runAction(Animate::create(anim));
    
    
}



