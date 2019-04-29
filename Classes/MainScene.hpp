//
//  MainScene.hpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include "cocos2d.h"

class MainScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    
    // paddle callbacks
    void paddleMoved(cocos2d::Vec2 pos);
    void paddleMoveEnd(float amount);
};

#endif /* MainScene_hpp */
