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
	Enemy * enemy1 = Enemy::create();
	enemy1->setPosition(100,100);
	addChild(enemy1);
	Enemy * enemy2 = Enemy::create();
	enemy2->setPosition(200,200);
	addChild(enemy2);
	Enemy * enemy3 = Enemy::create();
	enemy3->setPosition(300,200);
	addChild(enemy3);
	Enemy * enemy4 = Enemy::create();
	enemy4->setPosition(300,300);
	addChild(enemy4);
	Enemy * enemy5 = Enemy::create();
	enemy5->setPosition(400,400);
	addChild(enemy5);
	return true;
}
void EnemyLayer::createEnemy(){
	//在层中几个位置中随机生成坦克
}