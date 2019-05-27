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
#include "RandomNumber.hpp"
#include <cmath>
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

Node* paddle;
Node* ball;
Node* brickWall;
GameState* gameState;
Label* livesText;

SimpleAudioEngine* audio;

bool MainScene::init() {
    if (!Scene::initWithPhysics()) return false;
    audio = SimpleAudioEngine::getInstance();
    gameState = new GameState();
    getPhysicsWorld()->setGravity(Vec2(0.0f, -1.5f));
    
    paddle = Paddle::create();
    addChild(paddle);
    
    ball = Ball::create(paddle->getPosition());
    addChild(ball);
    
    brickWall = BrickWall::create(gameState->getNumBricks());
    addChild(brickWall);
    
    livesText = Label::createWithSystemFont(std::to_string(gameState->getLives()), "Arial", 18);
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
        float impulse = 3500;
        float angle = RandomNumber::generate(1.0472, 2.0944);
        ball->getPhysicsBody()->applyImpulse(Vec2(impulse * cos(angle), impulse * sin(angle)));
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
        if (numLives == 0) {
            // return to initial scene
            Director::getInstance()->replaceScene(InitialScene::createScene());
            return false;
        }
        livesText->setString(std::to_string(numLives));
        audio->playEffect("error.wav");
        resetGame();
        return true;
    }
    if (Collisions::isBallWithBrick(bodyA, bodyB)) {
        // remove brick
        bodyB->getNode()->removeFromParentAndCleanup(true);
        gameState->decreaseNumBricks();
        int numBricks = gameState->getNumBricks();
        if (numBricks % 5 == 0) {
            auto move = MoveBy::create(0.5f, Vec2(0, -15));
            brickWall->runAction(move);
        }
        if (numBricks <= 0) {
            // return to initial scene
            Director::getInstance()->replaceScene(InitialScene::createScene());
            return false;
        }
        audio->playEffect("correct.mp3");
        return true;
    }
    if (Collisions::isBallWithPaddle(bodyA, bodyB) && gameState->isBallFree() == true) {
        audio->playEffect("thump.wav");
        return true;
    }
    return true;
}

void MainScene::resetGame() {
    paddle->setPosition(240, 10);
    ball->removeFromParentAndCleanup(true);
    auto fadeIn = FadeTo::create(1.0f, 255);
    auto fadeOut = FadeTo::create(1.0f, 1);
    auto callback = CallFunc::create([&]() {
        ball = Ball::create(paddle->getPosition());
        addChild(ball);
        gameState->setBallFree(false);
    });
    auto seq = Sequence::create(fadeOut, fadeIn, callback, NULL);
    brickWall->runAction(seq);
}
