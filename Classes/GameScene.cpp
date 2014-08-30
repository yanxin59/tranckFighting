//
//  GameScene.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "GameScene.h"
#include "ControllerLayer.h"
bool GameScene::init(){
    
    if (!Scene::init()) {
        return false;
    }
    
    auto layer = ControllerLayer::create();
    
    this->addChild(layer);
    
    
    
    
    return true;
}