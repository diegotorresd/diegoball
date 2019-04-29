//
//  Ball.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "Ball.hpp"
USING_NS_CC;

Node* Ball::create() {
    auto ball = Sprite::create("ball.png");
    ball->setPosition(240, 20);
    auto pb_ball = PhysicsBody::createCircle(6);
    ball->addComponent(pb_ball);
    return ball;
}
