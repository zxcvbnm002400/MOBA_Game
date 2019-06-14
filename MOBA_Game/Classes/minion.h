#ifndef __MINION_H__
#define __MINION_H__

#include "cocos2d.h"
#include "Unit.h"

USING_NS_CC;

class MinionLayer : public UnitLayer {

public:
	int minionType;
	void initMinion(int type);
	void minionAI();

};

#endif