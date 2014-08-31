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
<<<<<<< HEAD


using namespace cocos2d;
class BulletLayer;
class Maps;
class GameScene:public Scene{
public:
    virtual bool init();
	CREATE_FUNC(GameScene);
	BulletLayer* getLayer();
	Maps * getMap();
=======
class BulletLayer;
using namespace cocos2d;


class GameScene:public Scene{
public:
    virtual bool init();
    CREATE_FUNC(GameScene);
    BulletLayer* getLayer();
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
};

#endif /* defined(__tranckFighting__GameScene__) */
