//
//  SceneManager.cpp
//  tranckFighting
//
//  Created by Yan on 14-9-3.
//
//

#include "SceneManager.h"
#include "SceneFactory.h"

SceneManager *SceneManager::_gInstance = nullptr;

SceneManager::SceneManager():_sceneType(en_WelcomeScene)
{
    
}

SceneManager::~SceneManager()
{
    NotificationCenter::getInstance()->removeAllObservers(this);
}

SceneManager *SceneManager::getInstance()
{
    if(!_gInstance)
    {
        _gInstance = new SceneManager();
        _gInstance->retain();
    }
    return _gInstance;
}

void SceneManager::delInstance()
{
    if(_gInstance) CC_SAFE_RELEASE_NULL(_gInstance);
}

void SceneManager::changeScene(Ref *pData)
{
    if(!pData) return;
    _sceneType = *(reinterpret_cast<SceneTpye *>(pData));
    auto pDirector = Director::getInstance();
    auto pCurRuningScene = pDirector->getRunningScene();
    auto pScene = SceneFactory::createScene(_sceneType);
    pCurRuningScene ? pDirector->runWithScene(pScene) : pDirector->replaceScene(pScene);
}

void SceneManager::initStartScene()
{
    Director::getInstance()->runWithScene(SceneFactory::createScene(_sceneType));
}

void SceneManager::registerSceneTransEvent()
{
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(SceneManager::changeScene), "changeScene", nullptr);
}

