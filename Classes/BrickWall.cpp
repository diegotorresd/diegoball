//
//  BrickWall.cpp
//  DiegoBall
//
//  Created by Diego Torres on 26/05/2019.
//

#include "BrickWall.hpp"
#include "Brick.hpp"
USING_NS_CC;

Node* BrickWall::create(int numBricks) {
    int w = 32; // px
    int h = 16; // px
    int n = 11; // bricks per row
    float left = (480 - w * (n - 1)) / 2;
    float top = 260;
    auto node = Node::create();
    node->setCascadeOpacityEnabled(true);
    for (int i = 0; i < numBricks; i++) {
        auto brick = Brick::create(i % 5);
        int row = i % n;
        int col = i / n;
        float dl = (col % 2) * (w / 2);
        brick->setPosition(Vec2(left + dl + w * row, top - h * col));
        brick->setCascadeOpacityEnabled(true);
        node->addChild(brick);
    }
    return node;
}
