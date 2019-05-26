//
//  BrickWall.cpp
//  DiegoBall
//
//  Created by Diego Torres on 26/05/2019.
//

#include "BrickWall.hpp"
#include "Brick.hpp"
USING_NS_CC;

Node* BrickWall::create() {
    auto node = Node::create();
    for (int i = 0; i < 9; i++) {
        auto brick = Brick::create(i % 5);
        brick->setPosition(Vec2(112 + 32*i, 200));
        node->addChild(brick);
    }
    return node;
}
