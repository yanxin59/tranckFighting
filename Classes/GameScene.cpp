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
	Maps * map = Maps::create();
	map->setName("map");
	this->addChild(map);

	auto elayer = EnemyLayer::create();
	elayer->setAnchorPoint(Point::ZERO);
	elayer->setPosition(Point::ZERO);
	this->addChild(elayer);

	auto layer = ControllerLayer::create();
    this->addChild(layer);
    
	auto l = BulletLayer::create();
    l->setTag(1);
	this->addChild(l);
    
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
