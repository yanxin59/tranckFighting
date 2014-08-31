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
    
<<<<<<< HEAD
   auto sp =  tanks::getInstance();
    this->addChild(sp);
    
    
    
    MenuItemImage * item1 = MenuItemImage::create("tutorial_guide8.png","tutorial_guide18.png",[=](Ref * sender){
    
        sp->up();
        
    
    });
    
    MenuItemImage * item2 = MenuItemImage::create("tutorial_guide2.png","tutorial_guide12.png",[=](Ref * sender){
=======
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
    
    auto tControl = Sprite::create("control_bg.png");
    tControl->setPosition(Vec2(tControl->getContentSize().width/2,tControl->getContentSize().height/2));
    this->addChild(tControl,1);
    tControl->setOpacity(150);
    
    auto tHandle = Sprite::create("cen.png");
    tHandle->setPosition(Vec2(tControl->getContentSize().width/2,tControl->getContentSize().height/2));
    this->addChild(tHandle,1);
    tHandle->setOpacity(200);
    
    tanks * tank = tanks::getInstance();
    this->addChild(tank);
    
    auto listen = EventListenerTouchOneByOne::create();
    listen->onTouchBegan = [=]( Touch * t , Event * e){
        
<<<<<<< HEAD
        sp->right();
    
    });
    
    item1->setPosition(Vec2(200,300));
    item2->setPosition(Vec2(200,100));
    item3->setPosition(Vec2(100,200));
    item4->setPosition(Vec2(300,200));
    
    
    MenuItemImage * item = MenuItemImage::create("SodRollCap.png","SodRollCap.png",[=](Ref * sender){
    
=======
        if (tHandle->getBoundingBox().containsPoint(Director::getInstance()->convertToGL(t->getLocationInView()))) {
            
            return true;
        }
        else{
            
            return false;
        }
    };
    listen->onTouchMoved = [ = ](Touch * t , Event * e){
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
        
        auto p1 = Director::getInstance()->convertToGL( t->getLocationInView());
        auto p2 = Director::getInstance()->convertToGL(t ->getPreviousLocationInView());
        auto p3 = p1 - p2;
        if(!tControl->getBoundingBox().containsPoint(tHandle->getPosition())){
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
    
<<<<<<< HEAD
    item->setPosition(Vec2(800,150));
    
    Menu * menu = Menu::create(item,item1,item2,item3,item4,NULL);
    menu->setPosition(Vec2(0,0));
    this->addChild(menu);
=======
    item->setPosition(Vec2(Director::getInstance()->getVisibleSize().width - (tControl->getContentSize().width/2),tControl->getContentSize().height/2));
 
    auto menu = Menu::create(item,NULL);
    this->addChild(menu,1);
    menu->setPosition(Vec2(0,0));
    
    auto tControlFireButton = Sprite::create("control_bg.png");
    tControlFireButton->setPosition(Vec2(Director::getInstance()->getVisibleSize().width - (tControl->getContentSize().width/2),tControl->getContentSize().height/2));
    this->addChild(tControlFireButton);
    scheduleUpdate();
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
    
    
    
    
    return true;
}
void ControllerLayer::update(float t){
    
    if (_iLeft == 1) {
        tanks::getInstance()->left();
    }
    if (_iLeft == 2) {
        tanks::getInstance()->right();
    }
    if (_iUp == 1) {
        tanks::getInstance()->up();
    }
    if (_iUp == 2) {
        tanks::getInstance()->down();
    }
}
