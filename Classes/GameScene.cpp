//
//  GameScene.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "GameScene.h"
<<<<<<< HEAD
#include "ControllerLayer.h"
bool GameScene::init(){
    
    if (!Scene::init()) {
        return false;
    }
    
    auto layer = ControllerLayer::create();
    
    this->addChild(layer);
    
    
    
    
    return true;
=======
#include "EnemyLayer.h"
#include "BulletLayer.h"

bool GameScene::init(){
	if (!Scene::init()){
		return false;
	}
	this->addChild(EnemyLayer::create());
	auto l = BulletLayer::create();
	l->setTag(1);
	this->addChild(l);
	return true;
}

BulletLayer* GameScene::getLayer(){
	return dynamic_cast<BulletLayer*>(this->getChildByTag(1));
>>>>>>> c4bbd9cd6e5e193394b45530f9f4da713d3f46c9
}