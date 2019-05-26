//
//  Collisions.hpp
//  DiegoBall
//
//  Created by Diego Torres on 26/05/2019.
//

#ifndef Collisions_hpp
#define Collisions_hpp

#include "cocos2d.h"
class Collisions {
public:
    static bool isBallWithBottom(cocos2d::PhysicsBody* bodyA, cocos2d::PhysicsBody* bodyB, cocos2d::Vec2 collisionPoint);
    static bool isBallWithBrick(cocos2d::PhysicsBody* bodyA, cocos2d::PhysicsBody* bodyB);
};

#endif /* Collisions_hpp */
