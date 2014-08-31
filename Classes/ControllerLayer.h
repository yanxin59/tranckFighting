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
    int _iLeft = 0 ;
    int _iUp = 0;
public:
    CREATE_FUNC(ControllerLayer);
    virtual void update(float t);
};
#endif /* defined(__tranckFighting__ControllerLayer__) */
