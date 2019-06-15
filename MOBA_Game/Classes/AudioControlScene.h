#ifndef AUDIO_CONTROL
#define AUDIO_CONTROL
#include <iostream>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include"extensions/GUI/CCControlExtension/CCControlSlider.h"
#include"GameMenuScene.h"
using namespace CocosDenshion;
using namespace cocos2d::extension;

class AudioControl : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	
	virtual bool init();

	CREATE_FUNC(AudioControl);
};



#endif // !AUDIO_CONTROL
