#include "Enemy.h"
#include "EnemyVector.h"
#include "time.h"
#include "Bullet.h"
#include "BulletLayer.h"
#include "GameScene.h"
bool Enemy::init(){
	if(!Node::init()){
		return false;
	}
	
	HP = BASEHP;
	jd = 180;
	speed = SPEED;
	mark = 2;
	EnemyVector::getInstence()->addEnemy(this);      //��̹�˼������鵥����
	sp = Sprite::create("p1-a-cell-hd.png");
	Size sizep = sp->getContentSize();
	sp->setPosition(sizep/2);                        //Rect ����Ϊ���½� �������nodeλ���غ�
	addChild(sp);
	schedule(schedule_selector(Enemy::changejd),3);  //����ı��ʱ��
	schedule(schedule_selector(Enemy::move),0.6);    //���߼��ϰ���ܼ�ʱ��
	this->schedule(schedule_selector(Enemy::addFire,this), 1);
	return true;
}
void Enemy::addFire(float t){
	auto p = this->getPosition();
	p = p + sp->getContentSize()/2;
	auto b = Bullet::create((float)jd, p, 2);
	auto s = dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
	s->getLayer()->addBullet(b);
}
bool Enemy::hurt(int attackValue){
	HP -= attackValue;
	if(HP <= 0){
		this->die();
		return true;                       //������Ϊ����
	}
	return false;
}
void Enemy::die(){
		EnemyVector::getInstence()->deleEnemy(this);
		this->removeFromParentAndCleanup(true);
}
Rect * Enemy::getRect(){                    //�����ײ���
	return new Rect(this->getPositionX(),this->getPositionY(),sp->getContentSize().width,sp->getContentSize().height);
}
void Enemy::changejd(float t){
	this->jd = (rand()%4)*90;
}
void Enemy::move(float t){
	Point p = this->getPosition();
	int w,h;
	switch(this->jd){
	case 0: p.y += 64;w = 64;h = 32;break;
	case 90: p.x += 64;w = 32;h = 64;break;
	case 180: p.y -= 64;w = 64;h = 32;break;                     //̹��Ϊ64��64���أ��ƶ�һ��Ϊ32����
	case 270: p.x -= 64;w = 32;h = 64;break;
	}                                                            //����Ԥ�е�λ��
	auto v = EnemyVector::getInstence()->getEV();
	for(auto vi = v.begin();vi != v.end();vi++){
		auto enemy = (Enemy *)(*vi);
		if(enemy == this)continue;
		if(enemy->getRect()->intersectsRect(Rect(p.x,p.y,w,h))){               //�л�������Ԥ�е�����ײ���
			int k = this->jd / 90;
			k = (k + rand()%3+1)%4;                 //�ı䷽��
			this->jd = k * 90;
		}
	}
	sp->setRotation(this->jd);                     //�ı�ͼ����
	Vec2 vec;
	switch(this->jd){
	case 0: vec = Vec2(0,32);break;
	case 90: vec = Vec2(32,0);;break;
	case 180: vec = Vec2(0,-32);break;
	case 270: vec = Vec2(-32,0);break;
	}   
	MoveBy * by = MoveBy::create(0.3,vec);         //�ƶ�һ������
	Size size = Director::getInstance()->getVisibleSize();                       //��ֹ�Ƴ���Ļ����
	if(this->getPositionX() < 32){MoveBy * by = MoveBy::create(0.3,Vec2(32,0));sp->setRotation(90);this->runAction(by);return;}
	if(this->getPositionY() < 32){MoveBy * by = MoveBy::create(0.3,Vec2(0,32));sp->setRotation(0);this->runAction(by);return;}
	if(this->getPositionX() > size.width - sp->getContentSize().width - 32){MoveBy * by = MoveBy::create(0.3,Vec2(-32,0));sp->setRotation(270);this->runAction(by);return;}
	if(this->getPositionY() > size.height - sp->getContentSize().height - 32){MoveBy * by = MoveBy::create(0.3,Vec2(0,-32));sp->setRotation(180);this->runAction(by);return;}
	this->runAction(by);
	
}