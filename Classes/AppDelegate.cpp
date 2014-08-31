#include "AppDelegate.h"
#include "ControllerLayer.h"
#include "GameScene.h"
<<<<<<< HEAD
=======



>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
	srand(time(0));                //»ñµÃ½Ç¶ÈËæ»úÖÖ×Ó
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
<<<<<<< HEAD
    auto scene = GameScene::create();

    // run
=======
 

    auto scene = GameScene::create();
       
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
    director->runWithScene(scene);

    
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
