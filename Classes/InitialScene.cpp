//
//  InitialScene.cpp
//  DiegoBall
//
//  Created by Diego Torres on 26/05/2019.
//

#include "InitialScene.hpp"
#include "MainScene.hpp"
USING_NS_CC;
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;

Scene* InitialScene::createScene(SceneType sceneType) {
    auto scene = InitialScene::create();
    scene->setSceneType(sceneType);
    return scene;
}

bool InitialScene::init() {
    if (!Scene::init()) {
        return false;
    }
    auto title = Label::createWithSystemFont("DiegoBall", "Arial", 48);
    title->setPosition(240, 180);
    addChild(title);
    
    auto newGame = Button::create("NewGame.png", "NewGame.png", "NewGame.png");
    newGame->setPosition(Vec2(240, 120));
    newGame->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        if (type == Widget::TouchEventType::ENDED) {
            auto director = Director::getInstance();
            director->replaceScene(MainScene::createScene());
        }
    });
    addChild(newGame);
    /*if (_sceneType == SceneType::NORMAL) {
        return true;
    }*/
    
    return true;
}

void InitialScene::setSceneType(SceneType sceneType) {
    log("set scene type %d", sceneType);
    _sceneType = sceneType;
    log("Scene type: %d", _sceneType);
    if (_sceneType == SceneType::NORMAL) return;
    bool isWin = _sceneType == SceneType::YOU_WIN;
    auto text = isWin ? "YOU WIN!!" : "GAME OVER";
    auto message = Label::createWithSystemFont(text, "Arial", 48);
    auto color = isWin ? Color3B::GREEN : Color3B::RED;
    message->setColor(color);
    message->setPosition(Vec2(240, 240));
    addChild(message);
    auto delay = DelayTime::create(2);
    auto fadeOut = FadeOut::create(3);
    auto seq = Sequence::create(delay, fadeOut, NULL);
    message->runAction(seq);
}

