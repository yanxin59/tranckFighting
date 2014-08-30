#ifndef __BULLET_H_
#define __BULLET_H_
#include <cocos2d.h>
USING_NS_CC;

//�ӵ��ٶ�
#define BULLETSPEED 100
//�ӵ�����
#define BULLETATTACK 100

//�ӵ���
class Bullet:public Node{
public:
	virtual bool init(float r, Vec2 v);
	//create��������һ������Ϊ���򣬵ڶ�������Ϊλ�ã�����������Ϊ����
	static Bullet* create(float r, Vec2 v, int t);
	//��ȡ������
	CC_SYNTHESIZE_READONLY(int, attack, Attack);
	void deleteBullet();
	//�ӵ�����
	CC_SYNTHESIZE_READONLY(Sprite*, sp, Sp);
	//�ӵ��Ķ���
	CC_SYNTHESIZE_READONLY(int, team, Team);
protected:
	//�ƶ�����
	void BulletsMove();
};
#endif