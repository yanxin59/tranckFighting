
#include "BigTank.h"
bool BigTank::init(){
	if(!Enemy::init()){
		return false;
	}
	HP = BIGHP;
	sp->setTexture("blue.png");
	return true;
}
bool BigTank::hurt(int attackValue){
	HP -= attackValue;
	if(HP == 600){
		sp->setTexture("green.png");
		sp->setRotation(jd);
	}else if(HP == 400){
		sp->setTexture("yellow.png.png");
		sp->setRotation(jd);
	}else if(HP == 200){
		sp->setTexture("white.png");
		sp->setRotation(jd);
	}else if(HP <= 0){
		this->die();
		return true;                       //·µ»ØÕæÎªËÀÍö
	}
	return false;
}

