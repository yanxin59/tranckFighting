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
	Enemy * e1 = Enemy::create();
	e1->setPosition(32*6,32*3);
	addChild(e1);
	return true;
}
void EnemyLayer::createEnemy(){
	//在层中几个位置中随机生成坦克
}