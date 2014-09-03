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
#include "tanks.h"

bool BulletLayer::init(){
	if (!Layer::init()){
		return false;
	}
	this->scheduleUpdate();
	return true;
}

//将子弹贴在层上的函数
void BulletLayer::addBullet(Bullet* b)
{
	this->addChild(b);
}

void BulletLayer::update(float t){
	auto v = BulletsBox::getInstance()->getBulletsVector();
	auto ev = EnemyVector::getInstence()->getEV();
	auto gamescene = dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
	auto map = gamescene->getMap();
	cocos2d::TMXLayer *bg = map->m_bg;
	cocos2d::TMXLayer *bird = map->m_bird;
	cocos2d::TMXLayer *iron = map->m_iron;
	auto tan = tanks::getInstance();
	
	static int a = 0;
	for (auto it1 = v.begin(); it1 != v.end();){
		auto bpoint = (*it1)->getPosition();
		auto bsize = (*it1)->getBulletSize();
		auto maphigth = bg->getLayerSize().height;
		auto px1 = 0;
		auto px2 = 0;
		auto px3 = 0;

		auto py1 = 0;
		auto py2 = 0;
		auto py3 = 0;
		auto r = (*it1)->getRotation();
		static int a = 0;
		static int b = 0;
		static int c = 0;
		if (r == 0.0f){
			py1 = maphigth - (bpoint.y + bsize.height)/16;
			px1	= bpoint.x/16;
			px2 = (bpoint.x + bsize.width/2)/16;
			px3 = (bpoint.x - bsize.width/2)/16;
			if(py1 < 0.0f) py1 = 0.0f;
			if(px2 > 59.0f) px2 = 59.0f;
			if(px3 < 0.0f) px3 = 0.0f;
			if (bg->getTileGIDAt(Vec2(px1,py1))){
				bg->removeTileAt(Vec2(px1,py1));
				a = 1;
			}
			if (bg->getTileGIDAt(Vec2(px2,py1))){
				bg->removeTileAt(Vec2(px2,py1));
				a = 1;
			}
			if (bg->getTileGIDAt(Vec2(px3,py1))){
				bg->removeTileAt(Vec2(px3,py1));
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px1,py1))){
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px2,py1))){
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px3,py1))){
				a = 1;
			}
			if(a == 1){
				a = 0;
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
				continue;
			}
			if (bird->getTileGIDAt(Vec2(px1,py1))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
				continue;
				//游戏结束
			}
			if (bird->getTileGIDAt(Vec2(px2,py1))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
				continue;
				//游戏结束
			}
			if (bird->getTileGIDAt(Vec2(px3,py1))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
				continue;
				//游戏结束
			}
		}else if (r == 90.0f){
			px1 = (bpoint.x + bsize.width/2)/16;
			py1 = maphigth - bpoint.y/16;
			py2 = maphigth - (bpoint.y + bsize.width/2)/16;
			py3 = maphigth - (bpoint.y - bsize.width/2)/16;
			if(px1 > 59.0f) px1 = 59.0f;
			if(py2 > 39.0f) py2 = 39.0f;
			if(py3 < 0.0f) py3 = 0.0f;
			if (bg->getTileGIDAt(Vec2(px1,py1))){
				bg->removeTileAt(Vec2(px1,py1));
				a = 1;
			}
			if (bg->getTileGIDAt(Vec2(px1,py2))){
				bg->removeTileAt(Vec2(px1,py2));
				a = 1;
			}
			if (bg->getTileGIDAt(Vec2(px1,py3))){
				bg->removeTileAt(Vec2(px1,py3));
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px1,py1))){
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px1,py2))){
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px1,py3))){
				a = 1;
			}
			if(a == 1){
				a = 0;
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
				continue;
			}
			if (bird->getTileGIDAt(Vec2(px1,py1)) || bird->getTileGIDAt(Vec2(px1,py2)) || bird->getTileGIDAt(Vec2(px1,py3))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
                log("game over");
				continue;
				//游戏结束
			}
        }else if (r == 180.0f){
			py1 = maphigth - (bpoint.y - bsize.height)/16;
			px1	= bpoint.x/16;
			px2 = (bpoint.x + bsize.width/2)/16;
			px3 = (bpoint.x - bsize.width/2)/16;
			if(py1 > 39.0f) py1 = 39.0f;
			if(px2 > 59.0f) px2 = 59.0f;
			if(px3 < 0.0f) px3 = 0.0f;
			if (bg->getTileGIDAt(Vec2(px1,py1))){
				bg->removeTileAt(Vec2(px1,py1));
				a = 1;
			}
			if (bg->getTileGIDAt(Vec2(px2,py1))){
				bg->removeTileAt(Vec2(px2,py1));
				a = 1;
			}
			if (bg->getTileGIDAt(Vec2(px3,py1))){
				bg->removeTileAt(Vec2(px3,py1));
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px1,py1))){
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px2,py1))){
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px3,py1))){
				a = 1;
			}
			if(a == 1){
				a = 0;
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
				continue;
			}
			if (bird->getTileGIDAt(Vec2(px1,py1)) || bird->getTileGIDAt(Vec2(px3,py1)) || bird->getTileGIDAt(Vec2(px2,py1))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
				continue;
				//游戏结束
			}
		}else if (r == 270.0f){
			px1 = (bpoint.x - bsize.width/2)/16;
			py1 = maphigth - bpoint.y/16;
			py2 = maphigth - (bpoint.y + bsize.width/2)/16;
			py3 = maphigth - (bpoint.y - bsize.width/2)/16;
			if(px1 < 0.0f) px1 = 0.0f;
			if(py2 > 39.0f) py2 = 39.0f;
			if(py3 < 0.0f) py3 = 0.0f;
			if (bg->getTileGIDAt(Vec2(px1,py1))){
				bg->removeTileAt(Vec2(px1,py1));
				a = 1;
			}
			if (bg->getTileGIDAt(Vec2(px1,py2))){
				bg->removeTileAt(Vec2(px1,py2));
				a = 1;
			}
			if (bg->getTileGIDAt(Vec2(px1,py3))){
				bg->removeTileAt(Vec2(px1,py3));
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px1,py1))){
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px1,py2))){
				a = 1;
			}
			if (iron->getTileGIDAt(Vec2(px1,py3))){
				a = 1;
			}
			if(a == 1){
				a = 0;
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
				continue;
			}
			if (bird->getTileGIDAt(Vec2(px1,py1)) || bird->getTileGIDAt(Vec2(px1,py2)) || bird->getTileGIDAt(Vec2(px1,py3))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				it1 ++;
                log("game over!");
				continue;
				//游戏结束
			}
        }
		if (!(*it1) || !tan){
			return;
		}
		if ((*it1)->getEntityType() == 2){
			if (Detections::getInstance()->BulletBullet((*it1))){
				log("zhutan sile");
			}
		}
		for (auto it2 = v.begin(); it2 != it1;){
			if (!(*it2)){
				return;
			}
			if ((*it1) == (*it2)){
				it2 ++;
				continue;
			}	
			if (Detections::getInstance()->BulletBullet((*it1), (*it2))){
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
				BulletsBox::getInstance()->deleteBullet((*it2));
				(*it2)->doDead();
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
			if (!(*it3)){
				return;
			}
			if ((*it1)->getEntityType() == 2){
				it3 ++;
				continue;
			}
			if (Detections::getInstance()->BulletBullet((*it1), (*it3))){
				(*it3)->hurt((*it1)->getAttack());
				BulletsBox::getInstance()->deleteBullet((*it1));
				(*it1)->doDead();
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