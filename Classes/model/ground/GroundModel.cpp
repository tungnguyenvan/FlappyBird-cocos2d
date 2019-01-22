//
// Created by tung on 22/01/2019.
//

#include "GroundModel.h"

GroundModel::GroundModel(cocos2d::Scene *scene) : CoreModel() {
    mSprite = cocos2d::Sprite::create();
    mSprite->setTag(TAG_BARRIER);

    mContent1 = cocos2d::Sprite::create("ground.png");
    mContent2 = cocos2d::Sprite::create("ground.png");
    mContent3 = cocos2d::Sprite::create("ground.png");
    mContent4 = cocos2d::Sprite::create("ground.png");

    mContent1->setAnchorPoint(cocos2d::Vec2(0, 0.5));
    mContent2->setAnchorPoint(cocos2d::Vec2(0, 0.5));
    mContent3->setAnchorPoint(cocos2d::Vec2(0, 0.5));
    mContent4->setAnchorPoint(cocos2d::Vec2(0, 0.5));

    mContent2->setPosition(cocos2d::Vec2(mContent1->getPosition().x + mContent1->getContentSize().width, 0));
    mContent3->setPosition(cocos2d::Vec2(mContent2->getPosition().x + mContent2->getContentSize().width, 0));
    mContent4->setPosition(cocos2d::Vec2(mContent3->getPosition().x + mContent3->getContentSize().width, 0));

    mSprite->addChild(mContent1);
    mSprite->addChild(mContent2);
    mSprite->addChild(mContent3);
    mSprite->addChild(mContent4);

    mSprite->setAnchorPoint(cocos2d::Vec2(0, 0));
    mSprite->setPosition(cocos2d::Vec2(0, 0));
    mSprite->setContentSize(cocos2d::Size(mContent1->getContentSize().width * 4, mContent1->getContentSize().height / 2));

    mPhysicsBody = cocos2d::PhysicsBody::createBox(mSprite->getContentSize());
    mPhysicsBody->setContactTestBitmask(true);
    mPhysicsBody->setDynamic(false);
    mSprite->setPhysicsBody(mPhysicsBody);

    scene->addChild(mSprite);
}

GroundModel::~GroundModel() {

}

void GroundModel::Init() {
    mSprite->setPosition(cocos2d::Vec2(mVisibleSize.width, 0));
}

void GroundModel::Update() {
    if (IsAlive()){
        mSprite->setPosition(cocos2d::Vec2(mSprite->getPosition().x - GROUND_STEP, mSprite->getPosition().y));
        if (mSprite->getPosition().x + mSprite->getContentSize().width <= 0){
            SetAlive(false);
        }
    }
}