#include "PopTank.h"
#include "EnemyVector.h"
#include "Enemy.h"
#include "BigTank.h"
#include "FasterTank.h"
#include "EnemyLayer.h"
bool PopTank::init(){
	if(!Node::init()){
		return false;
	}
	auto map = TMXTiledMap::create("mapNew.tmx");
	auto playerPosValueMap1 = map->getObjectGroup("object")->getObject("Enemy1");
	//auto playerPosValueMap2 = map->getObjectGroup("object")->getObject("Enemy2");
	//auto playerPosValueMap3 = map->getObjectGroup("object")->getObject("Enemy3");
	addPoint(Vec2(playerPosValueMap1.at("x").asFloat(), playerPosValueMap1.at("y").asFloat()));
	//addPoint(Vec2(playerPosValueMap2.at("x").asFloat(), playerPosValueMap2.at("y").asFloat()));
	//addPoint(Vec2(playerPosValueMap3.at("x").asFloat(), playerPosValueMap3.at("y").asFloat()));
	//this->addPoint(Vec2(16*6,16*4));
	this->addPoint(Vec2(16*16,16*38));
	this->addPoint(Vec2(16*36,16*38));
    //this->addPoint(Vec2(16*46,16*4));
	count = 20;
	schedule(schedule_selector(PopTank::mydate),1.5);
	return true;
}
void PopTank::addPoint(Vec2 vec){
	point.push_back(vec);
}
void PopTank::mydate(float t){
	auto ev = EnemyVector::getInstence();
	auto eve = ev->getEV();
	int s_k = rand()%10;
	int s_p = rand()%(point.size());

	if(count > 0 && eve.size() < 4){
		Enemy * p_enemy;

	auto center = __NotificationCenter::getInstance();
		if(count == 20){
			int k = 23;
			Ref * p_score = (Ref *)(&k);
			center->postNotification("changeEnemyCount",p_score);
		}else{
			center->postNotification("changeEnemyCount",NULL);
		}
		if(s_k < 2){
			p_enemy = BigTank::create();
		}else if(s_k > 2 && s_k < 5){
			p_enemy = FasterTank::create();
		}else{
			p_enemy = Enemy::create();
		}
		p_enemy->setPosition(point.at(s_p));
		EnemyLayer * elayer = (EnemyLayer *)this->getParent();
		elayer->addChild(p_enemy);
		count--;
	}
}

