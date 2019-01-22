//
// Created by tung on 22/01/2019.
//

#include "GameOver.h"

cocos2d::Scene* GameOver::createScene(int score) {
    return GameOver::create();
}

bool GameOver::init() {
    if (!cocos2d::Scene().init()){
        return false;
    }

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    //create background
    auto background  = cocos2d::Sprite::create("bg.png");
    background->setContentSize(visibleSize);
    background->setAnchorPoint(cocos2d::Vec2(0, 0));

    //create logo game over
    auto logo = cocos2d::Sprite::create("logo.png");
    logo->setPosition(cocos2d::Vec2(visibleSize.width * 0.5, visibleSize.height * 0.7));
    logo->setScale(0.5);

    //create panel yellow
    auto panel = cocos2d::Sprite::create("panel.jpg");
    panel->setScale(0.5);
    panel->setPosition(cocos2d::Vec2(visibleSize.width * 0.5,
            logo->getPosition().y - logo->getContentSize().height));

    //create label score
    auto lbScore = cocos2d::Label::createWithTTF(std::to_string(mScore), "fonts/Marker Felt.ttf", 60);
    lbScore->setPosition(cocos2d::Vec2(panel->getContentSize().width * 0.8, panel->getContentSize().height * 0.6));

    //create label high score
    auto lbHighScore = cocos2d::Label::createWithTTF(std::to_string(mScore), "fonts/Marker Felt.ttf", 60);
    lbHighScore->setPosition(cocos2d::Vec2(panel->getContentSize().width * 0.8, panel->getContentSize().height * 0.25));

    addChild(background);
    addChild(logo);
    addChild(panel);

    panel->addChild(lbScore);
    panel->addChild(lbHighScore);

    return true;
}