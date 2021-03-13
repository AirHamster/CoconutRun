#pragma ince

#include "cocos2d.h"
#include "Box2D/Box2D.h"

USING_NS_CC;

class Track
{
public:
    Track();
    void init(b2World *world);
private:
    b2PolygonShape floorShape;
    b2FixtureDef floorFixture;
    b2BodyDef floorBodyDef;
    float w;
    float h;
    float px;
    float py;
};