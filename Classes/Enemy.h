#ifndef __ENEMY_H
#define __ENEMY_H
#include "cocos2d.h"
#include "Entity.h"
#define BASEHP 200
#define TIME 0.3
#define TANK 32                            //坦克宽高
#define STEP 16                            //一步的距离
using namespace cocos2d;
class Enemy:public Entity{
protected:
	int jd;                                //角度初始180
	int HP;                                //血量初始200
	int mark;                              //主机敌机标记
	float speed;
public:
	bool death;                            //死亡状态,假为死亡
	CC_SYNTHESIZE(int,score,Score);
	virtual void doAction();               //死亡动画
	virtual bool init();
	CREATE_FUNC(Enemy);
	void addFire(float t);                        //开火
	virtual bool hurt(int attackValue);                           //受伤方法，血量为0，调用die死亡方法,返回真为死亡
	void die();                            //死亡方法，在容器中清除，并把自己从父节点清除
	Sprite * sp;                           //坦克精灵
	Rect * getRect();                      //获得精灵坦克的碰撞体积
	void changejd(float t);                //改变方向方法
	void move(float t);
	int makeTurn();                        //转向方法
	void move(){}
};
#endif