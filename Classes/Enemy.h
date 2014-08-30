#ifndef __ENEMY_H
#define __ENEMY_H
#include "cocos2d.h"
#define BASEHP 200
#define SPEED 100
using namespace cocos2d;
class Enemy:public Node{
protected:
	int jd;                                //角度初始180
	int HP;                                //血量初始200
	int speed;                             //速度初始100
	int mark;                              //主机敌机标记
public:
	virtual bool init();
	CREATE_FUNC(Enemy);
	void addFire();                        //开火
	void move();                           //移动
	bool hurt(int attackValue);                           //受伤方法，血量为0，调用die死亡方法,返回真为死亡
	void die();                            //死亡方法，在容器中清除，并把自己从父节点清除
	Sprite * sp;                           //坦克精灵
	Rect * getRect();                      //获得精灵坦克的碰撞体积
	void changejd(float t);                //改变方向方法
	void move(float t);
};
#endif