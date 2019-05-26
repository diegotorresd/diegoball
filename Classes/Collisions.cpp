//
//  Collisions.cpp
//  DiegoBall
//
//  Created by Diego Torres on 26/05/2019.
//

#include "Collisions.hpp"
#include "Categories.hpp"
USING_NS_CC;

bool Collisions::isBallWithBottom(PhysicsBody* bodyA, PhysicsBody* bodyB, Vec2 collisionPoint) {
    return (bodyA->getTag() == Categories::BALL
            && bodyB->getTag() == Categories::WALL
            && collisionPoint.y <= 1.0f);
}

bool Collisions::isBallWithBrick(PhysicsBody* bodyA, PhysicsBody* bodyB) {
    return (bodyA->getTag() == Categories::BALL
            && bodyB->getTag() == Categories::BRICK);
}
