//
//  ScoreLayer.cpp
//  tranckFighting
//
//  Created by Yan on 14-9-2.
//
//

#include "ScoreLayer.h"
#include "tanks.h"

ScoreLayer::ScoreLayer():_score(0), _killEnemyCount(0), _enemyCount(0), _tankLifeCount(0), _pTankLifeCountLabel(nullptr), _pEnemyCountLabel(nullptr), _pScoreLabel(nullptr), _pKillEnemyCountLabel(nullptr)
{
}

bool ScoreLayer::init()
{
    bool bRet = false;
    
    do
    {
        CC_BREAK_IF(!Layer::init());

        bRet = true;
    }
    while (0);
    
    return bRet;
}

ScoreLayer::~ScoreLayer()
{
    CC_SAFE_RELEASE_NULL(_pEnemyCountLabel);
    CC_SAFE_RELEASE_NULL(_pKillEnemyCountLabel);
    CC_SAFE_RELEASE_NULL(_pScoreLabel);
    CC_SAFE_RELEASE_NULL(_pTankLifeCountLabel);
}


void ScoreLayer::registerScoreEvent()
{
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ScoreLayer::changeScore), "addScore", nullptr);
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ScoreLayer::changeEnemyCount), "changeEnemyCount", nullptr);
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ScoreLayer::changeTankLifeCount), "changeTankLifeCount", nullptr);
}

void ScoreLayer::changeEnemyCount(Ref *pData)
{
    if(pData)
        _enemyCount = *(reinterpret_cast<int*>(pData));
    else
        --_enemyCount;
    _pEnemyCountLabel->setString(StringUtils::format("%d", _enemyCount));
}

void ScoreLayer::changeScore(Ref *pData)
{
    _score += *(reinterpret_cast<int*>(pData));
    _pScoreLabel->setString(StringUtils::format("%d", _score));
    
    _pKillEnemyCountLabel->setString(StringUtils::format("%d", ++_killEnemyCount));

}

void ScoreLayer::changeTankLifeCount(Ref *pData)
{
    _pTankLifeCountLabel->setString(StringUtils::format("%d", --_tankLifeCount));
}

void ScoreLayer::onEnter()
{
    Layer::onEnter();
    registerScoreEvent();
    initData();
    loadLabel();
}

void ScoreLayer::onExit()
{
    Layer::onExit();
    NotificationCenter::getInstance()->removeAllObservers(this);
}

void ScoreLayer::loadLabel()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto tScoreTitle = Label::createWithSystemFont("Score:", "Arial", 30);
    tScoreTitle->setPosition(Vec2(tScoreTitle->getContentSize().width / 2, visibleSize.height - tScoreTitle->getContentSize().height));
    addChild(tScoreTitle);
    
    _pScoreLabel = Label::createWithSystemFont(StringUtils::format("%d", _score), "Arial", 30);
    _pScoreLabel->setAnchorPoint(Vec2(0, 0.5));
    _pScoreLabel->setPosition(Vec2(tScoreTitle->getPositionX() + tScoreTitle->getContentSize().width / 2, tScoreTitle->getPositionY()));
    addChild(_pScoreLabel);
    _pScoreLabel->retain();
    
    auto tKillEnemyCountTitle = Label::createWithSystemFont("killEnemy:", "Arial", 30);
    tKillEnemyCountTitle->setPosition(Vec2(_pScoreLabel->getPositionX() + _pScoreLabel->getContentSize().width + tKillEnemyCountTitle->getContentSize().width, _pScoreLabel->getPositionY()));
    addChild(tKillEnemyCountTitle);
    
    
    _pKillEnemyCountLabel = Label::createWithSystemFont(StringUtils::format("%d", _killEnemyCount), "Arial", 30);
    _pKillEnemyCountLabel->setPosition(Vec2(tKillEnemyCountTitle->getPositionX() + tKillEnemyCountTitle->getContentSize().width / 2 , tKillEnemyCountTitle->getPositionY()));
    _pKillEnemyCountLabel->setAnchorPoint(Vec2(0, 0.5));
    addChild(_pKillEnemyCountLabel);
    _pKillEnemyCountLabel->retain();
    
    auto tEnemyCountTitle = Label::createWithSystemFont("EnmeyCount:", "Arial", 30);
    tEnemyCountTitle->setPosition(Vec2(_pKillEnemyCountLabel->getPositionX() + tEnemyCountTitle->getContentSize().width, _pKillEnemyCountLabel->getPositionY()));
    addChild(tEnemyCountTitle);
    
    _pEnemyCountLabel = Label::createWithSystemFont(StringUtils::format("%d", _enemyCount), "Arial", 30);
    _pEnemyCountLabel->setPosition(Vec2(tEnemyCountTitle->getPositionX() + tEnemyCountTitle->getContentSize().width / 2, tEnemyCountTitle->getPositionY()));
    _pEnemyCountLabel->setAnchorPoint(Vec2(0, 0.5));
    addChild(_pEnemyCountLabel);
    _pEnemyCountLabel->retain();
    
    auto tTankLifeCountTitle = Label::createWithSystemFont("Tank:", "Arial", 30);
    tTankLifeCountTitle->setPosition(Vec2(_pEnemyCountLabel->getPositionX() + tTankLifeCountTitle->getContentSize().width + 60, _pEnemyCountLabel->getPositionY()));
    addChild(tTankLifeCountTitle);
    
    _pTankLifeCountLabel = Label::createWithSystemFont(StringUtils::format("%d", _tankLifeCount), "Arial", 30);
    _pTankLifeCountLabel->setAnchorPoint(Vec2(0, 0.5));
    _pTankLifeCountLabel->setPosition(Vec2(tTankLifeCountTitle->getPositionX() + tTankLifeCountTitle->getContentSize().width / 2, tTankLifeCountTitle->getPositionY()));
    addChild(_pTankLifeCountLabel);
    _pTankLifeCountLabel->retain();
    
}

void ScoreLayer::initData()
{
    _tankLifeCount = tanks::getInstance()->getTankLifeCount();
}


