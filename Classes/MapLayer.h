#ifndef __MAPLAYER_H_
#define __MAPLAYER_H_
#include <cocos2d.h>
#include <map>
USING_NS_CC;

class MapLayer:public Layer{
public:
	virtual bool init();
	CREATE_FUNC(MapLayer);
	
};
#endif