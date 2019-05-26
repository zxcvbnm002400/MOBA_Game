#ifndef __PICKHERO_SCENE_H__
#define __PICKHERO_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class PickHero : public Scene {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(PickHero);

	void confirmCallback(Ref* pSender);
	void exitCallback(Ref* pSender);

};

#endif //__PICKHERO_SCENE_H__
