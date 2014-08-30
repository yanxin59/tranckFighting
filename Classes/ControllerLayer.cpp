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
    
    item1->setPosition(Vec2(200,300));
    item2->setPosition(Vec2(200,100));
    item3->setPosition(Vec2(100,200));
    item4->setPosition(Vec2(300,200));
    
    
    MenuItemImage * item = MenuItemImage::create("SodRollCap.png","SodRollCap.png",[=](Ref * sender){
    
        
        sp->mineFireEnemy();
        
            
    
    });
    
    item->setPosition(Vec2(800,150));
    
    Menu * menu = Menu::create(item,item1,item2,item3,item4,NULL);
    menu->setPosition(Vec2(0,0));
    this->addChild(menu);
    
    
    
    
    return true;
}

