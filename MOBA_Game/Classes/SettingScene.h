#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class Setting : public Scene {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Setting);

	void backCallback(cocos2d::Ref* pSender);

};

#endif //__SETTING_SCENE_H__