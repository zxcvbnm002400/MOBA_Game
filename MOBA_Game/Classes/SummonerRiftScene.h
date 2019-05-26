#ifndef __SUMMONERRIFT_SCENE_H__
#define __SUMMONERRIFT_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class  Rift: public Scene {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Rift);

	void onMouseDown(Event *event);

};

#endif //__SUMMONERRIFT_SCENE_H__
