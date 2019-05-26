#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public Scene {
public:
    static Scene* createScene();
    virtual bool init();
	CREATE_FUNC(HelloWorld);

    void menuCloseCallback(Ref* pSender);
	void gameStartCallback(Ref* pSender);
	void settingCallback(Ref* pSender);
    
};

#endif // __HELLOWORLD_SCENE_H__
