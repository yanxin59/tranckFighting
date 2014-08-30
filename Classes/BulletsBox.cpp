#include "BulletsBox.h"

BulletsBox* BulletsBox::instance = nullptr;

BulletsBox* BulletsBox::getInstance(){
	if (!instance){
		instance = new BulletsBox();
	}
	return instance;
}

void BulletsBox::addBullet(Bullet* b){
	bulletsVector.pushBack(b);
}

void BulletsBox::deleteBullet(Bullet* b){
	bulletsVector.eraseObject(b);
}