//
//  GameScene.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "GameScene.h"
<<<<<<< HEAD
#include "EnemyLayer.h"
#include "BulletLayer.h"
#include "Map.h"
=======
#include "ControllerLayer.h"
#include "EnemyLayer.h"
#include "BulletLayer.h"


>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
bool GameScene::init(){
	if (!Scene::init()){
		return false;
	}
<<<<<<< HEAD
	Maps * map = Maps::create();
	map->setName("map");
	this->addChild(map);

	this->addChild(EnemyLayer::create());

	/*auto l = BulletLayer::create();
=======
	auto layer = ControllerLayer::create();
    	this->addChild(layer);
    	
	this->addChild(EnemyLayer::create());
	auto l = BulletLayer::create();
	
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
	l->setTag(1);
	this->addChild(l);*/
	
	
	return true;
}

BulletLayer* GameScene::getLayer(){
	return dynamic_cast<BulletLayer*>(this->getChildByTag(1));
}
<<<<<<< HEAD
Maps * GameScene::getMap(){
	return (Maps *)(getChildByName("map"));
}
=======
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
