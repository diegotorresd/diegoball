//
//  Brick.cpp
//  DiegoBall
//
//  Created by Diego Torres on 26/05/2019.
//

#include "Brick.hpp"
#include "Categories.hpp"
USING_NS_CC;

Node* Brick::create() {
    auto brick = Sprite::create("brick0.png");
    brick->setPosition(Vec2(240, 200));
    auto pb_brick = PhysicsBody::createBox(brick->getBoundingBox().size, PhysicsMaterial(0.1f, 1.0f, 0.01f));
    brick->setPhysicsBody(pb_brick);
    pb_brick->setDynamic(false);
    pb_brick->setTag(Categories::BRICK);
    pb_brick->setContactTestBitmask(Categories::BALL);
    return brick;
}
