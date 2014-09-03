//
//  GameScene.h
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#ifndef __tranckFighting__GameScene__
#define __tranckFighting__GameScene__

#include "cocos2d.h"


using namespace cocos2d;

class BulletLayer;

class Maps;

class GameScene:public Scene
{
    
public:
    virtual bool init();
	CREATE_FUNC(GameScene);
	BulletLayer* getLayer();
	Maps * getMap();

};

#endif /* defined(__tranckFighting__GameScene__) */
