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
#include "EnemyVector.h"

bool BulletLayer::init(){
	if (!Layer::init()){
		return false;
	}
	//auto b = Bullet::create(0, Vec2(480, 320));
	//addBullet(b);
	//auto b1 = Bullet::create(90, Vec2(180, 220), 1);
	//b1->setName("1");
	//addBullet(b1);
	//auto b2 = Bullet::create(180, Vec2(480, 320));
	//addBullet(b2);
	//auto b3 = Bullet::create(270, Vec2(580, 220), 1);
	//addBullet(b3);
	//b3->setName("3");
	//this->schedule(schedule_selector(BulletLayer::update, this), 1);
	this->scheduleUpdate();
	return true;
}

//将子弹贴在层上的函数
void BulletLayer::addBullet(Bullet* b){
	this->addChild(b);
}

void BulletLayer::update(float t){
	auto v = BulletsBox::getInstance()->getBulletsVector();
	static int a = 0;
	for (auto it1 = v.begin(); it1 != v.end();){
		for (auto it2 = v.begin(); it2 != it1;){
			if (!(*it1) || !(*it2)){
				return;
			}
			if ((*it1) == (*it2)){
				break;
			}	
			if (Detections::getInstance()->BulletBullet((*it1), (*it2))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->deleteBullet();
				BulletsBox::getInstance()->deleteBullet((*it2));
				(*it2)->deleteBullet();
				a = 1;
				return;
			}
			it2 ++;
		}
		it1 ++;
	}
	auto ev = EnemyVector::getInstence()->getEV();
	static int b = 0;
	for (auto it1 = v.begin(); it1 != v.end();){
		for (auto it2 = ev.begin(); it2 != ev.end();){
			if (!(*it1) || !(*it2)){
				return;
			}
			if (Detections::getInstance()->BulletBullet((*it1), (*it2))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->deleteBullet();
				(*it2)->die();
				a = 1;
				return;
			}
			it2 ++;
		}
		it1 ++;
	}
}