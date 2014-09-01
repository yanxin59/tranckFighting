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
#include "Map.h"
#include "GameScene.h"

bool BulletLayer::init(){
	if (!Layer::init()){
		return false;
	}
	this->scheduleUpdate();
	return true;
}

//���ӵ����ڲ��ϵĺ���
void BulletLayer::addBullet(Bullet* b){
	this->addChild(b);
}

void BulletLayer::update(float t){
	auto v = BulletsBox::getInstance()->getBulletsVector();
	auto ev = EnemyVector::getInstence()->getEV();
	auto gamescene = dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
	auto map = gamescene->getMap();
	
	
	//log("%d", v.size());
	static int a = 0;
	static int b = 0;
	float x = 0;
	float y = 0;
	for (auto it1 = v.begin(); it1 != v.end();){
		auto bsize = (*it1)->getSp()->getContentSize();
		auto bpoint = (*it1)->getPosition();
		log("%.2f %.2f", bpoint.x, bpoint.y);
		switch ((int)((*it1)->getSp()->getRotation())){
		case 0:x = bpoint.x, y = bpoint.y + bsize.height;
		log("itp  {%.2f, %.2f}", bpoint.x, bpoint.y);
		log("{%.2f, %.2f}", x, y);break;
		case 90:x = bpoint.x + bsize.width, y = bpoint.y;
		log("itp  {%.2f, %.2f}", bpoint.x, bpoint.y);
		log("{%.2f, %.2f}", x, y);break;
		case 180:x = bpoint.x, y = bpoint.y - bsize.height;
		log("itp  {%.2f, %.2f}", bpoint.x, bpoint.y);
		log("{%.2f, %.2f}", x, y);break;
		case 270:x = bpoint.x - bsize.width, y = bpoint.y;
		log("itp  {%.2f, %.2f}", bpoint.x, bpoint.y);
		log("{%.2f, %.2f}", x, y);break;
		default:
		break;
		}
		x = x / 16;
		y = 40 - y / 16;
		if (x > 59){
		x = 59;
		}
		if (y > 39){
		y = 39;
		}
		if (x < 0){
		x = 0;
		}
		if (y < 0){
		y = 0;
		}
		//(*it1)->stopAllActions();

		if (map->m_bg->getTileGIDAt(Vec2(x, y))){
		BulletsBox::getInstance()->deleteBullet((*it1));
		(*it1)->deleteBullet();
		it1 ++;
		continue;

		}
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