/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "MainScene.h"
#include "SimpleAudioEngine.h"
#include "model/pipe/PipeModel.h"
#include "model/bird/BirdModel.h"
#include "model/ground/GroundModel.h"
#include "views/gameover/GameOver.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = MainScene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(cocos2d::Vec2(0, GRAVITY_Y));

    auto screen = MainScene::create();
    screen->SetPhysicsWorld(scene->getPhysicsWorld());

    scene->addChild(screen);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    mFrameCount = 0;
    mScore = 0;

    //create background
    auto background = Sprite::create(BACKGROUND_PATH);
    background->setContentSize(visibleSize);
    background->setAnchorPoint(cocos2d::Vec2(0, 0));
    addChild(background);

    mBird = new BirdModel(this);
    CreatePipes();

    //create label score
    mLbScore = cocos2d::Label::createWithTTF(std::to_string(mScore), "fonts/Marker Felt.ttf", 50);
    mLbScore->setString(std::to_string(mScore));
    mLbScore->setPosition(cocos2d::Vec2(visibleSize.width * 0.5, visibleSize.height * 0.8));
    addChild(mLbScore);

    //create ground
    mGround = new GroundModel(this);
    mGround->SetAlive(true);
    mGroundSecond = new GroundModel(this);
    mGroundSecond->SetAlive(false);

    this->scheduleUpdate();

    mContact = cocos2d::EventListenerPhysicsContact::create();
    mContact->onContactBegin = CC_CALLBACK_1(MainScene::OnContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mContact, this);

    return true;
}

void MainScene::update(float) {
    mGround->Update();
    mGroundSecond->Update();

    if (!mGroundSecond->IsAlive()) {
        mGroundSecond->SetPosition(cocos2d::Vec2(mGround->GetPosition().x + mGround->GetContentSize().width, mGround->GetPosition().y));
        mGroundSecond->SetAlive(true);
    }

    if (!mGround->IsAlive()) {
        mGround->SetPosition(cocos2d::Vec2(mGroundSecond->GetPosition().x + mGroundSecond->GetContentSize().width, mGroundSecond->GetPosition().y));
        mGround->SetAlive(true);
    }

    for (int i = 0; i < SIZE_MAX_PIPE; ++i) {
        mPipes.at(i)->Update();
    }

    mFrameCount++;
    if (mFrameCount % 20 == 0){
        for (int i = 0; i < SIZE_MAX_PIPE; ++i) {
            if (!mPipes.at(i)->IsAlive()){
                mPipes.at(i)->Init();
                mPipes.at(i)->SetAlive(true);
            }
            break;
        }
    }
}

void MainScene::CreatePipes() {
    for (int i = 0; i < SIZE_MAX_PIPE; ++i) {
        PipeModel *p = new PipeModel(this);
        p->Init();
        mPipes.push_back(p);
    }
}

bool MainScene::OnContactBegin(cocos2d::PhysicsContact &contact) {
    auto shapeA = contact.getShapeA()->getBody()->getNode();
    auto shapeB = contact.getShapeB()->getBody()->getNode();

    if ((shapeA->getTag() == TAG_BIRD && shapeB->getTag() == TAG_CENTER_PIPE) ||
            (shapeB->getTag() == TAG_BIRD && shapeA->getTag() == TAG_CENTER_PIPE)) {
        mScore++;
        mLbScore->setString(std::to_string(mScore));
    }

    if ((shapeA->getTag() == TAG_BIRD && shapeB->getTag() == TAG_BARRIER) ||
        (shapeB->getTag() == TAG_BIRD && shapeA->getTag() == TAG_BARRIER)) {
        cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.5, GameOver::createScene(mScore)));
        this->onExit();
    }

    return true;
}