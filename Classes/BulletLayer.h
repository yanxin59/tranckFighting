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


//子弹层
class BulletLayer:public Layer{
public:
	virtual bool init();
	CREATE_FUNC(BulletLayer);
	//将子弹贴在层上
	void addBullet(Bullet* b);
};


#endif /* defined(__tranckFighting__BulletLayer__) */
