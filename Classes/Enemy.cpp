#include "Enemy.h"
#include "EnemyVector.h"
#include "time.h"
#include "Bullet.h"
#include "BulletLayer.h"
#include "GameScene.h"
#include "Map.h"

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
#include "tanks.h"
bool Enemy::init(){
	if(!Node::init()){
		return false;
	}
	
	HP = BASEHP;
	jd = 180;
	mark = 2;
	_entityType = mark;
	speed = TIME;
	setScore(100);
	death = true;
	EnemyVector::getInstence()->addEnemy(this);      //将坦克加入数组单例中
	sp = Sprite::create("p1-a-cell.png");
	Size sizep = sp->getContentSize();
	sp->setPosition(sizep/2);                        //Rect 基点为左下角 设基点与node位置重合
	addChild(sp);
	setbindSprite(sp);
	schedule(schedule_selector(Enemy::changejd),4.5);  //方向改变计时器

	schedule(schedule_selector(Enemy::addFire), 1.5);
	
	return true;
}
void Enemy::addFire(float t){
	auto p = this->getPosition();
	p = p + sp->getContentSize()/2;
	auto b = Bullet::create((float)jd, p, mark);
	auto s = dynamic_cast<GameScene*>(Director::getInstance()->getRunningScene());
    s->getLayer()->addBullet(b);
    SimpleAudioEngine::getInstance()->playEffect("bullet.aif");

}
bool Enemy::hurt(int attackValue){
	HP -= attackValue;
	if(HP <= 0 && death){
		int t_score = getScore();
		Ref * p_score = (Ref *)(&t_score);
		auto center = __NotificationCenter::getInstance();
		center->postNotification("addScore",p_score);
		death = false;
		this->doAction();
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
int Enemy::makeTurn(){
	int k = this->jd / 90;
	k = (k + rand()%3+1)%4;                 //改变方向
	this->jd = k * 90;
	return this->jd;
}
void Enemy::move(float t){
    
    SimpleAudioEngine::getInstance()->playEffect("move.aif");
    
	int key = 1;

	Size size = Director::getInstance()->getVisibleSize();                       //防止移出屏幕操作
	
	switch (this->jd)
	{
	case 0: if(this->getPositionY() > size.height - TANK - TANK)this->jd = 180;break;
	case 90: if(this->getPositionX() > size.width - TANK - TANK)this->jd = 270;break;
	case 180: if(this->getPositionY() < TANK)this->jd = 0;break;
	case 270: if(this->getPositionX() < TANK)this->jd = 90;break;
	default:
		break;
	}

	sp->setRotation(this->jd);
	GameScene * gs = (GameScene *)Director::getInstance()->getRunningScene(); 
	Maps * myMap = gs->getMap();
	cocos2d::TMXTiledMap *mMap = myMap->m_Map;
	cocos2d::TMXLayer *bg = myMap->m_bg;
	cocos2d::TMXLayer *bird = myMap->m_bird;
	cocos2d::TMXLayer *iron = myMap->m_iron;
	cocos2d::TMXLayer *water = myMap->m_water;
	Point p = this->getPosition();
	int w,h;
	switch(this->jd){
	case 0: p.y += TANK;w = TANK;h = STEP;break;
	case 90: p.x += TANK;w = STEP;h = TANK;break;
	case 180: p.y -= STEP;w = TANK;h = STEP;break;                     //坦克为32*32像素，移动一步为16像素
	case 270: p.x -= STEP;w = STEP;h = TANK;break;
	}                                                                  //计算预判矩形位置
	auto v = EnemyVector::getInstence()->getEV();
	for(auto vi = v.begin();vi != v.end();vi++){
		auto enemy = (Enemy *)(*vi);
		if(enemy == this)continue;
		if(enemy->getRect()->intersectsRect(Rect(p.x,p.y,w,h))){               //敌机精灵与预判点做碰撞检测
			key = 0;
		}
	}
	
	tanks * MainTank = tanks::getInstance();
	if(Rect(p.x,p.y,w,h).intersectsRect(MainTank->getBoundingBox())){
		key = 0;
	}

	Point tpoint1;
	Point tpoint2;
	switch(this->jd){
	case 0: tpoint1 = getPosition() + Vec2(0,TANK + STEP);tpoint2 = getPosition() + Vec2(STEP,TANK + STEP);break;
	case 90: tpoint1 = getPosition() + Vec2(TANK + STEP,TANK);tpoint2 = getPosition() + Vec2(TANK + STEP,STEP);break;
	case 180: tpoint1 = getPosition() + Vec2(0,-STEP);tpoint2 = getPosition() + Vec2(STEP,-STEP);break;
	case 270: tpoint1 = getPosition() + Vec2(-STEP,STEP);tpoint2 = getPosition() + Vec2(-STEP,TANK);break;
	} 

	Vec2 t_map1 = Vec2(tpoint1.x/STEP ,40 - tpoint1.y/STEP);
	Vec2 t_map2 = Vec2(tpoint2.x/STEP ,40 - tpoint2.y/STEP);
	if(this->jd == 90 || this->jd == 270){
	if(bg->getTileGIDAt(t_map1) != 0 || iron->getTileGIDAt(t_map1) != 0 || water->getTileGIDAt(t_map1) != 0){
		key = 0;
	}
	if(bg->getTileGIDAt(t_map2) != 0 || iron->getTileGIDAt(t_map2) != 0 || water->getTileGIDAt(t_map2) != 0){
		key = 0;
	}
	}
	if(this->jd == 0 || this->jd == 180){
		t_map1 = myMap->getGID(tpoint1);
		t_map2 = myMap->getGID(tpoint2);	
		if(bg->getTileGIDAt(t_map1) != 0 || iron->getTileGIDAt(t_map1) != 0 || water->getTileGIDAt(t_map1) != 0){
			key = 0;
		}
		if(bg->getTileGIDAt(t_map2) != 0 || iron->getTileGIDAt(t_map2) != 0 || water->getTileGIDAt(t_map2) != 0){
			key = 0;
		}
	}
	

	Vec2 vec;
	switch(this->jd){
	case 0: vec = Vec2(0,STEP);break;
	case 90: vec = Vec2(STEP,0);;break;
	case 180: vec = Vec2(0,-STEP);break;
	case 270: vec = Vec2(-STEP,0);break;
	}   
	MoveBy * by = MoveBy::create(speed,vec);         //移动一步动画

	if(key != 0){

		this->runAction(by);
		return;
	}else{
		sp->setRotation(makeTurn());
	}
}
void Enemy::doAction(){

	auto center = __NotificationCenter::getInstance();
	center->postNotification("changeEnemyCount",NULL);
	
	this->unscheduleAllSelectors();
	//Blink * blink = Blink::create(0.5,3);
	Animation * ani = Animation::create();
	for(int i = 1;i < 6;i++){
		String * str = String::createWithFormat("blast%d.png",i);
		SpriteFrame * sf = SpriteFrame::create(str->getCString(),Rect(0,0,41,32));
		ani->addSpriteFrame(sf);
	}
	ani->setDelayPerUnit(0.1);
	ani->setLoops(1);
	Animate * ai = Animate::create(ani);
	CallFunc * cf = CallFunc::create(CC_CALLBACK_0(Enemy::die,this));
	Sequence * seq = Sequence::create(ai,cf,NULL);
	getbindSprite()->runAction(seq);
}
void Enemy::onEnter(){
	Entity::onEnter();
	schedule(schedule_selector(Enemy::move),speed);    //行走即障碍规避计时器
}