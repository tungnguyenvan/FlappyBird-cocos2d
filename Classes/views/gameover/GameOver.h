//
// Created by tung on 22/01/2019.
//

#ifndef FLAPPYBIRD_GAMEOVER_H
#define FLAPPYBIRD_GAMEOVER_H

#include "cocos2d.h"

class GameOver : public cocos2d::Scene {
private:
    int mScore;

public:
    static cocos2d::Scene* createScene(int score);
    virtual bool init();
    CREATE_FUNC(GameOver);
};


#endif //FLAPPYBIRD_GAMEOVER_H
