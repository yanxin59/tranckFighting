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

tanks * tanks::instance = nullptr;
tanks * tanks::getInstance()
{
    if (!instance) {
        instance = tanks::create();
        instance->setPosition(100, 50);

    }
     return instance;
}
void tanks::addFire(){
    
    auto bu = Bullet::create(_pTank->getRotation(), getPosition(), 1);//创建子弹
    
    auto gamescene  =  dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene());//通过导演得到运行中的场景
    
 
    auto layer = gamescene->getLayer();//通过运行的场景得到子弹层
    
    
    layer->addBullet(bu);//把子弹加到子弹层
    
    //点击按钮,开火
}

void tanks::mineTankDie(){
    
    
    
    
}

Rect tanks::getBoundingBox()
{
    auto tCurPos = getPosition();//当前的位置
    auto tSize = _pTank->getContentSize();//坦克的尺寸
    return Rect(tCurPos.x - tSize.width / 2, tCurPos.y - tSize.height / 2, tSize.width, tSize.height);//返回一个矩形,当前位置和坦克尺寸
}

void tanks::up(){
    
    _pTank->setRotation(0);//角度为0,方向朝上
    
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
    _pTank->setRotation(180);
    if(judge())
        return ;

    setPositionY(getPositionY()-1);
    Size  sSize = _pTank->getContentSize();
    if (getPositionY() < sSize.height/2) {
        
        setPositionY(sSize.height/2);
    }
}
void tanks::left(){
 
    _pTank->setRotation(270);
    if(judge())
        return ;

    setPositionX(getPositionX()-1);
    Size sSize = _pTank->getContentSize();
    if (getPositionX() < sSize.width/2) {
        setPositionX(sSize.width/2);
    }

}
void tanks::right(){

    _pTank->setRotation(90);
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
    
    auto tBg = (dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene()))->getMap()->m_bg;
    
    auto tRotate = _pTank->getRotation();
    
    auto tTankwidth = _pTank->getContentSize().width / 2;
    
    auto tBgheight = tBg->getLayerSize().height;
    
    auto px1 = 0;
    auto px2 = 0;
    auto px3 = 0;
    
    auto py1 = 0;
    auto py2 = 0;
    auto py3 = 0;
    
    if(tRotate == 0.0f)
    {
        py1 = tBgheight - (getPositionY() + tTankwidth + 8) / 16;
        px1 = getPositionX() / 16;
        px2 = (getPositionX() + tTankwidth / 2) / 16;
        px3 = (getPositionX() - tTankwidth / 2) / 16;
        
        
        if(tBg->getTileGIDAt(Vec2(px1, py1)) || tBg->getTileGIDAt(Vec2(px2, py1)) || tBg->getTileGIDAt(Vec2(px3, py1)))
        {
            return true;
        }
    }
    
    if(tRotate == 90.0f)
    {
        px1 = (getPositionX() + tTankwidth + 8) / 16;
        py1 = tBgheight - getPositionY() / 16;
        py2 = tBgheight - (getPositionY() - tTankwidth / 2) / 16;
        py3 = tBgheight - (getPositionY() + tTankwidth / 2) / 16;
        if(px1 > 39.0f) px1 = 39.0f;
        if(py2 > 59.0f) py2 = 59.0f;
        if(py3 < 0.0f) py3 = 0.0f;
        if(tBg->getTileGIDAt(Vec2(px1, py2)) || tBg->getTileGIDAt(Vec2(px1, py1)) || tBg->getTileGIDAt(Vec2(px1, py3)))
        {
            return true;
        }
        
    }
    
    if(tRotate == 180.0f)
    {
        py1 = tBgheight - (getPositionY() - tTankwidth - 8) / 16;
        px1 = getPositionX() / 16;
        px2 = (getPositionX() - tTankwidth / 2) / 16;
        px3 = (getPositionX() + tTankwidth / 2) / 16;
        
        if(py1 > 39.0f) py1 = 39.0f;
        if(px3 < 0.0f) px3 = 0.0f;
        if(px2 > 59.0f) px2 = 59.0f;
        
        
        if(tBg->getTileGIDAt(Vec2(px1, py1)) || tBg->getTileGIDAt(Vec2(px2, py1)) || tBg->getTileGIDAt(Vec2(px3, py1)))
        {
            return true;
        }
    }
    
    if(tRotate == 270.0f)
    {
        px1 = (getPositionX() - tTankwidth - 8) / 16;
        py1 = tBgheight - getPositionY() / 16;
        py2 = tBgheight - (getPositionY() - tTankwidth / 2) / 16;
        py3 = tBgheight - (getPositionY() + tTankwidth / 2) / 16;
        
        if(px1 < 0.0f) px1 = 0.0f;
        if(py2 > 59.0f) py2 = 59.0f;
        if(py3 < 0.0f) py3 = 0.0f;
        
        if(tBg->getTileGIDAt(Vec2(px1, py2)) || tBg->getTileGIDAt(Vec2(px1, py1)) || tBg->getTileGIDAt(Vec2(px1, py3)))
        {
            return true;
        }
    }
    
    return false;
    
    /*
    auto tBg = (dynamic_cast<GameScene *>(Director::getInstance()->getRunningScene()))->getMap()->m_bg;//砖块障碍物
    
    auto tRotate = _pTank->getRotation();//坦克的角度
    
    auto px = 0;//障碍物位置 X 坐标初始值是0
    
    auto py = 0;//障碍物位置 Y 坐标初始值是0
    
    auto pxleft = 0;
    
    auto pyleft = 0;
    
    auto pxright = 0;
    
    auto pyright = 0;
    
    if(tRotate == 0.0f)
    {
        py = (getPositionY() + _pTank->getContentSize().height / 2 + 16) / 16;
        
        px = getPositionX() / 16;
    //如果坦克角度是0°,要判断的点的 Y 是:单例的 Y坐标+坦克 身体的一半+一块儿小砖块的高度,除以16是转换成小砖块的相对坐标
        
        pyleft =(getPositionY() + _pTank->getContentSize().height / 2 + 16) / 16;
        
        pyright = (getPositionY() + _pTank->getContentSize().height / 2 + 16) / 16;
        
        pxright = (getPositionX()-_pTank->getContentSize().width/4)/16;
        
        pxleft =(getPositionX()+_pTank->getContentSize().width/4)/16;
        
    }
    if(tRotate == 90.0f)
    {
        py = getPositionY() / 16;
        
        px = (getPositionX() + _pTank->getContentSize().width / 2 + 16) / 16;
        
        pxleft = (getPositionX() + _pTank->getContentSize().width / 2 + 16) / 16;
        
        pxright = (getPositionX() + _pTank->getContentSize().width / 2 + 16) / 16;
        
        pyleft = (getPositionY() + _pTank->getContentSize().height/4)/16;
        
        pyright = (getPositionY() - _pTank->getContentSize().height/4)/16;
        
    
    }
    
    if(tRotate == 180.0f)
    {
        py = (getPositionY() - (_pTank->getContentSize().height / 2 + 16)) / 16;
        
        px = getPositionX() / 16;
        
        pxleft = (getPositionX()-_pTank->getContentSize().width/4)/16;
        
        pxright =(getPositionX()+_pTank->getContentSize().width/4)/16;
        
        pyleft =(getPositionY() - _pTank->getContentSize().height / 2 + 16) / 16;
        
        pyright = (getPositionY() - _pTank->getContentSize().height / 2 + 16) / 16;

        
        
    }
    
    if(tRotate == 270.0f)
    {
        py = getPositionY() / 16;
        
        px = (getPositionX() - _pTank->getContentSize().width / 2 + 16 )/ 16;
        
        pxleft = (getPositionX()-_pTank->getContentSize().width/4)/16;
        
        pxright =(getPositionX()+_pTank->getContentSize().width/4)/16;
        
        pyleft =( getPositionY()-_pTank->getContentSize().height/4)/16;
        
        pyright =( getPositionY()+_pTank->getContentSize().height/4)/16;

    }
    
    if(px >= 59.0f)
    {
        px = 59.0f;
    }
    
    if(py >= 39.0f)
    {
        py = 39.0f;
    }
    if(pxleft >= 59.0f)
    {
        pxleft = 59.0f;
    }
    
    if(pyleft >= 39.0f)
    {
        pyleft = 39.0f;
    }
    if(pxright >= 59.0f)
    {
        pxright = 59.0f;
    }
    
    if(pyright >= 39.0f)
    {
        pyright = 39.0f;
    }


    
    if(tBg->getTileGIDAt(Vec2(px - 1, 40 - py - 1)))
    {
        return true;
    }
    if(tBg->getTileGIDAt(Vec2(pxleft - 1, 40 - pyleft - 1)))
    {
        return true;
    }

    if(tBg->getTileGIDAt(Vec2(pxright - 1, 40 - pyright - 1)))
    {
        return true;
    }
*/
    
//    return false;
}


