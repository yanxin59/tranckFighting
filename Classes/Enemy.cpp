#include "Enemy.h"
#include "EnemyVector.h"
bool Enemy::init(){
	if(!Node::init()){
		return false;
	}
	HP = BASEHP;
	jd = 180;
	speed = SPEED;
	EnemyVector::getInstence()->addEnemy(this);    //��̹�˼������鵥����
	sp = Sprite::create("p1-a-cell-hd.png");
	Size sizep = sp->getContentSize();
	sp->setPosition(sizep/2);                        //Rect ����Ϊ���½� �������nodeλ���غ�
	addChild(sp);
	return true;
}
void Enemy::addFire(Vec2 point){

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
Rect * Enemy::getRect(){
	return new Rect(this->getPositionX(),this->getPositionY(),sp->getContentSize().width,sp->getContentSize().height);
}