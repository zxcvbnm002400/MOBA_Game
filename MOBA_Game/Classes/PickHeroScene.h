#ifndef Pick_Hero
#define Pick_Hero
#include"cocos2d.h"
#include"GameMenuScene.h"
#include"PreLoading.h"
#include"HeroBase.h"
#include"GameInfo.h"

class PickHero : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void gavi() {
		_Gavi->setVisible(true);
		_Snow->setVisible(false);
		_Ghost->setVisible(false);
	}

	void snow() {
		_Gavi->setVisible(false);
		_Snow->setVisible(true);
		_Ghost->setVisible(false);
	}


	void spirit() {
		_Gavi->setVisible(false);
		_Snow->setVisible(false);
		_Ghost->setVisible(true);
	}
	CREATE_FUNC(PickHero);
private:
	HeroBase *_Gavi;
	HeroBase *_Snow;
	HeroBase *_Ghost;
	
};


#endif // !Pick_Hero
#pragma once
