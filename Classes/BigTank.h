#ifndef __BIGTANK
#define __BIGTANK
#include "cocos2d.h"
#include "Enemy.h"
#define BIGHP 800
using namespace cocos2d;
class BigTank:public Enemy{
	bool hurt(int attackValue);
public:
	virtual bool init();
	CREATE_FUNC(BigTank);
};
#endif