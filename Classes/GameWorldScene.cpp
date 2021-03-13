#include <android/log.h>
#include <iostream>
#include "GameWorldScene.h"
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

#define SCALE_RATIO 16.0

Scene* GameWorld::createScene()
{
    return GameWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            CC_CALLBACK_1(GameWorld::menuCloseCallback, this));

    if (closeItem==nullptr ||
            closeItem->getContentSize().width<=0 ||
            closeItem->getContentSize().height<=0) {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else {
        float x = origin.x+visibleSize.width-closeItem->getContentSize().width/2;
        float y = origin.y+closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Game World", "fonts/Marker Felt.ttf", 24);
    if (label==nullptr) {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x+visibleSize.width/2,
                origin.y+visibleSize.height-label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
    world = new b2World(gravity);
    track.init(world);
    initCoconuts();
    scheduleUpdate();

    return true;
}

void GameWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void GameWorld::initCoconuts()
{
    for (auto& coc : coconut_array)
    {
        this->addChild(coc.getSprite());
        coc.init(world);
    }
}

//Simulate Physics
void GameWorld::update(float dt)
{
    int positionIterations = 10;
    int velocityIterations = 10;

    deltaTime = dt;
    world->Step(dt, velocityIterations, positionIterations);

    for (b2Body* body = world->GetBodyList(); body!=NULL; body = body->GetNext())
        if (body->GetUserData()) {
            Sprite* sprite = (Sprite*) body->GetUserData();
            sprite->setPosition(
                    Vec2(body->GetPosition().x*SCALE_RATIO, body->GetPosition().y*SCALE_RATIO));
            sprite->setRotation(-1*CC_RADIANS_TO_DEGREES(body->GetAngle()));
            CCLOG("UPDATE");
        }
    world->ClearForces();
    world->DrawDebugData();
}