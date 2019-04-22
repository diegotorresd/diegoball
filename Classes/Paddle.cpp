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
    auto pb_paddle = PhysicsBody::createBox(paddle->getBoundingBox().size);
    paddle->addComponent(pb_paddle);
    return paddle;
}

EventListener* Paddle::createTouchListener(Node* paddle) {
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    listener1->onTouchBegan = [=](Touch* touch, Event* event) {
        return true;
    };
    
    listener1->onTouchMoved = [=](Touch* touch, Event* event){
        auto d = touch->getDelta();
        auto pos = paddle->getPosition();
        float x = pos.x + d.x;
        /// TODO: extract position constants
        x = MAX(40, x);
        x = MIN(x, 440);
        paddle->setPosition(Vec2(x, pos.y));
        return true;
    };
    
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        return true;
    };
    
    return listener1;
}
