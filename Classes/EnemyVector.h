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
	void reset();//�������
	static EnemyVector * getInstence();//��õ���
	void addEnemy(Enemy * bt);//��̹��
	void deleEnemy(Enemy * bt);//��̹��
	CC_SYNTHESIZE_READONLY_PASS_BY_REF(Vector<Enemy *>,enemyVector,EV);
	void clearEnemy();
};
#endif