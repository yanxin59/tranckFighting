//
//  EnemyLayer.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "EnemyLayer.h"
#include "Enemy.h"
bool EnemyLayer::init(){
	if(!Layer::init()){
		return false;
	}
	Enemy * enemy = Enemy::create();
	enemy->setPosition(100,100);
	addChild(enemy);
	log("%f,%f,%f,%f",enemy->getRect()->origin.x,enemy->getRect()->origin.y,enemy->getRect()->size.width,enemy->getRect()->size.height);
	return true;
}
void EnemyLayer::createEnemy(){
	//在层中几个位置中随机生成坦克
}