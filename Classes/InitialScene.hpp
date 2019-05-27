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
    enum class SceneType : int {
        NORMAL = 0,
        GAME_OVER = 1,
        YOU_WIN = 2
    };
    static cocos2d::Scene* createScene(SceneType sceneType);
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(InitialScene);
};

#endif /* InitialScene_hpp */
