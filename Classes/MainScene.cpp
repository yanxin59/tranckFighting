//
//  MainScene.cpp
//  tranckFighting
//
//  Created by 王紫叶 on 14-8-30.
//
//

#include "MainScene.h"
#include "GameScene.h"
#include <SimpleAudioEngine.h>
using namespace CocosDenshion;
bool MainScene::init(){
    
    if (!Scene::init()) {
        return false;
    }
    
    auto layer = Layer::create();
    
    this->addChild(layer);
    
    MenuItemImage * item = MenuItemImage::create("BattleCity.png","BattleCity.png",[=](Ref * sender){
        
        auto scene = GameScene::create();
        Director::getInstance()->replaceScene(scene);
        
        
    });
    item->setPosition(Vec2(480,320));
    
    Menu * menu = Menu::create(item,NULL);
    menu ->setPosition(Vec2(0,0));
    this->addChild(menu);
    
    auto act = JumpBy::create(3, Vec2(0,0), 50, 2);
    item->runAction(act);
    
    return true;
}