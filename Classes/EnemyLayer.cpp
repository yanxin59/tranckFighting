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
bool EnemyLayer::init(){
	if(!Layer::init()){
		return false;
	}
	/*Enemy * e1 = Enemy::create();
	e1->setPosition(16*6,16*4);
	addChild(e1);
	Enemy * e2 = BigTank::create();
	e2->setPosition(16*16,16*4);
	addChild(e2);
	Enemy * e3 = FasterTank::create();
	e3->setPosition(16*36,16*4);
	addChild(e3);
	Enemy * e4 = Enemy::create();
	e4->setPosition(16*46,16*4);
	addChild(e4);*/
	PopTank * p_Tank = PopTank::create();
	addChild(p_Tank);

	tanks * main = tanks::getInstance();
	addChild(main);
	return true;
}
void EnemyLayer::createEnemy(){
	//在层中几个位置中随机生成坦克
}