#include "Items.h"
#include "tanks.h"
#include "EnemyVector.h"

bool Items::init(){
	if (!Node::init()){
		return false;
	}
	auto i = rand()%2 + 1;
	const char* filename;
	switch (i)
	{
	case 1:filename = "star.png";itemsstate = 1;break;
	case 2:filename = "timer.png";itemsstate = 2;break;
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
	return true;
}

void Items::doDead(){
	this->removeFromParentAndCleanup(true);
}

void Items::update(float t){
	if(this->itemsBox.intersectsRect(tanks::getInstance()->getBoundingBox())){
		switch (itemsstate)
		{
		case 1:EnemyVector::getInstence()->reset();log("yixing");break;
		case 2:log("tingzhi");break;
		default:
			break;
		}
		doDead();
	}
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