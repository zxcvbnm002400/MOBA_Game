#ifndef __GAMESETTLE_SCENE_H__
#define __GAMESETTLE_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameSettle : public Scene {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameSettle);

	void confirmCallback(Ref* pSender);

};

#endif //__GAMESETTLE_SCENE_H__