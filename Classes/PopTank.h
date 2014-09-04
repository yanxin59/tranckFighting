#ifndef __POPTANK_H
#define __POPTANK_H
#include "cocos2d.h"
using namespace cocos2d;
class PopTank:public Node{
	std::vector<Vec2> point;
public:
	int count;
	virtual bool init();
	CREATE_FUNC(PopTank);
	static PopTank * getInstence();//»ñµÃµ¥Àý
	void addPoint(Vec2 ver);
	void mydate(float t);
};
#endif