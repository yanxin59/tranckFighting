//
//  ScoreLayer.h
//  tranckFighting
//
//  Created by Yan on 14-9-2.
//
//

#ifndef __tranckFighting__ScoreLayer__
#define __tranckFighting__ScoreLayer__

#include "cocos2d.h"

using namespace cocos2d;

class ScoreLayer: public Layer
{
public:
    
    CREATE_FUNC(ScoreLayer);
    
    virtual ~ScoreLayer();
    
protected:
    
    virtual bool init();
    
    virtual void registerScoreEvent();
    
    virtual void onEnter()override;
    
    virtual void onExit()override;
    
    virtual void changeScore(Ref *pData);
    
    virtual void changeEnemyCount(Ref *pData);
    
    virtual void changeTankLifeCount(Ref *pData);
    
    virtual void loadLabel();
    
    virtual void initData();
    
private:
    
    int _score;
    
    int _enemyCount;
    
    int _killEnemyCount;
    
    int _tankLifeCount;
    
    Label *_pScoreLabel;
    
    Label *_pEnemyCountLabel;
    
    Label *_pKillEnemyCountLabel;
    
    Label *_pTankLifeCountLabel;
private:
    
    ScoreLayer();
};

#endif /* defined(__tranckFighting__ScoreLayer__) */
