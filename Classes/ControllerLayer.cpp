//
//  ControllerLayer.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "ControllerLayer.h"
#include "tanks.h"

bool ControllerLayer::init(){
    
    if (!Layer::init()) {
        
        return false;
    }
    
    _iLeft = 0;
    _iUp = 0;
    auto tControl = Sprite::create("control_bg.png");
    tControl->setPosition(Vec2(tControl->getContentSize().width/2,tControl->getContentSize().height/2));
    this->addChild(tControl,1);
    tControl->setOpacity(150);
    
    auto tHandle = Sprite::create("cen.png");
    tHandle->setPosition(Vec2(tControl->getContentSize().width/2,tControl->getContentSize().height/2));
    this->addChild(tHandle,1);
    tHandle->setOpacity(200);
    
    tanks * tank = tanks::getInstance();
    
    
    auto listen = EventListenerTouchOneByOne::create();
    listen->onTouchBegan = [=]( Touch * t , Event * e){
        
        if (tHandle->getBoundingBox().containsPoint(Director::getInstance()->convertToGL(t->getLocationInView()))) {
            
            return true;
        }
        else{
            
            return false;
        }
    };
    listen->onTouchMoved = [ = ](Touch * t , Event * e){
        
        auto p1 = Director::getInstance()->convertToGL( t->getLocationInView());
        auto p2 = Director::getInstance()->convertToGL(t ->getPreviousLocationInView());
        auto p3 = p1 - p2;
        if(!tControl->getBoundingBox().containsPoint(tHandle->getPosition()) || !tControl->getBoundingBox().containsPoint(p1)){
            tHandle->setPosition(Vec2(tControl->getContentSize().width/2,tControl->getContentSize().height/2));
            _iLeft = 0;
            _iUp = 0;
            return;
        }
        tHandle->setPosition(tHandle->getPosition() + p3);
 
        auto sy = tHandle->getPositionY() - tControl->getPositionY();
        auto sx = tHandle->getPositionX() - tControl->getPositionX();
        auto x1 = tHandle->getPositionX();
        auto x2 = tControl->getPositionX();
        auto y1 = tHandle->getPositionY();
        auto y2 = tControl->getPositionY();
        
        if (x1 > x2) {
            
            if (y1 > y2) {
                
                if (fabsf(sy) > fabsf(sx)) {
                    
                    _iUp = 1;
                    _iLeft = 0;
                }else {
                    
                    _iLeft = 2;
                    _iUp = 0;
                }
                
            }else{
                
                if (fabsf(sy) > fabsf(sx)) {
                    
                    _iUp = 2;
                    _iLeft= 0;
                }else {
                    
                     _iLeft = 2;
                     _iUp = 0;
                }
            }
            
        }else{
            
            if (y1 > y2) {
                
                if (fabsf(sy) > fabsf(sx)) {

                    _iUp = 1;
                     _iLeft = 0;
                    
                }else {
                    
                    _iLeft = 1;
                     _iUp = 0;
                }
                
            }else{
                
                if (fabsf(sy) > fabsf(sx)) {
                    
                    _iUp = 2;
                     _iLeft = 0;
                }else {
                    
                    _iLeft = 1;
                     _iUp = 0;
                }
            }
        }
    };
    listen->onTouchEnded = [=](Touch * t , Event * e) {
        
        tHandle->setPosition(Vec2(tControl->getContentSize().width/2,tControl->getContentSize().height/2));
        _iLeft = 0;
        _iUp = 0;
    };
    auto dis = Director::getInstance()->getEventDispatcher();
    dis->addEventListenerWithSceneGraphPriority(listen, this);

    MenuItemImage * item = MenuItemImage::create("fire_button_default.png","fire_button_press.png",[=](Ref * sender){
 
        tank->addFire();
    });
    item->setScale(0.8);
    item->setOpacity(50);
    item->setPosition(Vec2(Director::getInstance()->getVisibleSize().width - (tControl->getContentSize().width/2),tControl->getContentSize().height/2));

 
    auto menu = Menu::create(item,NULL);
    this->addChild(menu,1);
    menu->setPosition(Vec2(0,0));
    
    scheduleUpdate();
    
    return true;
}
void ControllerLayer::update(float t){
    
    
    if (_iLeft == 1) {
        tanks::getInstance()->move(en_Left);
    }
    if (_iLeft == 2) {
        tanks::getInstance()->move(en_Right);
    }
    if (_iUp == 1) {
        tanks::getInstance()->move(en_Up);
    }
    if (_iUp == 2) {
        tanks::getInstance()->move(en_Down);
    }
//    tanks::getInstance()->move(tRotation);
}
