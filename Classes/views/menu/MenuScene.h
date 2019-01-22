//
// Created by tung on 22/01/2019.
//

#ifndef FLAPPYBIRD_MENUSCENE_H
#define FLAPPYBIRD_MENUSCENE_H

#include "cocos2d.h"

class MenuScene : cocos2d::Scene{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MenuScene);
};


#endif //FLAPPYBIRD_MENUSCENE_H
