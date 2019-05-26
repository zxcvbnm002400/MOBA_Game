#ifndef __GAMEMODE_SCENE_H__
#define __GAMEMODE_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameMode : public Scene {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameMode);

	void confirmCallback(cocos2d::Ref* pSender);
	void exitCallback(cocos2d::Ref* pSender);

};

#endif __GAMEMODE_SCENE_H__