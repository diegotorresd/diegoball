//
//  Border.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "Border.hpp"
#include "Categories.hpp"
USING_NS_CC;

Node* Border::create(Size visibleSize) {
    auto pb_border = PhysicsBody::createEdgeBox(visibleSize, PhysicsMaterial(0.1f, 1.0f, 0.01f));
    auto border = Node::create();
    border->setAnchorPoint(Vec2(0, 0));
    border->setPosition(visibleSize / 2.0);
    pb_border->setDynamic(false);
    pb_border->setCategoryBitmask(Categories::WALL);
    pb_border->setCollisionBitmask(Categories::BALL | Categories::PADDLE);
    border->addComponent(pb_border);
    return border;
}
