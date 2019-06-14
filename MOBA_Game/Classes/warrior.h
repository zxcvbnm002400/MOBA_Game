#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "cocos2d.h"
#include "Unit.h"
#include "Hero.h"

USING_NS_CC;

class Warrior : public HeroLayer {
public:
	void initWarrior();

public:
	virtual void Qskill();
	virtual void Wskill();
	virtual void Eskill();
	virtual void Rskill();

	virtual void attack(UnitLayer* aim) override;

};

#endif