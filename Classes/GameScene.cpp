//
//  GameScene.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "GameScene.h"
#include "EnemyLayer.h"
#include "BulletLayer.h"
#include "Map.h"
bool GameScene::init(){
	if (!Scene::init()){
		return false;
	}
	Maps * map = Maps::create();
	map->setName("map");
	this->addChild(map);

	this->addChild(EnemyLayer::create());

	/*auto l = BulletLayer::create();
	l->setTag(1);
	this->addChild(l);*/
	
	
	return true;
}

BulletLayer* GameScene::getLayer(){
	return dynamic_cast<BulletLayer*>(this->getChildByTag(1));
}
Maps * GameScene::getMap(){
	return (Maps *)(getChildByName("map"));
}