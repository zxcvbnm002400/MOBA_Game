#ifndef GAME_MENU
#define GAME_MENU
#include <iostream>
#include "cocos2d.h"
#include "AudioControlScene.h"
#include"PickHeroScene.h"
class GameMenu : public cocos2d::Layer
{
public:
	
	static cocos2d::Scene* createScene();
	
	virtual bool init();
	CREATE_FUNC(GameMenu);
};

#endif // !GAME_MENU

