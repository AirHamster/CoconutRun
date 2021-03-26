#pragma once

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GameWorldScene.h"

USING_NS_CC;

class CartObject : public DrawNode {
public:
    virtual void init(GameWorld* world) = 0;

private:
};

class CartWheel : public CartObject {
    CartWheel();

public:
    virtual void init(GameWorld* world) override;

private:
};

class CartLongeron : public CartObject {

public:
    CartLongeron();

    virtual void init(GameWorld* world) override;

    void update_coordinates(float x1, float y1, float x2, float y2);

    void draw_rectangle();

private:
    DrawNode* m_rectNode = {};
    float h = 4;
    float m_x1;
    float m_y1;
    float m_x2;
    float m_y2;

    //Color4F m_body_color(0.63, 0.71, 0.82, 1);
    //Color4F m_border_color(0.56, 0.62, 0.72, 1);
    void calc_rectangle_point(Vec2 rectangle[]);
};

class CartRod : public CartObject {

public:
    CartRod();

    virtual void init(GameWorld* world) override;

private:
};

class CartDisk : public CartObject {

public:
    CartDisk();

    virtual void init(GameWorld* world) override;

private:
};
