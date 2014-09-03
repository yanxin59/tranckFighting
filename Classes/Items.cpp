#include "Items.h"
#include "tanks.h"
#include "EnemyVector.h"
#include "GameScene.h"
#include "BulletLayer.h"

bool Items::init(){
	if (!Node::init()){
		return false;
	}
	auto i = rand()%3 + 1;
	const char* filename;
	switch (i)
	{
	case 1:filename = "bomb.png";itemsstate = 1;break;
	case 2:filename = "star.png";itemsstate = 2;break;
	case 3:filename = "timer.png";itemsstate = 3;break;
	default:
		break;
	}
	_pSprite = Sprite::create(filename);
	auto b = Blink::create(1, 20);
	_pSprite->runAction(b);
	this->addChild(_pSprite);
	this->setPosition(Vec2(rand()%961, rand()%641));
	itemsBox = Rect(this->getPositionX(), this->getPositionY(), _pSprite->getContentSize().width, _pSprite->getContentSize().height);
	this->scheduleUpdate();
	auto s = dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
	s->getLayer()->addChild(this);
	this->schedule(schedule_selector(Items::timedoDead), 10);
	return true;
}

void Items::doDead(){
	this->removeFromParentAndCleanup(true);
}

void Items::update(float t){
	if(this->itemsBox.intersectsRect(tanks::getInstance()->getBoundingBox())){
		switch (itemsstate)
		{
		case 1:EnemyVector::getInstence()->reset();break;
		case 2:break;
		case 3:break;
		default:
			break;
		}
		doDead();
	}
}

void Items::timedoDead(float t){
	doDead();
}
//
//Items* Items::instance = nullptr;
//
//Items* Items::getInstance(){
//	if (!instance){
//		instance = new Items();
//		instance->init();
//	}
//	return instance;
//}