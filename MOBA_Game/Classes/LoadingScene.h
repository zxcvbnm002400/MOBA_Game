#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class Loading : public Scene {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Loading);

};

#endif //__LOADING_SCENE_H__