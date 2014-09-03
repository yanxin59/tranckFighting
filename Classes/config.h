//
//  config.h
//  tranckFighting
//
//  Created by Yan on 14-9-3.
//
//

#ifndef tranckFighting_config_h
#define tranckFighting_config_h

#include "cocos2d.h"

using namespace cocos2d;

enum SceneTpye
{
    en_WelcomeScene,
    en_GameScene,
    en_GameEndScene
};

enum TankState
{
    en_NormalState,
    en_StopEnemyState,
    en_BombEnemyState,
    en_AddBulletSpeedState
};

#endif
