//
//  MainScene.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "MainScene.hpp"
#include "Paddle.hpp"
#include "Border.hpp"
#include "Ball.hpp"

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

Node* paddle;
Node* ball;

bool MainScene::init() {
    if (!Scene::initWithPhysics()) return false;
    getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    paddle = Paddle::create();
    addChild(paddle);
    
    ball = Ball::create();
    addChild(ball);
    
    auto paddleListener = Paddle::createTouchListener(paddle, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(paddleListener, this);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto border = Border::create(visibleSize);
    addChild(border);
    
    return true;
}

void MainScene::paddleMoved(Vec2 pos) {
    auto currentPos = ball->getPosition();
    ball->setPosition(Vec2(pos.x, currentPos.y));
}

void MainScene::paddleMoveEnd(float amount) {
    log("move %f", amount);
}
