//
// Created by tung on 21/01/2019.
//

#ifndef FLAPPYBIRD_BIRDMODEL_H
#define FLAPPYBIRD_BIRDMODEL_H

#include "cocos2d.h"
#include "model/core/CoreModel.h"

class BirdModel : public CoreModel {
private:
    cocos2d::EventListenerTouchOneByOne *mEventListener;
    cocos2d::PhysicsBody *mPhysicsBody;

public:
    BirdModel(cocos2d::Scene *scene);
    ~BirdModel();
    bool OnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void Init();
    virtual void Update();
};


#endif //FLAPPYBIRD_BIRDMODEL_H
