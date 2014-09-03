//
//  SceneFactory.h
//  tranckFighting
//
//  Created by Yan on 14-9-3.
//
//

#ifndef __tranckFighting__SceneFactory__
#define __tranckFighting__SceneFactory__


#include "config.h"

class SceneFactory
{
public:
    static Scene *createScene(const SceneTpye &rSceneType);
};

#endif /* defined(__tranckFighting__SceneFactory__) */
