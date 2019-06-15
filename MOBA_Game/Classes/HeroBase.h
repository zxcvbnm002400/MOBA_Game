#pragma once
#ifndef _HeroBase_
#define _HeroBase_

#include"cocos2d.h"
#include"ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;



class HeroBase :public Sprite
{
public:

	std::string Name;
	static HeroBase* create(const std::string& filename)
	{
		HeroBase *sprite = new HeroBase();
		if (sprite && sprite->initWithFile(filename))
		{
			sprite->autorelease();
			return sprite;
		}
		CC_SAFE_DELETE(sprite);
		return nullptr;
	}

	
	Animate* getAnimateByName(std::string animName, float delay, int animNum);


};

#endif 

