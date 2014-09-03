
#include "BigTank.h"
bool BigTank::init(){
	if(!Enemy::init()){
		return false;
	}
	HP = BIGHP;
	setScore(500);
	sp->setTexture("blue.png");
	return true;
}
bool BigTank::hurt(int attackValue){
	HP -= attackValue;
	if(HP == 600){
		sp->setTexture("green.png");
		sp->setRotation(jd);
	}else if(HP == 400){
		sp->setTexture("yellow.png");
		sp->setRotation(jd);
	}else if(HP == 200){
		sp->setTexture("white.png");
		sp->setRotation(jd);
	}else if(HP <= 0 && death){
		int t_score = getScore();
		Ref * p_score = (Ref *)(&t_score);
		auto center = __NotificationCenter::getInstance();
		center->postNotification("addScore",p_score);
		death = false;
		this->doAction();
		return true;                       //·µ»ØÕæÎªËÀÍö
	}
	return false;
}

