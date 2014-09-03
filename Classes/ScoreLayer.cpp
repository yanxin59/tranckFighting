//
//  ScoreLayer.cpp
//  tranckFighting
//
//  Created by Yan on 14-9-2.
//
//

#include "ScoreLayer.h"

ScoreLayer::ScoreLayer():_score(0), _killEnemyCount(0), _enemyCount(0), _pEnemyCountLabel(nullptr), _pScoreLabel(nullptr), _pKillEnemyCountLabel(nullptr)
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
}


void ScoreLayer::registerScoreEvent()
{
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ScoreLayer::changeScore), "addScore", nullptr);
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(ScoreLayer::changeEnemyCount), "changeEnemyCount", nullptr);
}

void ScoreLayer::changeEnemyCount(cocos2d::Ref *pData)
{
    _enemyCount += *(reinterpret_cast<int*>(pData));
    _pEnemyCountLabel->setString(StringUtils::format("%d", _enemyCount));
}

void ScoreLayer::changeScore(cocos2d::Ref *pData)
{
    _score += *(reinterpret_cast<int*>(pData));
    _pScoreLabel->setString(StringUtils::format("%d", _score));
    
    _killEnemyCount += 1;
    _pKillEnemyCountLabel->setString(StringUtils::format("%d", _killEnemyCount));

}

void ScoreLayer::onEnter()
{
    Layer::onEnter();
    registerScoreEvent();
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
    
    _pScoreLabel = Label::createWithSystemFont("0", "Arial", 30);
    _pScoreLabel->setAnchorPoint(Vec2(0, 0.5));
    _pScoreLabel->setPosition(Vec2(tScoreTitle->getPositionX() + tScoreTitle->getContentSize().width / 2, tScoreTitle->getPositionY()));
    addChild(_pScoreLabel);
    _pScoreLabel->retain();
    
    auto tKillEnemyCountTitle = Label::createWithSystemFont("killEnemy:", "Arial", 30);
    tKillEnemyCountTitle->setPosition(Vec2(_pScoreLabel->getPositionX() + _pScoreLabel->getContentSize().width + tKillEnemyCountTitle->getContentSize().width, _pScoreLabel->getPositionY()));
    addChild(tKillEnemyCountTitle);
    
    
    _pKillEnemyCountLabel = Label::createWithSystemFont("0", "Arial", 30);
    _pKillEnemyCountLabel->setPosition(Vec2(tKillEnemyCountTitle->getPositionX() + tKillEnemyCountTitle->getContentSize().width / 2 , tKillEnemyCountTitle->getPositionY()));
    _pKillEnemyCountLabel->setAnchorPoint(Vec2(0, 0.5));
    addChild(_pKillEnemyCountLabel);
    _pKillEnemyCountLabel->retain();
    
    auto tEnemyCountTitle = Label::createWithSystemFont("EnmeyCount:", "Arial", 30);
    tEnemyCountTitle->setPosition(Vec2(_pKillEnemyCountLabel->getPositionX() + tEnemyCountTitle->getContentSize().width, _pKillEnemyCountLabel->getPositionY()));
    addChild(tEnemyCountTitle);
    
    _pEnemyCountLabel = Label::createWithSystemFont("0", "Arial", 30);
    _pEnemyCountLabel->setPosition(Vec2(tEnemyCountTitle->getPositionX() + tEnemyCountTitle->getContentSize().width / 2, tEnemyCountTitle->getPositionY()));
    _pEnemyCountLabel->setAnchorPoint(Vec2(0, 0.5));
    addChild(_pEnemyCountLabel);
    _pEnemyCountLabel->retain();
    
}


