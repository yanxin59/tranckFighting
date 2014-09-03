#include "FasterTank.h"
bool FasterTank::init(){
	if(!Enemy::init()){
		return false;
	}
	HP = FASTHP;
	speed = FASTTIME;
	sp->setTexture("pink.png");
	return true;
}