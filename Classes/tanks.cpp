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
#include "config.h"
using namespace CocosDenshion;

tanks * tanks::instance = nullptr;

tanks * tanks::getInstance()
{
    if (!instance)
    {
        instance = tanks::create();
        instance->retain();
    }
    return instance;
}

void tanks::delInstance()
{
    if(instance) CC_SAFE_RELEASE_NULL(instance);
}

tanks::tanks()
{
    setbindSprite(Sprite::create("p1-a-cell.png"));
    this->addChild(getbindSprite());
    initTank();
}

void tanks::initTank()
{
    setRotation(en_Up);
    _tankSize = getbindSprite()->getContentSize();
    _tankState = en_NormalState;
    _tankLifeCount = 3;
    auto map = TMXTiledMap::create("mapNewer.tmx");
    auto playerPosValueMap = map->getObjectGroup("object")->getObject("player");
    _tankInitPos = Vec2(playerPosValueMap.at("x").asFloat(), playerPosValueMap.at("y").asFloat());
    setPosition(_tankInitPos);
}

void tanks::reset()
{
    setRotation(en_Up);
    _tankState = en_NormalState;
    _tankLifeCount = 3;
    setPosition(_tankInitPos);
}

void tanks::addFire(){
    
    auto bu = Bullet::create(getRotation(), getPosition(), 1);//创建子弹
    
    auto gamescene  =  dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());//通过导演得到运行中的场景
    
    auto layer = gamescene->getLayer();//通过运行的场景得到子弹层
    
    layer->addBullet(bu);//把子弹加到子弹层
    
    SimpleAudioEngine::getInstance()->playEffect("bullet.aif");
    
    //点击按钮,开火
}

void tanks::doDead()
{
    setIsDead(true);
    doAction();
    if(--_tankLifeCount == 0)
    {
        auto tSceneType = en_GameEndScene;
        NotificationCenter::getInstance()->postNotification("changeScene", reinterpret_cast<Ref *>(&tSceneType));
    }
}
void tanks::doAction()
{
    
    auto pBlink = Blink::create(1, 2);
    auto pCallFunc = CallFunc::create([this]()
    {
        this->setPosition(_tankInitPos);
        this->setRotation(en_Up);
        this->setIsDead(false);
    });
    runAction(Sequence::create(pBlink, pCallFunc, NULL));
}

Rect tanks::getBoundingBox()
{
    auto tCurPos = getPosition();//当前的位置
    return Rect(tCurPos.x - _tankSize.width / 2, tCurPos.y - _tankSize.height / 2, _tankSize.width, _tankSize.height);//返回一个矩形,当前位置和坦克尺寸
}

void tanks::up(){
    
    setPositionY(getPositionY()+TANK_SPEED);//一步一步移动
    Size s = Director::getInstance()->getVisibleSize();//屏幕尺寸

    if (getPositionY() >= (s.height - _tankSize.height/2))
    {
        setPositionY(s.height - _tankSize.height/2);
    }
    //如果坦克要出了上边界,就让它停留在上边界
}

void tanks::down()
{
    setPositionY(getPositionY()-TANK_SPEED);
    if (getPositionY() < _tankSize.height/2) {
        
        setPositionY(_tankSize.height/2);
    }
}
void tanks::left()
{
    setPositionX(getPositionX()-TANK_SPEED);
    if (getPositionX() < _tankSize.width/2) {
        setPositionX(_tankSize.width/2);
    }

}
void tanks::right()
{
    setPositionX(getPositionX()+TANK_SPEED);
    Size s = Director::getInstance()->getVisibleSize();
    if (getPositionX() >= (s.width-_tankSize.width/2 )) {
        setPositionX(s.width-_tankSize.width/2);
    }
}

void tanks::move(const Rotation &rRotation)
{
    setRotation(rRotation);
    if(judge()) return;
    SimpleAudioEngine::getInstance()->playEffect("move.aif");
    switch (rRotation) {
        case en_Up:
            up();
            break;
        case en_Right:
            right();
            break;
        case en_Down:
            down();
            break;
        case en_Left:
            left();
            break;
        default:
            break;
    }
}



bool tanks::judge()
{
    
    auto tMap = (dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene()))->getMap();
    auto tBg = tMap->m_bg;
    auto tIron = tMap->m_iron;
    
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
        if(py1 > tBgheight - 1) py1 = tBgheight - 1;
        if(tBg->getTileGIDAt(Vec2(px1, py1)) || tBg->getTileGIDAt(Vec2(px2, py1)) || tIron->getTileGIDAt(Vec2(px1, py1)) || tIron->getTileGIDAt(Vec2(px2, py1)))
        {
            return true;
        }
    }
    
    if(tRotate == en_Right || tRotate == en_Left)
    {
        px1 = tRotate == en_Right ? (getPositionX() + SEGMENTSIZE) / SEGMENTSIZE : (getPositionX() - SEGMENTSIZE) / SEGMENTSIZE ;
        py1 = tBgheight - (getPositionY() + SEGMENTSIZE / 2) / SEGMENTSIZE;
        py2 = tBgheight - (getPositionY() - SEGMENTSIZE / 2) / SEGMENTSIZE;

        if(px1 > tBgWidth - 1) px1 = tBgWidth - 1;
        if(px1 < tBgZero) px1 = tBgZero;
        if(tBg->getTileGIDAt(Vec2(px1, py2)) || tBg->getTileGIDAt(Vec2(px1, py1)) || tIron->getTileGIDAt(Vec2(px1, py2)) || tIron->getTileGIDAt(Vec2(px1, py1)))
        {
            return true;
        }
    }
    return false;    
}

void tanks::move()
{

}

