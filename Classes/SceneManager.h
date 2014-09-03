//
//  SceneManager.h
//  tranckFighting
//
//  Created by Yan on 14-9-3.
//
//

#ifndef __tranckFighting__SceneManager__
#define __tranckFighting__SceneManager__

#include "config.h"

class SceneManager:public Node
{
    
private:

public:
    
    static SceneManager *getInstance();
    
    static void delInstance();
    
    virtual void initStartScene();

protected:
    
    virtual void changeScene(Ref *pData);
    
    virtual void registerSceneTransEvent();
    
private:
    
    SceneTpye _sceneType;

private:
    
    static SceneManager *_gInstance;
    
private:

    CREATE_FUNC(SceneManager);
    
    SceneManager();
    
    virtual ~SceneManager();
    
    SceneManager(const SceneManager &){};
    
    SceneManager &operator=(const SceneManager &){};
};

#endif /* defined(__tranckFighting__SceneManager__) */
