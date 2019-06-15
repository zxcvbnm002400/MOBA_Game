#ifndef _PRELOADING_
#define _PRELOADING_
#include"cocos2d.h"
#include"SummonerRift1Scene.h"
#include"GameInfo.h"

class Preloading :public cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();

	virtual bool init();


	CREATE_FUNC(Preloading);
	
	virtual void update(float delta);
private:
	int _count;
};

#endif // !_PRELOADING_

