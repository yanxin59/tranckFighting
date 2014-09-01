#include "Bullet.h"
#include "BulletsBox.h"

bool Bullet::init(float r, Vec2 v){
	if (!Node::init()){//Sprite::initWithFile("bullet.png")
		return false;
	}
	//初始化队伍
	setEntityType(0);
	//设置速度
	setISpeed(300);
	//创建精灵
	setbindSprite(Sprite::create("bullet.png"));
	//攻击力
	this->attack = BULLETATTACK;
	//根据坦克角度旋转子弹
	this->setRotation(r);
	//将子弹初始位置置为坦克位置 + 2个子弹长度，为了看着是从炮口出来
	auto ss = getbindSprite()->getContentSize()*2;
	auto maxs = ss.width > ss.height ? ss.width:ss.height;
	switch ((int)r){
	case 0:ss.width = 0;ss.height = maxs;break;
	case 90:ss.height = 0;ss.width = maxs;break;
	case 180:ss.width = 0; ss.height = -maxs;break;
	case 270:ss.height = 0; ss.width = -maxs;break;
	default:
		break;
	}
	auto vs = v + ss;
	this->setPosition(vs);
	//将子弹加入容器
	BulletsBox::getInstance()->addBullet(this);
	//移动
	move();
	//添加
	this->addChild(getbindSprite());
	return true;
}

void Bullet::doAction(){

}

Bullet* Bullet::create(float r, Vec2 v, int t){
	auto b = new Bullet();
	if (b && b->init(r, v)){
		b->autorelease();
		b->setEntityType(t);
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
void Bullet::move(){
	//设置移动允许的最大值，现在为屏幕宽度
	float sum = Director::getInstance()->getVisibleSize().width;
	
	//设置移动偏移量
	float moveX = 0;
	float moveY = 0;
	//得到位置
	float positionBullet = 0;
	//根据角度， 位置改变移动方向，距离
	auto bs = this->getContentSize();
	auto maxs = bs.width > bs.height ? bs.width:bs.height;
	switch ((int)(this->getRotation())){
		
		case 0:sum = Director::getInstance()->getVisibleSize().height;positionBullet = this->getPosition().y;moveY = sum - positionBullet + maxs;break;
		case 90:positionBullet = this->getPosition().x;moveX = sum - positionBullet + maxs;break;
		case 180:sum = 0;positionBullet = -this->getPosition().y;moveY = positionBullet - maxs;break;
		case 270:sum = 0;positionBullet = -this->getPosition().x;moveX = positionBullet - maxs;break;
		default:
			break;
	}
	float number = sum - positionBullet;
	//移动动画
	auto move = MoveBy::create(number/getISpeed(), Vec2(moveX, moveY));
	auto cf = CallFunc::create([=](){
		BulletsBox::getInstance()->deleteBullet(this);
		doDead();
	});
	this->runAction(Sequence::create(move, cf, NULL));
}

//删除Node
void Bullet::doDead(){
	this->removeFromParentAndCleanup(true);
}