#ifndef __ENEMY_H
#define __ENEMY_H
#include "cocos2d.h"
#include "Entity.h"
#define BASEHP 200
#define TIME 0.3
#define TANK 32                            //̹�˿��
#define STEP 16                            //һ���ľ���
using namespace cocos2d;
class Enemy:public Entity{
protected:
	int jd;                                //�Ƕȳ�ʼ180
	int HP;                                //Ѫ����ʼ200
	int mark;                              //�����л����
	float speed;
public:
	bool death;                            //����״̬,��Ϊ����
	CC_SYNTHESIZE(int,score,Score);
	virtual void doAction();               //��������
	virtual bool init();
	CREATE_FUNC(Enemy);
	void addFire(float t);                        //����
	virtual bool hurt(int attackValue);                           //���˷�����Ѫ��Ϊ0������die��������,������Ϊ����
	void die();                            //����������������������������Լ��Ӹ��ڵ����
	Sprite * sp;                           //̹�˾���
	Rect * getRect();                      //��þ���̹�˵���ײ���
	void changejd(float t);                //�ı䷽�򷽷�
	void move(float t);
	int makeTurn();                        //ת�򷽷�
	void move(){}
};
#endif