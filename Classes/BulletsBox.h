#ifndef __BULLETSBOX_H_
#define __BULLETSBOX_H_
#include <cocos2d.h>
#include "Bullet.h"
USING_NS_CC;

class BulletsBox{
public:
	static BulletsBox* getInstance();
	void addBullet(Bullet* b);
	void deleteBullet(Bullet* b);
protected:
	static BulletsBox* instance;
private:
	CC_SYNTHESIZE(Vector<Bullet*>, bulletsVector, BulletsVector);
	BulletsBox(){}
	BulletsBox(const BulletsBox& b){};
	BulletsBox operator=(const BulletsBox& b){return b;}
};
#endif