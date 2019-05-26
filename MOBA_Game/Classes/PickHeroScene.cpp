#include "PickHeroScene.h"
#include "HelloWorldScene.h"
#include "LoadingScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* PickHero::createScene() {
	return PickHero::create();
}

bool PickHero::init() {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("PickHeroScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	//Confirm Button, to LoadingScene
	auto confirmItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(PickHero::confirmCallback, this));
	float x_cI = origin.x + visibleSize.width - confirmItem->getContentSize().width / 2;
	float y_cI = origin.y + confirmItem->getContentSize().height / 2;
	confirmItem->setPosition(Vec2(x_cI, y_cI));
	auto confirm = Menu::create(confirmItem, NULL);
	confirm->setPosition(Vec2::ZERO);
	this->addChild(confirm, 1);

	//Exit Button, to HelloWorldScene
	auto exitItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(PickHero::exitCallback, this));
	float x_eI = origin.x + visibleSize.width - exitItem->getContentSize().width / 2;
	float y_eI = origin.y + visibleSize.height - exitItem->getContentSize().height / 2;
	exitItem->setPosition(Vec2(x_eI, y_eI));
	auto exit = Menu::create(exitItem, NULL);
	exit->setPosition(Vec2::ZERO);
	this->addChild(exit, 1);

	//Background
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	return true;
}

void PickHero::confirmCallback(Ref* pSenser) {
	auto director = Director::getInstance();
	auto scene = Loading::createScene();
	director->replaceScene(scene);
}

void PickHero::exitCallback(Ref* pSender) {
	auto director = Director::getInstance();
	auto scene = HelloWorld::createScene();
	director->replaceScene(scene);
}