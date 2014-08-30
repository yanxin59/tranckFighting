#ifndef __ENEMY_H
#define __ENEMY_H
#include "cocos2d.h"
#define BASEHP 200
#define SPEED 100
using namespace cocos2d;
class Enemy:public Node{
protected:
	int jd;                                //�Ƕȳ�ʼ180
	int HP;                                //Ѫ����ʼ200
	int speed;                             //�ٶȳ�ʼ100
	int mark;                              //�����л����
public:
	virtual bool init();
	CREATE_FUNC(Enemy);
	void addFire();                        //����
	void move();                           //�ƶ�
	bool hurt(int attackValue);                           //���˷�����Ѫ��Ϊ0������die��������,������Ϊ����
	void die();                            //����������������������������Լ��Ӹ��ڵ����
	Sprite * sp;                           //̹�˾���
	Rect * getRect();                      //��þ���̹�˵���ײ���
	void changejd(float t);                //�ı䷽�򷽷�
	void move(float t);
};
#endif