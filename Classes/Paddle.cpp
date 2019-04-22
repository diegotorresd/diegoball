//
//  Paddle.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "Paddle.hpp"
USING_NS_CC;

Node* Paddle::create() {
    auto paddle = Sprite::create("paddle.png");
    paddle->setPosition(Vec2(240, 10));
    return paddle;
}
