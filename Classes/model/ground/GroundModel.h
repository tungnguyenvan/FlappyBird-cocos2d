//
// Created by tung on 22/01/2019.
//

#ifndef FLAPPYBIRD_GROUNDMODEL_H
#define FLAPPYBIRD_GROUNDMODEL_H

#include "cocos2d.h"
#include "common/defines/Defines.h"
#include "model/core/CoreModel.h"

class GroundModel : public CoreModel {
private:
    cocos2d::PhysicsBody *mPhysicsBody;
    cocos2d::Sprite *mContent1;
    cocos2d::Sprite *mContent2;
    cocos2d::Sprite *mContent3;
    cocos2d::Sprite *mContent4;

public:
    GroundModel(cocos2d::Scene *scene);
    ~GroundModel();

    virtual void Init() override;
    virtual void Update() override;
};


#endif //FLAPPYBIRD_GROUNDMODEL_H
