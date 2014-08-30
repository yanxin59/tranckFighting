//
//  BulletLayer.cpp
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#include "BulletLayer.h"
#include "Bullet.h"
#include "Detections.h"
#include "BulletsBox.h"

bool BulletLayer::init(){
	if (!Layer::init()){
		return false;
	}
	//auto b = Bullet::create(0, Vec2(480, 320));
	//addBullet(b);
	auto b1 = Bullet::create(90, Vec2(180, 220), 1);
	b1->setName("1");
	addBullet(b1);
	//auto b2 = Bullet::create(180, Vec2(480, 320));
	//addBullet(b2);
	auto b3 = Bullet::create(270, Vec2(580, 220), 1);
	addBullet(b3);
	b3->setName("3");
	//this->schedule(schedule_selector(BulletLayer::update, this), 1);
	this->scheduleUpdate();
	return true;
}

//将子弹贴在层上的函数
void BulletLayer::addBullet(Bullet* b){
	this->addChild(b);
}

void BulletLayer::update(float t){
	auto b1 = dynamic_cast<Bullet*>(this->getChildByName("1"));
	auto b3 = dynamic_cast<Bullet*>(this->getChildByName("3"));
	if (!b1 || !b3){
		return;
	}
	if (Detections::getInstance()->BulletBullet(b1, b3)){
		BulletsBox::getInstance()->deleteBullet(b1);
		b1->deleteBullet();
		BulletsBox::getInstance()->deleteBullet(b3);
		b3->deleteBullet();
	}
}