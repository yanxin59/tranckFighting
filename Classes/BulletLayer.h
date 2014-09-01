//
//  BulletLayer.h
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#ifndef __tranckFighting__BulletLayer__
#define __tranckFighting__BulletLayer__
#include <cocos2d.h>
#include "Bullet.h"
USING_NS_CC;

#define MAPCELL 16

//�ӵ���
class BulletLayer:public Layer{
public:
	virtual bool init();
	CREATE_FUNC(BulletLayer);
	//���ӵ����ڲ���
	void addBullet(Bullet* b);
protected:
	void update(float t);
};


#endif /* defined(__tranckFighting__BulletLayer__) */
