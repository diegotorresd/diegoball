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

Scene* InitialScene::createScene() {
    return InitialScene::create();
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
    return true;
}

