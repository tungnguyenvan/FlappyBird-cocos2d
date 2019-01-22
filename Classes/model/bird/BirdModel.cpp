//
// Created by tung on 21/01/2019.
//

#include "common/defines/Defines.h"
#include "BirdModel.h"

BirdModel::BirdModel(cocos2d::Scene *scene) : CoreModel() {
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("bird.plist");
    mSprite = cocos2d::Sprite::createWithSpriteFrameName("bird_0.png");
    mSprite->setScale(0.6);
    mSprite->setTag(TAG_BIRD);
    mSprite->setPosition(cocos2d::Vec2(mVisibleSize.width / 2, mVisibleSize.height / 2));

    //create physicsBody
    mPhysicsBody = cocos2d::PhysicsBody::createCircle(mSprite->getContentSize().width / 2);
    mPhysicsBody->setCollisionBitmask(BIRD_COLLISION_BITMASK);
    mPhysicsBody->setCategoryBitmask(BIRD_COLLISION_BITMASK);
    mPhysicsBody->setContactTestBitmask(true);
    mPhysicsBody->setRotationEnable(false);
    mSprite->setPhysicsBody(mPhysicsBody);

    //create event
    mEventListener = cocos2d::EventListenerTouchOneByOne::create();
    mEventListener->setSwallowTouches(true);
    mEventListener->onTouchBegan = CC_CALLBACK_2(BirdModel::OnTouchBegan, this);
    scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mEventListener, scene);

    //add sprite to scene
    scene->addChild(mSprite);
}

BirdModel::~BirdModel(){

}

bool BirdModel::OnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
    mPhysicsBody->setVelocity(cocos2d::Vec2(0, VELOCITY_BIRD));
    return true;
}

void BirdModel::Init() {

}

void BirdModel::Update() {

}