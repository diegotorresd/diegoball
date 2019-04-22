//
//  MainScene.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "MainScene.hpp"
#include "Paddle.hpp"

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

bool MainScene::init() {
    if (!Scene::initWithPhysics()) return false;
    getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    auto paddle = Paddle::create();
    addChild(paddle);
    
    auto paddleListener = Paddle::createTouchListener(paddle);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(paddleListener, this);
    
    return true;
}
