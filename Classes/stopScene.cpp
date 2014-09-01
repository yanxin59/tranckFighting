//
//  stopScene.cpp
//  tranckFighting
//
//  Created by 王紫叶 on 14-8-30.
//
//

#include "stopScene.h"
#include "GameScene.h"
bool stopScene::init(){
    
    if (!Scene::init()) {
        return false;
    }
    
    auto layer = Layer::create();
    this->addChild(layer);
    
    
    MenuItemImage * item = MenuItemImage::create("gamedone.png","gamedone.png",[=](Ref * sender){
    
        auto scene = GameScene::create();
        
        Director::getInstance()->replaceScene(scene);
        
    });
    item->setPosition(Vec2(480,320));
    
    Menu * menu = Menu::create();
    menu->setPosition(Vec2(0,0));
    this->addChild(menu);
    
    auto act = JumpBy::create(3, Vec2(0,0), 100, 10);
    layer->runAction(act);
    
    return true;
}