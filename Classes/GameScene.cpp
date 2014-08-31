//
//  GameScene.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "GameScene.h"
#include "ControllerLayer.h"
#include "EnemyLayer.h"
#include "BulletLayer.h"


bool GameScene::init(){
	if (!Scene::init()){
		return false;
	}
	auto layer = ControllerLayer::create();
    	this->addChild(layer);
    	
	this->addChild(EnemyLayer::create());
	auto l = BulletLayer::create();
	
	l->setTag(1);
	this->addChild(l);
	return true;
}

BulletLayer* GameScene::getLayer(){
	return dynamic_cast<BulletLayer*>(this->getChildByTag(1));
}
