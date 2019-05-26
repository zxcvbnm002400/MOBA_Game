#include "GameModeScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* GameMode::createScene() {
	return GameMode::create();
}

bool GameMode::init() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("GameModeScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	auto confirmItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameMode::confirmCallback, this));
	float x = origin.x + visibleSize.width - confirmItem->getContentSize().width / 2;
	float y = origin.y + confirmItem->getContentSize().height / 2;
	confirmItem->setPosition(Vec2(x, y));
	auto confirm = Menu::create(confirmItem, NULL);
	confirm->setPosition(Vec2::ZERO);
	this->addChild(confirm, 1);

	auto exitItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameMode::exitCallback, this));
	float x = origin.x + visibleSize.width - exitItem->getContentSize().width / 2;
	float y = origin.y + visibleSize.height - exitItem->getContentSize().height / 2;
	exitItem->setPosition(Vec2(x, y));
	auto exit = Menu::create(exitItem, NULL);
	exit->setPosition(Vec2::ZERO);
	this->addChild(exit, 1);



}

