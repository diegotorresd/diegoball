//
//  MainScene.cpp
//  DiegoBall
//
//  Created by Diego Torres on 22/04/2019.
//

#include "MainScene.hpp"
#include "InitialScene.hpp"
#include "Paddle.hpp"
#include "Border.hpp"
#include "Ball.hpp"
#include "GameState.hpp"
#include "BrickWall.hpp"
#include "Collisions.hpp"
#include <stdio.h>

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

Node* paddle;
Node* ball;
Node* brickWall;
GameState* gameState;
Label* livesText;

bool MainScene::init() {
    if (!Scene::initWithPhysics()) return false;
    gameState = new GameState();
    getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    getPhysicsWorld()->setGravity(Vec2(0.0f, -0.5f));
    
    paddle = Paddle::create();
    addChild(paddle);
    
    ball = Ball::create();
    addChild(ball);
    
    brickWall = BrickWall::create(gameState->getNumBricks());
    addChild(brickWall);
    
    livesText = Label::createWithSystemFont("3", "Arial", 18);
    livesText->setColor(Color3B::ORANGE);
    livesText->setPosition(460, 300);
    addChild(livesText);
    
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
        gameState->decreaseLives();
        int numLives = gameState->getLives();
        if (numLives <= 0) {
            // return to initial scene
            Director::getInstance()->replaceScene(InitialScene::createScene());
            return false;
        }
        livesText->setString(std::to_string(numLives));
        resetGame();
    }
    if (Collisions::isBallWithBrick(bodyA, bodyB)) {
        // remove brick
        bodyB->getNode()->removeFromParentAndCleanup(true);
        gameState->decreaseNumBricks();
        if (gameState->getNumBricks() <= 0) {
            // return to initial scene
            Director::getInstance()->replaceScene(InitialScene::createScene());
            return false;
        }
    }
    return true;
}

void MainScene::resetGame() {
    paddle->setPosition(240, 10);
    ball->removeFromParentAndCleanup(true);
    ball = Ball::create();
    addChild(ball);
    gameState->setBallFree(false);
}
