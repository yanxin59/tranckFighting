#ifndef __FASTERTANK_H
#define __FASTERTANK_H
#include "cocos2d.h"
#include "Enemy.h"
#define FASTHP 400
#define FASTTIME 0.2
using namespace cocos2d;
class FasterTank:public Enemy{
public:
	virtual bool init();
	CREATE_FUNC(FasterTank);
};
#endif
