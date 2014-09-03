//
//  tanks.cpp
//  tranckFighting
//
//  Created by 王紫叶 on 14-8-30.
//
//

#include "tanks.h"
#include "GameScene.h"
#include "Map.h"
#include "Bullet.h"
#include "BulletLayer.h"
#include "SimpleAudioEngine.h"
#include "stopScene.h"

using namespace CocosDenshion;

tanks * tanks::instance = nullptr;

tanks * tanks::getInstance()
{
    if (!instance) {
        instance = tanks::create();
        
    }
    return instance;
}

tanks::tanks()
{
    _pTank = Sprite::create("p1-a-cell.png");
    this->addChild(_pTank);
}

void tanks::addFire(){
    
    auto bu = Bullet::create(getRotation(), getPosition(), 1);//创建子弹
    
    auto gamescene  =  dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());//通过导演得到运行中的场景
    
    auto layer = gamescene->getLayer();//通过运行的场景得到子弹层
    
    layer->addBullet(bu);//把子弹加到子弹层
    
    SimpleAudioEngine::getInstance()->playEffect("bullet.aif");
    
    //点击按钮,开火
}

void tanks::mineTankDie(){
 
    playAnimation();
    
    auto scene = stopScene::create();
    
    Director::getInstance()->replaceScene(scene);
    
}
void tanks::playAnimation(){
    
    SimpleAudioEngine::getInstance()->playEffect("tankbomb.aif");
    
    SimpleAudioEngine::getInstance()->playEffect("gameover.aif");
}
Rect tanks::getBoundingBox()
{
    auto tCurPos = getPosition();//当前的位置
    auto tSize = _pTank->getContentSize();//坦克的尺寸
    return Rect(tCurPos.x - tSize.width / 2, tCurPos.y - tSize.height / 2, tSize.width, tSize.height);//返回一个矩形,当前位置和坦克尺寸
}

void tanks::up(){
    
    setRotation(en_Up);//角度为0,方向朝上
    
    SimpleAudioEngine::getInstance()->playEffect("move.aif");
    
    if(judge())//如果前方有障碍物,停止向前
        return ;
    setPositionY(getPositionY()+1);//一步一步移动
    Size s = Director::getInstance()->getVisibleSize();//屏幕尺寸
    Size tSize = _pTank->getContentSize();//坦克尺寸
    if (getPositionY() >= (s.height - tSize.height/2)) {
        
        setPositionY(s.height - tSize.height/2);
    }//如果坦克要出了上边界,就让它停留在上边界

}

void tanks::down(){
    setRotation(en_Down);
    

    if(judge())
        return ;
     SimpleAudioEngine::getInstance()->playEffect("move.aif");
    setPositionY(getPositionY()-1);
    Size  sSize = _pTank->getContentSize();
    if (getPositionY() < sSize.height/2) {
        
        setPositionY(sSize.height/2);
    }
}
void tanks::left(){
 
    setRotation(en_Left);
    
     SimpleAudioEngine::getInstance()->playEffect("move.aif");
    if(judge())
        return ;

    setPositionX(getPositionX()-1);
    Size sSize = _pTank->getContentSize();
    if (getPositionX() < sSize.width/2) {
        setPositionX(sSize.width/2);
    }

}
void tanks::right(){

    setRotation(en_Right);
    
     SimpleAudioEngine::getInstance()->playEffect("move.aif");
    if(judge())
        return ;
    setPositionX(getPositionX()+1);
    Size s = Director::getInstance()->getVisibleSize();
    Size sSize = _pTank->getContentSize();
    if (getPositionX() >= (s.width-sSize.width/2 )) {
        setPositionX(s.width-sSize.width/2);
    }
}



bool tanks::judge()
{
    
    auto tMap = (dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene()))->getMap();
    auto tBg = tMap->m_bg;
    auto tRotate = getRotation();
    auto tBgheight = tBg->getLayerSize().height;
    
    auto tBgWidth = tBg->getLayerSize().width;
    
    auto tBgZero = 0;
    
    auto px1 = 0;
    auto px2 = 0;
    
    auto py1 = 0;
    auto py2 = 0;
    
    if(tRotate == en_Up || tRotate == en_Down)
    {
        py1 = tRotate == en_Up ? tBgheight - (getPositionY() + SEGMENTSIZE) / SEGMENTSIZE : tBgheight - (getPositionY() - SEGMENTSIZE) / SEGMENTSIZE;
        px1 = (getPositionX() - SEGMENTSIZE / 2) / SEGMENTSIZE;
        px2 = (getPositionX() + SEGMENTSIZE / 2) / SEGMENTSIZE;
        
        if(py1 < tBgZero) py1 = tBgZero;
        if(tBg->getTileGIDAt(Vec2(px1, py1)) || tBg->getTileGIDAt(Vec2(px2, py1)))
        {
            return true;
        }
    }
    
    if(tRotate == en_Right)
    {
        px1 = tRotate == en_Right ? (getPositionX() + SEGMENTSIZE) / SEGMENTSIZE : (getPositionX() - SEGMENTSIZE) / SEGMENTSIZE ;
        py1 = tBgheight - (getPositionY() + SEGMENTSIZE / 2) / SEGMENTSIZE;
        py2 = tBgheight - (getPositionY() - SEGMENTSIZE / 2) / SEGMENTSIZE;

        if(px1 > tBgWidth) px1 = tBgWidth;
        if(tBg->getTileGIDAt(Vec2(px1, py2)) || tBg->getTileGIDAt(Vec2(px1, py1)))
        {
            return true;
        }
    }
    return false;
    
}


