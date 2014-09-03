#ifndef __ENEMYVECTOR_H
#define __ENEMYVECTOR_H
#include "cocos2d.h"
#include "Enemy.h"
using namespace cocos2d;
class EnemyVector{
private:
	static EnemyVector * instence;
	EnemyVector(){}
	EnemyVector(const EnemyVector & t){}
	EnemyVector operator=(const EnemyVector & t){return t;}
public:
	void reset();//清空容器
	static EnemyVector * getInstence();//获得单例
	void addEnemy(Enemy * bt);//加坦克
	void deleEnemy(Enemy * bt);//减坦克
	CC_SYNTHESIZE_READONLY_PASS_BY_REF(Vector<Enemy *>,enemyVector,EV);
	void clearEnemy();
};
#endif