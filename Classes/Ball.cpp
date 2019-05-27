//
//  Ball.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "Ball.hpp"
#include "Categories.hpp"
USING_NS_CC;

Node* Ball::create(Vec2 paddlePos) {
    auto ball = Sprite::create("ball.png");
    ball->setPosition(paddlePos + Vec2(0, 10));
    auto pb_ball = PhysicsBody::createCircle(6, PhysicsMaterial(0.1f, 1.0f, 0.01f));
    pb_ball->setTag(Categories::BALL);
    pb_ball->setCategoryBitmask(Categories::BALL);
    pb_ball->setCollisionBitmask(Categories::PADDLE | Categories::WALL | Categories::BRICK);
    pb_ball->setContactTestBitmask(Categories::PADDLE | Categories::WALL | Categories::BRICK);
    ball->addComponent(pb_ball);
    return ball;
}
