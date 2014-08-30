#include "BulletsBox.h"

BulletsBox* BulletsBox::instance = nullptr;

BulletsBox* BulletsBox::getInstance(){
	if (!instance){
		instance = new BulletsBox();
	}
	return instance;
}

//向容器中添加子弹
void BulletsBox::addBullet(Bullet* b){
	bulletsVector.pushBack(b);
}

//从容器中删除子弹
void BulletsBox::deleteBullet(Bullet* b){
	bulletsVector.eraseObject(b);
}