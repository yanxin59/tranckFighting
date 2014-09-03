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
#include "ControllerLayer.h"
#include "SimpleAudioEngine.h"
#include "ScoreLayer.h"

using namespace CocosDenshion;

bool GameScene::init(){
	if (!Scene::init()){
		return false;
	}
	Maps * tPMap = Maps::create();
	tPMap->setName("map");
	this->addChild(tPMap);

	auto tPEnemyLayer = EnemyLayer::create();
	tPEnemyLayer->setAnchorPoint(Point::ZERO);
	tPEnemyLayer->setPosition(Point::ZERO);
	this->addChild(tPEnemyLayer);

	auto tPControllerLayer = ControllerLayer::create();
    this->addChild(tPControllerLayer);
    
	auto tPBulletLayer = BulletLayer::create();
    tPBulletLayer->setTag(1);
	this->addChild(tPBulletLayer);
    
    auto tPScoreLayer = ScoreLayer::create();
    addChild(tPScoreLayer);
    
    SimpleAudioEngine::getInstance()->playEffect("startSound.wav");
	
	return true;
}

BulletLayer* GameScene::getLayer(){
	return dynamic_cast<BulletLayer*>(this->getChildByTag(1));
}
Maps * GameScene::getMap(){
	return dynamic_cast<Maps*>(getChildByName("map"));
}
