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
#include "BulletLayer.h"

using namespace cocos2d;

<<<<<<< HEAD
class GameScene:public Scene
{
    
protected:
    virtual bool init();
    
public:
    
    CREATE_FUNC(GameScene);
    

=======
class GameScene:public Scene{
public:
    virtual bool init();
	CREATE_FUNC(GameScene);
	BulletLayer* getLayer();
>>>>>>> c4bbd9cd6e5e193394b45530f9f4da713d3f46c9
};

#endif /* defined(__tranckFighting__GameScene__) */
