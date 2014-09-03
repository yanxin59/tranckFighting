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
#include "EnemyVector.h"

bool EnemyLayer::init(){
	if(!Layer::init()){
		return false;
	}

	PopTank * p_Tank = PopTank::create();
	addChild(p_Tank);

	tanks * main = tanks::getInstance();
    main->reset();
	addChild(main);
    
	return true;
}

void EnemyLayer::onExit()
{
    Layer::onExit();
    EnemyVector::getInstence()->clearEnemy();
}

void EnemyLayer::createEnemy(){
	//在层中几个位置中随机生成坦克
}