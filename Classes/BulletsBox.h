#ifndef __BULLETSBOX_H_
#define __BULLETSBOX_H_
#include <cocos2d.h>
#include "Bullet.h"
USING_NS_CC;

//子弹容器
class BulletsBox{
public:
	static BulletsBox* getInstance();
	//向容器添加子弹方法
	void addBullet(Bullet* b);
	//从容器删除子弹方法
	void deleteBullet(Bullet* b);
	void clearVector();
protected:
	static BulletsBox* instance;
private:
	//
	CC_SYNTHESIZE(Vector<Bullet*>, bulletsVector, BulletsVector);
	BulletsBox(){}
	BulletsBox(const BulletsBox& b){};
	BulletsBox operator=(const BulletsBox& b){return b;}
};
#endif