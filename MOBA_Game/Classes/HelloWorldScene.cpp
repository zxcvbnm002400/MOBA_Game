#include "HelloWorldScene.h"
#include "GameModeScene.h"
#include "SettingScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene() {
    return HelloWorld::create();
}

bool HelloWorld::init() {

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("HelloWorldScene", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

	//Start Button, to GameModeScene
	auto stratItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::gameStartCallback, this));
	float x_gI = origin.x + visibleSize.width - stratItem->getContentSize().width / 2;
	float y_gI = origin.y + stratItem->getContentSize().height / 2;
	stratItem->setPosition(Vec2(x_gI, y_gI));
	auto startGame = Menu::create(stratItem, NULL);
	startGame->setPosition(Vec2::ZERO);
	this->addChild(startGame, 1);

	//Setting Button, to SettingScene
	auto settingItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::settingCallback, this));
	float x_sI = origin.x + visibleSize.width - settingItem->getContentSize().width / 2;
	float y_sI = origin.y + settingItem->getContentSize().height / 2;
	settingItem->setPosition(Vec2(x_sI, y_sI));
	auto setting = Menu::create(settingItem, NULL);
	setting->setPosition(Vec2::ZERO);
	this->addChild(setting, 1);

	//Close Button, quit the Game
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    float x_cI = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
    float y_cI = origin.y + closeItem->getContentSize().height/2;
    closeItem->setPosition(Vec2(x_cI,y_cI));
    auto menu_c = Menu::create(closeItem, NULL);
    menu_c->setPosition(Vec2::ZERO);
    this->addChild(menu_c, 1);

	//Background
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender) {
    Director::getInstance()->end();
}

void HelloWorld::gameStartCallback(Ref* pSenser) {
	auto director = Director::getInstance();
	auto scene = GameMode::createScene();
	director->replaceScene(scene);
}

void HelloWorld::settingCallback(Ref* pSenser) {
	auto director = Director::getInstance();
	auto scene = Setting::createScene();
	director->replaceScene(scene);
}