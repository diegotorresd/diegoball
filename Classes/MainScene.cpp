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
#include "GameState.hpp"

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

Node* paddle;
Node* ball;
GameState* gameState;

bool MainScene::init() {
    if (!Scene::initWithPhysics()) return false;
    gameState = new GameState();
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
    if (gameState->isBallFree() == true) return;
    auto currentPos = ball->getPosition();
    ball->setPosition(Vec2(pos.x, currentPos.y));
}

void MainScene::paddleMoveEnd(float amount) {
    if (gameState->isBallFree() == false) {
        log("move %f", amount);
        ball->getPhysicsBody()->applyImpulse(Vec2(2000, 2000));
        gameState->setBallFree(true);
    }
}

GameState* getGameState() {
    return gameState;
}
