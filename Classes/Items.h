#ifndef __ITEMS_H_
#define __ITEMS_H_
#include <cocos2d.h>
USING_NS_CC;


class Items:public Node{
public:
	//static Items* getInstance();
	CC_SYNTHESIZE_READONLY(Sprite*, _pSprite, bindSprite);
	virtual void doDead();
	CC_SYNTHESIZE_READONLY(int, itemsstate, ItemsState);
	virtual bool init();
	CREATE_FUNC(Items);
	Rect itemsBox;
protected:
	void update(float t);
//protected:
//	static Items* instance;
//private:
//	Items(){}
//	Items(const Items& i){}
//	Items operator=(const Items& i){return i;}
};
#endif