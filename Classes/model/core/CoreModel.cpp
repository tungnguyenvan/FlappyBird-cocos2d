//
// Created by tung on 21/01/2019.
//

#include "common/defines/Defines.h"
#include "CoreModel.h"
#include "cocos2d.h"

CoreModel::CoreModel() {
    mVisibleSize = cocos2d::Director::getInstance()->getVisibleSize();
}

CoreModel::~CoreModel() {

}

cocos2d::Vec2 CoreModel::GetPosition() {
    return mSprite->getPosition();
}

void CoreModel::SetPosition(cocos2d::Vec2 position) {
    mSprite->setPosition(position);
}

bool CoreModel::IsAlive() {
    return mAlive;
}

void CoreModel::SetAlive(bool alive) {
    mAlive = alive;
}

cocos2d::Size CoreModel::GetContentSize() {
    return mSprite->getContentSize();
}
