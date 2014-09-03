//
//  EnemyLayer.h
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#ifndef __tranckFighting__EnemyLayer__
#define __tranckFighting__EnemyLayer__
#include "cocos2d.h"
using namespace cocos2d;
class EnemyLayer:public Layer{
    
protected:
    
    virtual void onExit()override;
    
public:
    
	virtual bool init();
    
	CREATE_FUNC(EnemyLayer);
    
	void createEnemy();  //层中生成坦克方法
    
};
#endif /* defined(__tranckFighting__EnemyLayer__) */
