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
    
   auto sp =  tanks::getInstance();
    
   sp->setPosition(Vec2(480,320));
    
   this->addChild(sp);
    
    
    
    MenuItemImage * item1 = MenuItemImage::create("tutorial_guide8.png","tutorial_guide18.png",[=](Ref * sender){
    
        sp->up();
        
    
    });
    
    MenuItemImage * item2 = MenuItemImage::create("tutorial_guide2.png","tutorial_guide12.png",[=](Ref * sender){
    
        sp->down();
    
    });
    
    MenuItemImage * item3 = MenuItemImage::create("tutorial_guide4.png","tutorial_guide14.png",[=](Ref * sender){
        
        sp->left();
    
    
    });
    
    MenuItemImage * item4 = MenuItemImage::create("tutorial_guide6.png","tutorial_guide16.png",[=](Ref * sender){
        
        sp->right();
    
    });
    
    item1->setPosition(Vec2(150,250));
    item2->setPosition(Vec2(150,50));
    item3->setPosition(Vec2(50,150));
    item4->setPosition(Vec2(250,150));
    
    
    MenuItemImage * item = MenuItemImage::create("fire_button_default.png","fire_button_press.png",[=](Ref * sender){
    
        
        sp->mineFireEnemy();
        
            
    
    });
    
    auto sprite = Sprite::create("control_bg.png");
    
    this->addChild(sprite);
    
    sprite->setPosition(Vec2(850,100));
    
    item->setPosition(Vec2(850,100));
    
    Menu * menu = Menu::create(item,item1,item2,item3,item4,NULL);
    
    menu->setPosition(Vec2(0,0));
    
    this->addChild(menu);
    
    return true;
}

