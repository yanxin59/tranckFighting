#include "Bullet.h"
#include "BulletsBox.h"

bool Bullet::init(float r, Vec2 v){
	if (!Node::init()){//Sprite::initWithFile("bullet.png")
		return false;
	}
	sp = Sprite::create("bullet.png");
	this->attack = BULLETATTACK;
	this->setRotation(r);
	this->setPosition(v);
	BulletsBox::getInstance()->addBullet(this);
	BulletsMove();
	this->addChild(sp);
	return true;
}

Bullet* Bullet::create(float r, Vec2 v){
	auto b = new Bullet();
	if (b && b->init(r, v)){
		b->autorelease();
		switch ((int)r){
			case 0:break;
			case 90:b->setRotation(90);break;
			case 180:break;
			case 270:b->setRotation(270);break;
			default:
				break;
		}
		return b;
	}
	CC_SAFE_DELETE(b);
	return nullptr;
}

void Bullet::BulletsMove(){
	auto sum = Director::getInstance()->getVisibleSize().width;
	float moveX = 0;
	float moveY = 0;
	float positionBullet = 0;
	switch ((int)(this->getRotation())){
		case 0:moveY = sum;positionBullet = this->getPosition().y;break;
		case 90:moveX = sum;positionBullet = this->getPosition().x;break;
		case 180:moveY = -sum;positionBullet = this->getPosition().x;break;
		case 270:moveX = -sum;positionBullet = this->getPosition().x;break;
		default:
			break;
	}
	auto move = MoveBy::create((sum - positionBullet)/BULLETSPEED, Vec2(moveX, moveY));
	this->runAction(move);
}

void Bullet::deleteBullet(){
	this->removeFromParentAndCleanup(true);
}