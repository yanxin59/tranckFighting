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
class BulletLayer;
using namespace cocos2d;


class GameScene:public Scene{
public:
    virtual bool init();
    CREATE_FUNC(GameScene);
    BulletLayer* getLayer();
};

#endif /* defined(__tranckFighting__GameScene__) */
