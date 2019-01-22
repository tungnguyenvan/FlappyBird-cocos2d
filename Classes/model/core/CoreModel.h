//
// Created by tung on 21/01/2019.
//

#ifndef FLAPPYBIRD_COREMODEL_H
#define FLAPPYBIRD_COREMODEL_H

#include "cocos2d.h"

class CoreModel {
protected:
    bool mAlive;
    cocos2d::Sprite *mSprite;
    cocos2d::Size mVisibleSize;

public:
    CoreModel();
    virtual ~CoreModel();
    void SetPosition(cocos2d::Vec2 position);
    cocos2d::Vec2 GetPosition();
    bool IsAlive();
    void SetAlive(bool alive);
    cocos2d::Size GetContentSize();

    virtual void Init() = 0;
    virtual void Update() = 0;
};


#endif //FLAPPYBIRD_COREMODEL_H
