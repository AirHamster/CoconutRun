#include <android/log.h>
#include <iostream>
#include "objects/track.h"

USING_NS_CC;

#define SCALE_RATIO 16.0

Track::Track()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    px = (visibleSize.width/2);
    py = 0;
    w = visibleSize.width;
    h = 10;
}

void Track::init(b2World* world)
{
    floorShape.SetAsBox(w/SCALE_RATIO, h/SCALE_RATIO);
    floorFixture.density = 0;
    floorFixture.friction = 10;
    floorFixture.restitution = 0.5;
    floorFixture.shape = &floorShape;

    floorBodyDef.position.Set(px/SCALE_RATIO, py/SCALE_RATIO);
    b2Body* floorBody = world->CreateBody(&floorBodyDef);

    floorBody->CreateFixture(&floorFixture);
}