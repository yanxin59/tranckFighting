#ifndef __BULLET_H_
#define __BULLET_H_
#include <cocos2d.h>
#include "Entity.h"
USING_NS_CC;


//子弹攻击
#define BULLETATTACK 200

//子弹类
class Bullet:public Entity{
public:
	virtual bool init(float r, Vec2 v);
	//create方法，第一个参数为方向，第二个参数为位置，第三个参数为队伍
	static Bullet* create(float r, Vec2 v, int t);
	//获取攻击力
	CC_SYNTHESIZE_READONLY(int, attack, Attack);
	virtual void doDead();
	CC_SYNTHESIZE_READONLY(Size, buletsize, BulletSize);
protected:
	virtual void doAction();
	virtual void move();
};
#endif