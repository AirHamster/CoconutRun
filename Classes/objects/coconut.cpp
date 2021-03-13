#include <android/log.h>
#include <iostream>
#include "objects/coconut.h"

USING_NS_CC;

#define SCALE_RATIO 16.0

Coconut::Coconut()
{
    coconutX = 200 + random(-100, 100);
    coconutY = 200 + random(-100, 100);

    coconut = Sprite::create("items/coconut.png");
    coconut->setScale(0.57);
    coconut->setPosition(Point(coconutX, coconutY));

    coconutShape.m_radius = 20/SCALE_RATIO;
    coconutFixture.density = 10;
    coconutFixture.friction = 0.8;
    coconutFixture.restitution = 0.6;
    coconutFixture.shape = &coconutShape;

    coconutBodyDef.type = b2_dynamicBody;
    coconutBodyDef.userData = coconut;
}

void Coconut::init(b2World *world)
{
    coconutBodyDef.position.Set(coconut->getPosition().x/SCALE_RATIO, coconut->getPosition().y/SCALE_RATIO);

    coconutBody = world->CreateBody(&coconutBodyDef);
    coconutBody->CreateFixture(&coconutFixture);
    coconutBody->SetGravityScale(10);
}

Sprite *Coconut::getSprite()
{
    return coconut;
}