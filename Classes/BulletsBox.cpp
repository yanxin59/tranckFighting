#include "BulletsBox.h"

BulletsBox* BulletsBox::instance = nullptr;

BulletsBox* BulletsBox::getInstance(){
	if (!instance){
		instance = new BulletsBox();
	}
	return instance;
}

//������������ӵ�
void BulletsBox::addBullet(Bullet* b){
	bulletsVector.pushBack(b);
}

//��������ɾ���ӵ�
void BulletsBox::deleteBullet(Bullet* b){
	bulletsVector.eraseObject(b);
}