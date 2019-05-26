//
//  Ball.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "Ball.hpp"
#include "Categories.hpp"
USING_NS_CC;

Node* Ball::create() {
    auto ball = Sprite::create("ball.png");
    ball->setPosition(240, 20);
    auto pb_ball = PhysicsBody::createCircle(6, PhysicsMaterial(0.1f, 1.0f, 0.01f));
    pb_ball->setCategoryBitmask(Categories::BALL);
    pb_ball->setCollisionBitmask(Categories::PADDLE | Categories::WALL | Categories::BRICK);
    ball->addComponent(pb_ball);
    return ball;
}
