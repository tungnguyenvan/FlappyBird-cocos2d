//
// Created by tung on 22/01/2019.
//

#include "MenuScene.h"
#include "cocos2d.h"
#include "ui/UIButton.h"
#include "views/main/MainScene.h"

cocos2d::Scene* MenuScene::createScene() {
    return MenuScene::create();
}

bool MenuScene::init() {
    if (!Scene().init()) {
        return false;
    }

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    auto background = cocos2d::Sprite::create("bg.png");
    background->setAnchorPoint(cocos2d::Vec2(0, 0));
    background->setContentSize(visibleSize);

    auto button = cocos2d::ui::Button::create("btn_play.png");
    button->addTouchEventListener([&](cocos2d::Ref *sender, cocos2d::ui::Widget::TouchEventType type){
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED){
            cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.5, MainScene::createScene()));
        }
    });
    button->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));

    addChild(background);
    addChild(button);

    return true;
}