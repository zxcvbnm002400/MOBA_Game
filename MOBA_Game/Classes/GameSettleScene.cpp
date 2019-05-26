#include "GameSettleScene.h"
#include "SummonerRiftScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* GameSettle::createScene() {
	return Rift::create();
}

bool GameSettle::init() {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("GameSettleScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	//Confirm Button, to HelloWorldScene
	auto confirmItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameSettle::confirmCallback, this));
	float x_cI = origin.x + visibleSize.width - confirmItem->getContentSize().width / 2;
	float y_cI = origin.y + confirmItem->getContentSize().height / 2;
	confirmItem->setPosition(Vec2(x_cI, y_cI));
	auto confirm = Menu::create(confirmItem, NULL);
	confirm->setPosition(Vec2::ZERO);
	this->addChild(confirm, 1);

	//Background
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	return true;
}

void GameSettle::confirmCallback(Ref* pSenser) {
	auto director = Director::getInstance();
	auto scene = HelloWorld::createScene();
	director->replaceScene(scene);
}