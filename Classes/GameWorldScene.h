#pragma once

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "objects/coconut.h"
#include "objects/track.h"

USING_NS_CC;

class GameWorld : public cocos2d::Scene, public b2ContactListener {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameWorld);
    void update(float dt);

    b2World *world;
    float deltaTime;

private:
    void initCoconuts();
    Track track{};
    std::array<Coconut, 15>coconut_array;
};
