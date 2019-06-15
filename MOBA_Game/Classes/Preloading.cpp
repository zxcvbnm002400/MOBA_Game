#include"cocos2d.h"
#include"SimpleAudioEngine.h"
#include"PreLoading.h"
USING_NS_CC;
using namespace CocosDenshion;
Scene* Preloading::createScene()
{

	auto scene = Scene::create();

	auto layer = Preloading::create();

	scene->addChild(layer);

	return scene;
}

bool Preloading::init() {
	if (!Layer::init()) {
		return false;
	}
	_count = 0;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Preloading.mp3", true);

	Sprite *_background = Sprite::create("Preloading.png");
	_background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(_background);

	auto _vs = Sprite::create("vs.png");
	_vs->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(_vs);

	auto _player2 = Sprite::create("gavi1.png");//电脑玩家
	_player2->setFlippedX(true);
	_player2->setTag(2);
	_player2->setPosition(visibleSize.width*0.75, 0);
	this->addChild(_player2);

	auto cp_text = Text::create("GAVI", "华文琥珀",100);
	auto blink = Blink::create(7, 50);
	cp_text->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*0.3));
	cp_text->runAction(blink);
	this->addChild(cp_text);

	this->scheduleUpdate();
	return true;
}

void Preloading::update(float delta) {
	_count++;
	if (_count > 500) {
		Director::getInstance()->replaceScene(SummonerRift1Scene::createScene());
	}
	Node*node2 = this->getChildByTag(2);
	if (NULL != node2) {
		if (node2->getPositionY() < 360) {
			node2->setPositionY(node2->getPositionY() + 120.0f*delta);
		}
	}
}