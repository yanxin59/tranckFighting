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
#include "tanks.h"

using namespace CocosDenshion;

bool GameScene::init(){
	if (!Scene::init()){
		return false;
	}


	auto tPEnemyLayer = EnemyLayer::create();
	tPEnemyLayer->setAnchorPoint(Point::ZERO);
	tPEnemyLayer->setPosition(Point::ZERO);
	this->addChild(tPEnemyLayer, 0);

	auto tPControllerLayer = ControllerLayer::create();
    tPControllerLayer->setFuncTankMove(std::bind( (void (tanks::*)(const Rotation&))(&tanks::move), tanks::getInstance(), std::placeholders::_1) );
    this->addChild(tPControllerLayer, 4);
    
	auto tPBulletLayer = BulletLayer::create();
    tPBulletLayer->setTag(1);
	this->addChild(tPBulletLayer, 1);
    
    Maps * tPMap = Maps::create();
	tPMap->setName("map");
	this->addChild(tPMap, 3);
    
    auto tPScoreLayer = ScoreLayer::create();
    addChild(tPScoreLayer, 2);
    
    SimpleAudioEngine::getInstance()->playEffect("startSound.wav");
	
	return true;
}

BulletLayer* GameScene::getLayer(){
	return dynamic_cast<BulletLayer*>(this->getChildByTag(1));
}
Maps * GameScene::getMap(){
	return dynamic_cast<Maps*>(getChildByName("map"));
}
