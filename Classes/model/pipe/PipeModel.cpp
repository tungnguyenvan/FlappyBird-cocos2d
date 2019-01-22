//
// Created by tung on 21/01/2019.
//

#include "PipeModel.h"

PipeModel::PipeModel(cocos2d::Scene *scene) : CoreModel() {
    mSprite = cocos2d::Sprite::create();

    mTopPipe = cocos2d::Sprite::create(PIPE_PATH);
    mCenterPipe = cocos2d::Sprite::create();
    mBottomPipe = cocos2d::Sprite::create(PIPE_PATH);

    mTopPipe->setTag(TAG_BARRIER);
    mCenterPipe->setTag(TAG_CENTER_PIPE);
    mBottomPipe->setTag(TAG_BARRIER);

    mSprite->setContentSize(cocos2d::Size(mBottomPipe->getContentSize().width, mVisibleSize.height));
    mSprite->setAnchorPoint(cocos2d::Vec2(0, 0));
    mBottomPipe->setAnchorPoint(cocos2d::Vec2(0, 1));
    mTopPipe->setRotation(180);
    mTopPipe->setAnchorPoint(cocos2d::Vec2(1, 1));
    mCenterPipe->setContentSize(cocos2d::Size(mBottomPipe->getContentSize().width, DISTANCE_PIPE));
    mCenterPipe->setAnchorPoint(cocos2d::Vec2(0, 0));

    //create physicsBody
    auto topPipePhysic = cocos2d::PhysicsBody::createBox(mTopPipe->getContentSize());
    auto centerPipePhysics = cocos2d::PhysicsBody::createBox(mCenterPipe->getContentSize());
    auto bottomPipePhysic = cocos2d::PhysicsBody::createBox(mBottomPipe->getContentSize());

    centerPipePhysics->setCollisionBitmask(PIPE_CENTER_COLLISION_BITMASK);
    centerPipePhysics->setContactTestBitmask(true);

    topPipePhysic->setContactTestBitmask(true);
    centerPipePhysics->setContactTestBitmask(true);
    bottomPipePhysic->setContactTestBitmask(true);

    topPipePhysic->setDynamic(false);
    centerPipePhysics->setDynamic(false);
    bottomPipePhysic->setDynamic(false);

    mTopPipe->setPhysicsBody(topPipePhysic);
    mBottomPipe->setPhysicsBody(bottomPipePhysic);
    mCenterPipe->setPhysicsBody(centerPipePhysics);

    mSprite->addChild(mTopPipe);
    mSprite->addChild(mCenterPipe);
    mSprite->addChild(mBottomPipe);
    scene->addChild(mSprite);
    SetAlive(false);
}

PipeModel::~PipeModel() {

}

void PipeModel::Init() {
    int maxHeightPipeBottom = mVisibleSize.height - mBottomPipe->getContentSize().height * 0.5;
    int minHeightPipeBottom = mBottomPipe->getContentSize().height * 0.3;
    int random = cocos2d::RandomHelper::random_int(minHeightPipeBottom, maxHeightPipeBottom);

    mSprite->setPosition(cocos2d::Vec2(-mSprite->getContentSize().width, 0));
    mBottomPipe->setPosition(cocos2d::Vec2(0, random));
    mTopPipe->setPosition(cocos2d::Vec2(0, mBottomPipe->getPosition().y + DISTANCE_PIPE));
    mCenterPipe->setPosition(cocos2d::Vec2(0, mBottomPipe->getPosition().y));
    mSprite->setPosition(mVisibleSize.width + mSprite->getContentSize().width, 0);
}

void PipeModel::Update() {
    if (IsAlive()){
        mSprite->setPosition(cocos2d::Vec2(mSprite->getPosition().x - PIPE_STEP, mSprite->getPosition().y));
        if (GetPosition().x <= -mSprite->getContentSize().width){
            SetAlive(false);
        }
    }
}