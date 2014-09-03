//
//  stopScene.cpp
//  tranckFighting
//
//  Created by 王紫叶 on 14-8-30.
//
//

#include "stopScene.h"
#include "config.h"

bool stopScene::init(){
    
    if (!Scene::init()) {
        return false;
    }
    
    auto layer = Layer::create();
    this->addChild(layer);
    
    
    MenuItemImage * item = MenuItemImage::create("gamedone.png","gamedone.png",[=](Ref * sender){
        auto tSceneType = en_GameScene;
        NotificationCenter::getInstance()->postNotification("changeScene", reinterpret_cast<Ref *>(&tSceneType));
    });
    
    Menu * menu = Menu::create(item, nullptr);
    layer->addChild(menu);
    
    return true;
}