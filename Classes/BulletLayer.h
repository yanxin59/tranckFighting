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

USING_NS_CC;

class Bullet;
//子弹层
class BulletLayer:public Layer{
public:
	virtual bool init();
	CREATE_FUNC(BulletLayer);
	//将子弹贴在层上
	void addBullet(Bullet* b);
protected:
	void update(float t);
};


#endif /* defined(__tranckFighting__BulletLayer__) */
