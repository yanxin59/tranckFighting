#ifndef __MAP_H
#define __MAP_H
#include "cocos2d.h"
using namespace cocos2d;
class Maps:public Layer{
    
protected:
    
    virtual bool init();
    
public:
    

    Maps();
    
    virtual ~Maps();
    
	cocos2d::TMXTiledMap *m_Map;
	cocos2d::TMXLayer *m_bg;
	cocos2d::TMXLayer *m_bird;
	cocos2d::TMXLayer *m_iron;
	cocos2d::TMXLayer *m_water;
    cocos2d::TMXObjectGroup *_pObjectGroup;
    
	CREATE_FUNC(Maps);
    
	Point getGID(Vec2 ver);
    
    
};
#endif