#ifndef __BULLET_H_
#define __BULLET_H_
#include <cocos2d.h>
#include "Entity.h"
USING_NS_CC;


//�ӵ�����
#define BULLETATTACK 200

//�ӵ���
class Bullet:public Entity{
public:
	virtual bool init(float r, Vec2 v);
	//create��������һ������Ϊ���򣬵ڶ�������Ϊλ�ã�����������Ϊ����
	static Bullet* create(float r, Vec2 v, int t);
	//��ȡ������
	CC_SYNTHESIZE_READONLY(int, attack, Attack);
	virtual void doDead();
	CC_SYNTHESIZE_READONLY(Size, buletsize, BulletSize);
protected:
	virtual void doAction();
	virtual void move();
};
#endif