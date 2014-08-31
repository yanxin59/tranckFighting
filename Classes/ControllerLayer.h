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
<<<<<<< HEAD
    
    Vec2 tankPosition;
    
=======
    int _iLeft = 0 ;
    int _iUp = 0;
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
public:
    CREATE_FUNC(ControllerLayer);
<<<<<<< HEAD
    
    CC_SYNTHESIZE(std::function<void ()>, up, Up);
    
    CC_SYNTHESIZE(std::function<void ()>, down, Down);
    
    CC_SYNTHESIZE(std::function<void ()>, left, Left);
    
    CC_SYNTHESIZE(std::function<void ()>, right, Right);
    
    
    
    
=======
    virtual void update(float t);
>>>>>>> 79abac176493eb5d0a984516b4392662cec1313d
};
#endif /* defined(__tranckFighting__ControllerLayer__) */
