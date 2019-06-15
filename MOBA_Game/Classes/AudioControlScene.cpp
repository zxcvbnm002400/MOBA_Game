#include "AudioControlScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

Scene* AudioControl::createScene() {
	auto scene = Scene::create();
	auto layer = AudioControl::create();
	scene->addChild(layer);
	return scene;
}

bool AudioControl::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sprite *_background = Sprite::create("Settingbackground.png");
	_background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(_background);

	auto music_text = Text::create("MUSIC", "华文琥珀", 50);
	music_text->setPosition(Vec2(visibleSize.width*0.7, visibleSize.height*0.8));
	this->addChild(music_text);



	auto return_button = Button::create("button.png");
	return_button->setScale(1.3);
	return_button->setTitleText("RETURN");
	return_button->setTitleFontName("华文琥珀");
	return_button->setTitleFontSize(35);
	return_button->setPosition(Vec2(visibleSize.width*0.8, visibleSize.height*0.1));
	return_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			// 切换到MenuScene场景
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
			Director::getInstance()->replaceScene(GameMenu::createScene());
		}
	});
	this->addChild(return_button);
}