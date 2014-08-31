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
	
	
	this->scheduleUpdate();
	return true;
}

//将子弹贴在层上的函数
void BulletLayer::addBullet(Bullet* b){
	this->addChild(b);
}

void BulletLayer::update(float t){
	auto v = BulletsBox::getInstance()->getBulletsVector();
	auto ev = EnemyVector::getInstence()->getEV();
	log("%d", v.size());
	static int a = 0;
	static int b = 0;
	for (auto it1 = v.begin(); it1 != v.end();){
		for (auto it2 = v.begin(); it2 != it1;){
			if (!(*it1) || !(*it2)){
				return;
			}
			if ((*it1) == (*it2)){
				it2 ++;
				continue;
			}	
			if (Detections::getInstance()->BulletBullet((*it1), (*it2))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->deleteBullet();
				BulletsBox::getInstance()->deleteBullet((*it2));
				(*it2)->deleteBullet();
				a = 1;
				break;
			}
			it2 ++;
		}
		if (a ==1){
			a = 0;
			it1 ++;
			continue;
		}
		for (auto it3 = ev.begin(); it3 != ev.end();){
			if (!(*it1) || !(*it3)){
				return;
			}
			if ((*it1)->getTeam() == 2){
				it3 ++;
				continue;
			}
			if (Detections::getInstance()->BulletBullet((*it1), (*it3))){
				(*it3)->hurt((*it1)->getAttack());
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->deleteBullet();
				b = 1;
				break;;
			}
			it3 ++;
		}
		if (b == 1){
			b = 0;
			it1 ++;
			continue;
		}
		it1 ++;
	}
}