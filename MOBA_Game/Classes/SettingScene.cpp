#include "SettingScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* Setting::createScene() {
	return Setting::create();
}

bool Setting::init() {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("SettingScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	//Back Button, to HelloWorldScene
	auto backItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(Setting::backCallback, this));
	float x_bI = origin.x + visibleSize.width - backItem->getContentSize().width / 2;
	float y_bI = origin.y + backItem->getContentSize().height / 2;
	backItem->setPosition(Vec2(x_bI, y_bI));
	auto back = Menu::create(backItem, NULL);
	back->setPosition(Vec2::ZERO);
	this->addChild(back, 1);

	//Background
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	return true;
}

void Setting::backCallback(Ref* pSender) {
	auto director = Director::getInstance();
	auto scene = HelloWorld::createScene();
	director->replaceScene(scene);
}
