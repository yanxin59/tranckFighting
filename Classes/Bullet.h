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
	//create方法，第一个参数为方向，第二个参数为位置，第三个参数为队伍
	static Bullet* create(float r, Vec2 v, int t);
	//获取攻击力
	CC_SYNTHESIZE_READONLY(int, attack, Attack);
	void deleteBullet();
	//子弹精灵
	CC_SYNTHESIZE_READONLY(Sprite*, sp, Sp);
	//子弹的队伍
	CC_SYNTHESIZE_READONLY(int, team, Team);
protected:
	//移动动画
	void BulletsMove();
};
#endif