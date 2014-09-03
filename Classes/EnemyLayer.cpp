//
//  EnemyLayer.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "EnemyLayer.h"
#include "Enemy.h"
#include "BigTank.h"
#include "tanks.h"
#include "FasterTank.h"
#include "PopTank.h"
#include "GameScene.h"
#include "Map.h"

bool EnemyLayer::init(){
	if(!Layer::init()){
		return false;
	}

	PopTank * p_Tank = PopTank::create();
	addChild(p_Tank);

	tanks * main = tanks::getInstance();
	addChild(main);
    main->setRotation(en_Up);

    auto map = TMXTiledMap::create("mapNew.tmx");
    auto playerPosValueMap = map->getObjectGroup("object")->getObject("player");
    main->setPosition(Vec2(playerPosValueMap.at("x").asFloat(), playerPosValueMap.at("y").asFloat()));
    
	return true;
}

void EnemyLayer::onExit()
{
    Layer::onExit();
}

void EnemyLayer::createEnemy(){
	//在层中几个位置中随机生成坦克
}