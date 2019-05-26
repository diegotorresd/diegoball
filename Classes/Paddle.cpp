//
//  Paddle.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "Paddle.hpp"
#include "Categories.hpp"
USING_NS_CC;

Node* Paddle::create() {
    auto paddle = Sprite::create("paddle.png");
    paddle->setPosition(Vec2(240, 10));
    auto pb_paddle = PhysicsBody::createBox(paddle->getBoundingBox().size, PhysicsMaterial(0.1f, 1.0f, 0.01f));
    pb_paddle->setDynamic(false);
    //pb_paddle->setGravityEnable(true);
    pb_paddle->setCategoryBitmask(Categories::PADDLE);
    pb_paddle->setCollisionBitmask(Categories::BALL | Categories::WALL);
    paddle->addComponent(pb_paddle);
    return paddle;
}

EventListener* Paddle::createTouchListener(Node* paddle, MainScene* scene) {
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
        auto newPos = Vec2(x, pos.y);
        paddle->getPhysicsBody()->setVelocity(Vec2::ZERO);
        paddle->setPosition(newPos);
        scene->paddleMoved(newPos);
        return true;
    };
    
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        scene->paddleMoveEnd(0.5f);
        return true;
    };
    
    return listener1;
}
