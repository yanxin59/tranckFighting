//
//  BulletLayer.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "BulletLayer.h"
#include "Bullet.h"

bool BulletLayer::init(){
	if (!Layer::init()){
		return false;
	}
	auto b = Bullet::create(0, Vec2(480, 320));
	addBullet(b);
	auto b1 = Bullet::create(90, Vec2(480, 320));
	addBullet(b1);
	auto b2 = Bullet::create(180, Vec2(480, 320));
	addBullet(b2);
	auto b3 = Bullet::create(270, Vec2(480, 320));
	addBullet(b3);
	return true;
}

//将子弹贴在层上的函数
void BulletLayer::addBullet(Bullet* b){
	this->addChild(b);
}