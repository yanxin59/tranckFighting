//
//  SceneFactory.cpp
//  tranckFighting
//
//  Created by Yan on 14-9-3.
//
//

#include "SceneFactory.h"
#include "MainScene.h"
#include "GameScene.h"
#include "stopScene.h"


Scene *SceneFactory::createScene(const SceneTpye &rSceneType)
{
    Scene *pScene = nullptr;
    switch (rSceneType) {
        case en_WelcomeScene:
            pScene = MainScene::create();
            break;
        case en_GameScene:
            pScene = GameScene::create();
            break;
        case en_GameEndScene:
            pScene = stopScene::create();
            break;
        default:
            break;
    }
    return pScene;
}