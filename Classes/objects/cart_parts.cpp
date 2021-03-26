#include <android/log.h>
#include <iostream>
#include "objects/cart_parts.h"


USING_NS_CC;

#define SCALE_RATIO 16.0

CartLongeron::CartLongeron() {
    m_rectNode = DrawNode::create();
}

void CartLongeron::init(GameWorld *world) {
    world->addChild(m_rectNode);
}

void CartLongeron::draw_rectangle() {

    Vec2 rectangle[4];

    calc_rectangle_point(rectangle);
    Color4F blue(0.63, 0.71, 0.82, 1);
    Color4F border_blue(0.56, 0.62, 0.72, 1);
    m_rectNode->drawPolygon(rectangle, 4, blue, 1, border_blue);
}

void CartLongeron::calc_rectangle_point(Vec2 rectangle[]) {

    CCLOG("blya %f", (m_y1 - m_y2)/(m_x1-m_x2));
    float alfa = MATH_RAD_TO_DEG(atan((m_y1 - m_y2)/(m_x1-m_x2)));
    CCLOG("Alfa %f", alfa);
    float beta = 180 - 90 - MATH_RAD_TO_DEG(atan((m_y1 - m_y2)/(m_x1-m_x2)));
    CCLOG("Beta %f", beta);
    CCLOG("Cos beta %f", cos(MATH_DEG_TO_RAD(beta)));
    CCLOG("Sin beta %f", sin(MATH_DEG_TO_RAD(beta)));

    float x2 = m_x1-h*cos(MATH_DEG_TO_RAD(beta));
    float y2 = m_y1+h*sin(MATH_DEG_TO_RAD(beta));
    float x1 = m_x1+h*cos(MATH_DEG_TO_RAD(beta));
    float y1 = m_y1-h*sin(MATH_DEG_TO_RAD(beta));

    float x3 = m_x2-h*cos(MATH_DEG_TO_RAD(beta));
    float y3 = m_y2+h*sin(MATH_DEG_TO_RAD(beta));
    float x4 = m_x2+h*cos(MATH_DEG_TO_RAD(beta));
    float y4 = m_y2-h*sin(MATH_DEG_TO_RAD(beta));
    CCLOG("x3 y3 x4 y4 %f %f %f %f", x3, y3, x4, y4);

    rectangle[0] = Vec2(x1, y1);
    rectangle[1] = Vec2(x2, y2);
    rectangle[2] = Vec2(x3, y3);
    rectangle[3] = Vec2(x4, y4);
}

void CartLongeron::update_coordinates(float x1, float y1, float x2, float y2) {
    m_x1 = x1;
    m_x2 = x2;
    m_y1 = y1;
    m_y2 = y2;
    draw_rectangle();
}