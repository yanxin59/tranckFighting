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
    
    auto layerWin = Layer::create();
    this->addChild(layerWin);
    
    auto layerLose = Layer::create();
    this->addChild(layerLose);
    auto loseSp = Sprite::create("gamedone.png");
    layerLose->addChild(loseSp);
    loseSp->setPosition(Vec2(480,320));
    loseSp->setScale(4.0, 4.0);
    
    MenuItemImage * image = MenuItemImage::create("close.png","open.png",[=](Ref * sender){
        
        auto tSceneType = en_GameScene;
        
        NotificationCenter::getInstance()->postNotification("changeScene", reinterpret_cast<Ref *>(& tSceneType));
    });

        Size s = Director::getInstance()->getVisibleSize();
    Size sbutton = image->getContentSize();
    image->setPosition(Vec2(s.width-sbutton.width/2,sbutton.height/2));
    
    Menu * menu = Menu::create(image,NULL);
    menu->setPosition(Vec2(0,0));
    this->addChild(menu);
    

    return true;
}