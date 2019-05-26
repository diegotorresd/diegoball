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
#include "Brick.hpp"
#include "Collisions.hpp"

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

Node* paddle;
Node* ball;
Node* brick;
GameState* gameState;

bool MainScene::init() {
    if (!Scene::initWithPhysics()) return false;
    gameState = new GameState();
    getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    getPhysicsWorld()->setGravity(Vec2(0.0f, -0.5f));
    
    paddle = Paddle::create();
    addChild(paddle);
    
    ball = Ball::create();
    addChild(ball);
    
    brick = Brick::create();
    addChild(brick);
    
    auto paddleListener = Paddle::createTouchListener(paddle, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(paddleListener, this);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto border = Border::create(visibleSize);
    
    addChild(border);
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(MainScene::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    
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
        ball->getPhysicsBody()->applyImpulse(Vec2(3000, 3000));
        gameState->setBallFree(true);
    }
}

GameState* getGameState() {
    return gameState;
}

bool MainScene::onContactBegin(PhysicsContact& contact) {
    auto bodyA = contact.getShapeA()->getBody();
    auto bodyB = contact.getShapeB()->getBody();
    auto points = contact.getContactData()->points;
    if (Collisions::isBallWithBottom(bodyA, bodyB, points[0])) {
        log("Bottom!");
    }
    return true;
}
