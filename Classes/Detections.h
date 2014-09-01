#ifndef __DETECTIOMS_H_
#define __DETECTIOMS_H_
#include <cocos2d.h>
#include "Bullet.h"
#include "Enemy.h"
USING_NS_CC;

class Detections{
public:
	static Detections* getInstance();
	bool BulletBullet(Bullet* b1, Bullet* b2);
	bool BulletBullet(Bullet* b1, Enemy* e1);
	bool BulletBullet(Bullet* b);
protected:
	static Detections* instance;
	
private:
	Detections(){}
	Detections(const Detections& c){}
	Detections operator=(const Detections& c){return c;}
};
#endif