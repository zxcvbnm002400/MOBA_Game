#include"cocos2d.h"
#include"PickHeroScene.h"
#include "ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
USING_NS_CC;
using namespace ui;

Scene* PickHero::createScene()
{

	auto scene = Scene::create();

	auto layer = PickHero::create();

	scene->addChild(layer);

	return scene;
}

bool PickHero::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Heroselect.mp3", true);

	Sprite *_background = Sprite::create("selectbackground.png");
	_background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(_background);

	Sprite *_select = Sprite::create("select.png");
	_select->setPosition(visibleSize.width *0.6, visibleSize.height *0.38);
	this->addChild(_select);
;

	_Gavi = HeroBase::create("gavi1.png");
	auto Gavianimate = _Gavi->getAnimateByName("gavi_in_", 0.5f, 4);
	auto Gavirepeatanimate = RepeatForever::create(Gavianimate);
	_Gavi->runAction(Gavirepeatanimate);
	_Gavi->setPosition(visibleSize.width*0.6, visibleSize.height / 2);
	_Gavi->setVisible(false);
	this->addChild(_Gavi);
	
	auto gavi_text = Text::create("GAVI", "华文琥珀", 50);
	gavi_text->setPosition(Vec2(visibleSize.width*0.25, visibleSize.height*0.85));
	gavi_text->setColor(Color3B(0, 0, 0));
	this->addChild(gavi_text);
	
	_Snow = HeroBase::create("snow1.png");
	auto Snowanimate = _Snow->getAnimateByName("snow_death_", 0.3f, 4);
	auto Snowrepeatanimate = RepeatForever::create(Snowanimate);
	_Snow->runAction(Snowrepeatanimate);
	_Snow->setPosition(visibleSize.width*0.6, visibleSize.height / 2);
	_Snow->setVisible(false);
	this->addChild(_Snow);

	auto snow_text = Text::create("SNOWMAN", "华文琥珀", 50);
	snow_text->setPosition(Vec2(visibleSize.width*0.25, visibleSize.height*0.6));
	snow_text->setColor(Color3B(0, 0, 0));
	this->addChild(snow_text);

	_Ghost = HeroBase::create("ghost1.png");
	auto Spiritanimate = _Ghost->getAnimateByName("ghost_death_", 0.3f, 4);
	auto Spiritrepeatanimate = RepeatForever::create(Spiritanimate);
	_Ghost->runAction(Spiritrepeatanimate);
	_Ghost->setPosition(visibleSize.width*0.6, visibleSize.height / 2);
	_Ghost->setVisible(false);
	this->addChild(_Ghost);

	auto spirit_text = Text::create("GHOST", "华文琥珀", 50);
	spirit_text->setPosition(Vec2(visibleSize.width*0.25, visibleSize.height*0.35));
	spirit_text->setColor(Color3B(0, 0, 0));
	this->addChild(spirit_text);
	
	auto gavi_button = Button::create("gaviselect.png");
	gavi_button->setPosition(Vec2(visibleSize.width*0.25, visibleSize.height *0.75));
	gavi_button->addTouchEventListener([this](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			this->gavi();
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
			SimpleAudioEngine::getInstance()->playEffect("gaviselect.wav", false);
		}
	});
	this->addChild(gavi_button);

	auto snow_button = Button::create("snowselect.png");
	snow_button->setPosition(Vec2(visibleSize.width*0.25, visibleSize.height *0.5));
	snow_button->addTouchEventListener([this](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			this->snow();
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
			SimpleAudioEngine::getInstance()->playEffect("snowselect.wav", false);
		}
	});
	this->addChild(snow_button);

	auto ghost_button = Button::create("ghostselect.png");
	ghost_button->setPosition(Vec2(visibleSize.width*0.25, visibleSize.height *0.25));
	ghost_button->addTouchEventListener([this](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			this->spirit();
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
			SimpleAudioEngine::getInstance()->playEffect("ghostselect.wav",false);
		}
	});
	this->addChild(ghost_button);


	auto gorift = Button::create("gorift.png");
	gorift->setPosition(Vec2(visibleSize.width*0.85, visibleSize.height*0.15));
	gorift->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			// 切换到MenuScene场景
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
			Director::getInstance()->replaceScene(Preloading::createScene());
		}
	});
	this->addChild(gorift);

	auto gaviskill = Button::create("skill.png");
	gaviskill->setPosition(Vec2(visibleSize.width*0.15, visibleSize.height*0.75));
	this->addChild(gaviskill);

	auto snowskill = Button::create("skill.png");
	snowskill->setPosition(Vec2(visibleSize.width*0.15, visibleSize.height*0.5));
	this->addChild(snowskill);

	auto spiritskill = Button::create("skill.png");
	spiritskill->setPosition(Vec2(visibleSize.width*0.15, visibleSize.height*0.25));
	this->addChild(spiritskill);

	auto return_button = Button::create("button.png");
	return_button->setScale(1.3);
	return_button->setTitleText("RETURN");
	return_button->setTitleFontName("华文琥珀");
	return_button->setTitleFontSize(35);
	return_button->setPosition(Vec2(visibleSize.width*0.2, visibleSize.height*0.1));
	return_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			// 切换到MenuScene场景
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
			Director::getInstance()->replaceScene(GameMenu::createScene());
		}
	});
	this->addChild(return_button);
	return true;
}

