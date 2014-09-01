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
	EnemyVector::getInstence()->addEnemy(this);      //将坦克加入数组单例中
	sp = Sprite::create("p1-a-cell.png");
	Size sizep = sp->getContentSize();
	sp->setPosition(sizep/2);                        //Rect 基点为左下角 设基点与node位置重合
	addChild(sp);
	schedule(schedule_selector(Enemy::changejd),3);  //方向改变计时器
	schedule(schedule_selector(Enemy::move),0.6);    //行走即障碍规避计时器

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
		return true;                       //返回真为死亡
	}
	return false;
}
void Enemy::die(){
		EnemyVector::getInstence()->deleEnemy(this);
		this->removeFromParentAndCleanup(true);
}
Rect * Enemy::getRect(){                    //获得碰撞体积
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
	case 180: p.y -= TANK;w = TANK;h = STEP;break;                     //坦克为32*32像素，移动一步为16像素
	case 270: p.x -= TANK;w = STEP;h = TANK;break;
	}                                                            //计算预判点位置
	auto v = EnemyVector::getInstence()->getEV();
	for(auto vi = v.begin();vi != v.end();vi++){
		auto enemy = (Enemy *)(*vi);
		if(enemy == this)continue;
		if(enemy->getRect()->intersectsRect(Rect(p.x,p.y,w,h))){               //敌机精灵与预判点做碰撞检测
			int k = this->jd / 90;
			k = (k + rand()%3+1)%4;                 //改变方向
			this->jd = k * 90;
		}
	}
	sp->setRotation(this->jd);                     //改变图像方向
	Vec2 vec;
	switch(this->jd){
	case 0: vec = Vec2(0,STEP);break;
	case 90: vec = Vec2(STEP,0);;break;
	case 180: vec = Vec2(0,-STEP);break;
	case 270: vec = Vec2(-STEP,0);break;
	}   
	MoveBy * by = MoveBy::create(0.6,vec);         //移动一步动画

	Point tpoint = getPosition() + Vec2(STEP,STEP) + vec;
	Vec2 t_map = Vec2(tpoint.x/STEP,tpoint.y/STEP);
	if(tpoint.x > STEP && tpoint.x < 960 - STEP && tpoint.y > STEP && tpoint.y < 640 - STEP){
	if(bg->getTileGIDAt(t_map) || bird->getTileGIDAt(t_map) || iron->getTileGIDAt(t_map)){
		return;
	}
	}

	Size size = Director::getInstance()->getVisibleSize();                       //防止移出屏幕操作
	if(this->getPositionX() < STEP){MoveBy * by = MoveBy::create(0.6,Vec2(STEP,0));sp->setRotation(90);jd = 90;this->runAction(by);return;}
	if(this->getPositionY() < STEP){MoveBy * by = MoveBy::create(0.6,Vec2(0,STEP));sp->setRotation(0);jd = 0;this->runAction(by);return;}
	if(this->getPositionX() > size.width - sp->getContentSize().width - STEP){MoveBy * by = MoveBy::create(0.6,Vec2(-STEP,0));sp->setRotation(270);jd = 270;this->runAction(by);return;}
	if(this->getPositionY() > size.height - sp->getContentSize().height - STEP){MoveBy * by = MoveBy::create(0.6,Vec2(0,-STEP));sp->setRotation(180);jd = 180;this->runAction(by);return;}
	this->runAction(by);
	
}