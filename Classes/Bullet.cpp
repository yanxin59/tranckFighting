#include "Bullet.h"
#include "BulletsBox.h"

bool Bullet::init(float r, Vec2 v){
	if (!Node::init()){//Sprite::initWithFile("bullet.png")
		return false;
	}
	//初始化队伍
	team = 0;
	//创建精灵
	sp = Sprite::create("bullet.png");
	//攻击力
	this->attack = BULLETATTACK;
	//根据坦克角度旋转子弹
	this->setRotation(r);
	//将子弹初始位置置为坦克位置
	this->setPosition(v);
	//将子弹加入容器
	BulletsBox::getInstance()->addBullet(this);
	//移动
	BulletsMove();
	//添加
	this->addChild(sp);
	return true;
}

Bullet* Bullet::create(float r, Vec2 v, int t){
	auto b = new Bullet();
	if (b && b->init(r, v)){
		b->autorelease();
		b->team = t;
		//根据角度转换子弹方向
		switch ((int)r){
			case 0:b->setRotation(0);break;
			case 90:b->setRotation(90);break;
			case 180:b->setRotation(180);break;
			case 270:b->setRotation(270);break;
			default:
				break;
		}
		return b;
	}
	CC_SAFE_DELETE(b);
	return nullptr;
}

//子弹移动动画
void Bullet::BulletsMove(){
	//设置移动允许的最大值，现在为屏幕宽度
	float sum = Director::getInstance()->getVisibleSize().width;
	
	//设置移动偏移量
	float moveX = 0;
	float moveY = 0;
	//得到位置
	float positionBullet = 0;
	//根据角度， 位置改变移动方向，距离

	switch ((int)(this->getRotation())){
		
		case 0:sum = Director::getInstance()->getVisibleSize().height;positionBullet = this->getPosition().y;moveY = sum - positionBullet;break;
		case 90:positionBullet = this->getPosition().x;moveX = sum - positionBullet;break;
		case 180:sum = 0;positionBullet = -this->getPosition().y;moveY = positionBullet;break;
		case 270:sum = 0;positionBullet = -this->getPosition().x;moveX = positionBullet;break;
		default:
			break;
	}
	float number = sum - positionBullet;
	//移动动画
	auto move = MoveBy::create(number/BULLETSPEED, Vec2(moveX, moveY));
	this->runAction(move);
}

//删除Node
void Bullet::deleteBullet(){
	this->removeFromParentAndCleanup(true);
}