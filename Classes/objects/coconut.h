#pragma ince

#include "cocos2d.h"
#include "Box2D/Box2D.h"

USING_NS_CC;

class Coconut
{
public:
    Coconut();
    void init(b2World *world);
    Sprite *getSprite();

private:
    Sprite *coconut;
    bool existcoconut;
    float coconutX;
    float coconutY;
    b2FixtureDef coconutFixture;
    b2Body *coconutBody;
    b2CircleShape coconutShape;
    b2BodyDef coconutBodyDef;
};