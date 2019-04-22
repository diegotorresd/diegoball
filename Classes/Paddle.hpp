//
//  Paddle.hpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#ifndef Paddle_hpp
#define Paddle_hpp

#include "cocos2d.h"
class Paddle {
public:
    static cocos2d::Node* create();
    static cocos2d::EventListener* createTouchListener(cocos2d::Node* paddle);
};
#endif /* Paddle_hpp */
