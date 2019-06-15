#include"cocos2d.h"
#include"GameMenuScene.h"
#include "ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
USING_NS_CC;
using namespace ui;
using namespace CocosDenshion;

Scene* GameMenu::createScene()
{
	
	auto scene = Scene::create();

	auto layer = GameMenu::create();

	scene->addChild(layer);

	return scene;
}

bool GameMenu::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
		SimpleAudioEngine::getInstance()->playBackgroundMusic("Menumusic.mp3", true);

	Sprite *_background = Sprite::create("Menubackground.png");
	_background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(_background);

	Sprite *_label = Sprite::create("label.png");
	_label->setPosition(visibleSize.width / 2, visibleSize.height*0.7);
	this->addChild(_label,1);


	auto start_button = Button::create("button.png");//开始按钮
	start_button->setScale(1.3);
	start_button->setTitleText("START");
	start_button->setTitleFontName("华文琥珀");
	start_button->setTitleFontSize(35);
	start_button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*0.4));
	start_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			// 切换到PreLoad场景
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
			Director::getInstance()->replaceScene(PickHero::createScene());
		}
	});
	this->addChild(start_button);

	auto set_button= Button::create("button.png");//设置按钮
	set_button->setScale(1.3);
	set_button->setTitleText("SETTING");
	set_button->setTitleFontName("华文琥珀");
	set_button->setTitleFontSize(35);
	set_button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*0.25));
	set_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			// 切换到AudioControl场景
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
			Director::getInstance()->replaceScene(AudioControl::createScene());
		}
	});
	this->addChild(set_button);

	auto close_button = Button::create("button.png");//退出按钮
	close_button->setScale(1.3);
	close_button->setTitleText("EXIT");
	close_button->setTitleFontName("华文琥珀");
	close_button->setTitleFontSize(35);
	close_button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*0.1));
	close_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
			Director::getInstance()->end();
		}
	});
	this->addChild(close_button);
	return true;
}
