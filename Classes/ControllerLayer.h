//
//  ControllerLayer.h
//  tranckFighting
//
//  Created by Yan on 14-8-29.
//
//

#ifndef __tranckFighting__ControllerLayer__
#define __tranckFighting__ControllerLayer__
#include "cocos2d.h"
using namespace cocos2d;
class ControllerLayer:public Layer{
    
    
protected:
    
    virtual bool init();
    

    Vec2 tankPosition;
    
public:
    
    CREATE_FUNC(ControllerLayer);
    
    CC_SYNTHESIZE(std::function<void ()>, up, Up);
    
    CC_SYNTHESIZE(std::function<void ()>, down, Down);
    
    CC_SYNTHESIZE(std::function<void ()>, left, Left);
    
    CC_SYNTHESIZE(std::function<void ()>, right, Right);
    

    
};





#endif /* defined(__tranckFighting__ControllerLayer__) */
