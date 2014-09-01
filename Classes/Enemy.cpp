#include "Enemy.h"
#include "EnemyVector.h"
#include "time.h"
#include "Bullet.h"
#include "BulletLayer.h"
#include "GameScene.h"
#include "Map.h"
bool Enemy::init(){
	if(!Node::init()){
		return false;
	}
	
	HP = BASEHP;
	jd = 180;
	speed = SPEED;
	mark = 2;
	EnemyVector::getInstence()->addEnemy(this);      //��̹�˼������鵥����
	sp = Sprite::create("p1-a-cell.png");
	Size sizep = sp->getContentSize();
	sp->setPosition(sizep/2);                        //Rect ����Ϊ���½� �������nodeλ���غ�
	addChild(sp);
	schedule(schedule_selector(Enemy::changejd),3);  //����ı��ʱ��
	schedule(schedule_selector(Enemy::move),0.6);    //���߼��ϰ���ܼ�ʱ��

	this->schedule(schedule_selector(Enemy::addFire), 1);
	return true;
}
void Enemy::addFire(float t){
	auto p = this->getPosition();
	p = p + sp->getContentSize()/2;
	auto b = Bullet::create((float)jd, p, mark);
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
	GameScene * gs = (GameScene *)Director::getInstance()->getRunningScene(); 
	Maps * myMap = gs->getMap();
	cocos2d::TMXTiledMap *mMap = myMap->m_Map;
	cocos2d::TMXLayer *bg = myMap->m_bg;
	cocos2d::TMXLayer *bird = myMap->m_bird;
	cocos2d::TMXLayer *iron = myMap->m_iron;
	
	Point p = this->getPosition();
	int w,h;
	switch(this->jd){
	case 0: p.y += TANK;w = TANK;h = STEP;break;
	case 90: p.x += TANK;w = STEP;h = TANK;break;
	case 180: p.y -= TANK;w = TANK;h = STEP;break;                     //̹��Ϊ32*32���أ��ƶ�һ��Ϊ16����
	case 270: p.x -= TANK;w = STEP;h = TANK;break;
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
	case 0: vec = Vec2(0,STEP);break;
	case 90: vec = Vec2(STEP,0);;break;
	case 180: vec = Vec2(0,-STEP);break;
	case 270: vec = Vec2(-STEP,0);break;
	}   
	MoveBy * by = MoveBy::create(0.6,vec);         //�ƶ�һ������

	Point tpoint = getPosition() + Vec2(STEP,STEP) + vec;
	Vec2 t_map = Vec2(tpoint.x/STEP,tpoint.y/STEP);
	if(tpoint.x > STEP && tpoint.x < 960 - STEP && tpoint.y > STEP && tpoint.y < 640 - STEP){
	if(bg->getTileGIDAt(t_map) || bird->getTileGIDAt(t_map) || iron->getTileGIDAt(t_map)){
		return;
	}
	}

	Size size = Director::getInstance()->getVisibleSize();                       //��ֹ�Ƴ���Ļ����
	if(this->getPositionX() < STEP){MoveBy * by = MoveBy::create(0.6,Vec2(STEP,0));sp->setRotation(90);jd = 90;this->runAction(by);return;}
	if(this->getPositionY() < STEP){MoveBy * by = MoveBy::create(0.6,Vec2(0,STEP));sp->setRotation(0);jd = 0;this->runAction(by);return;}
	if(this->getPositionX() > size.width - sp->getContentSize().width - STEP){MoveBy * by = MoveBy::create(0.6,Vec2(-STEP,0));sp->setRotation(270);jd = 270;this->runAction(by);return;}
	if(this->getPositionY() > size.height - sp->getContentSize().height - STEP){MoveBy * by = MoveBy::create(0.6,Vec2(0,-STEP));sp->setRotation(180);jd = 180;this->runAction(by);return;}
	this->runAction(by);
	
}