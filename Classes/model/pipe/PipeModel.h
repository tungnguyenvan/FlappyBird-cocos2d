//
// Created by tung on 21/01/2019.
//

#ifndef FLAPPYBIRD_PIPEMODEL_H
#define FLAPPYBIRD_PIPEMODEL_H

#include "cocos2d.h"
#include "common/defines/Defines.h"
#include "model/core/CoreModel.h"

class PipeModel : public CoreModel{
private:
    cocos2d::Sprite *mTopPipe;
    cocos2d::Sprite *mCenterPipe;
    cocos2d::Sprite *mBottomPipe;

public:
    PipeModel(cocos2d::Scene *scene);
    ~PipeModel();

    virtual void Init() override;
    virtual void Update() override;
};


#endif //FLAPPYBIRD_PIPEMODEL_H
