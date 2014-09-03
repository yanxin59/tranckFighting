#include "FasterTank.h"
bool FasterTank::init(){
	if(!Enemy::init()){
		return false;
	}
	HP = FASTHP;
	speed = FASTTIME;
	setScore(200);
	sp->setTexture("pink.png");
	return true;
}