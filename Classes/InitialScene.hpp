//
//  InitialScene.hpp
//  DiegoBall
//
//  Created by Diego Torres on 26/05/2019.
//

#ifndef InitialScene_hpp
#define InitialScene_hpp

#include "cocos2d.h"

class InitialScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(InitialScene);
};

#endif /* InitialScene_hpp */
