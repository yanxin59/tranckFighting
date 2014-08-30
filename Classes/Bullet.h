#ifndef __BULLET_H_
#define __BULLET_H_
#include <cocos2d.h>
USING_NS_CC;

//子弹速度
#define BULLETSPEED 100
//子弹攻击
#define BULLETATTACK 100

//子弹类
class Bullet:public Node{
public:
	virtual bool init(float r, Vec2 v);
	static Bullet* create(float r, Vec2 v);
	//获取攻击力
	CC_SYNTHESIZE_READONLY(int, attack, Attack);
	void deleteBullet();
	//子弹精灵
	CC_SYNTHESIZE_READONLY(Sprite*, sp, Sp);
protected:
	//移动动画
	void BulletsMove();
};
#endif