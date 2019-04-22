//
//  Border.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "Border.hpp"
USING_NS_CC;

Node* Border::create(Size visibleSize) {
    auto pb_border = PhysicsBody::createEdgeBox(visibleSize);
    auto border = Node::create();
    border->setAnchorPoint(Vec2(0, 0));
    border->setPosition(visibleSize / 2.0);
    pb_border->setDynamic(false);
    border->addComponent(pb_border);
    return border;
}
