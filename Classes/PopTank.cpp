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
	addPoint(Vec2(playerPosValueMap1.at("x").asFloat(), playerPosValueMap1.at("y").asFloat()));
	
	this->addPoint(Vec2(16*16,16*38));
	this->addPoint(Vec2(16*36,16*38));
	this->addPoint(Vec2(16*9,16*7));
	this->addPoint(Vec2(52*16,16*20));
    
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

		if(count == 20){
			auto center = __NotificationCenter::getInstance();
			int k = 20;
			Ref * p_count = (Ref *)(&k);
			center->postNotification("changeEnemyCount",p_count);
		}

		Enemy * p_enemy;
		
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
