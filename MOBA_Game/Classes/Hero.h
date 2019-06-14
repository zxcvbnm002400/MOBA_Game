#ifndef __HERO_H__
#define __HERO_H__

#include "cocos2d.h"
#include "Unit.h"

USING_NS_CC;

enum SkillType {instant, aim, direction, state, passive, ban};

struct skillInfo{
	SkillType skillType;
	float coldDown;
	float timer;
	float duration;
	float range;
};

class HeroLayer : public UnitLayer {

public:
	//属性
	float level;
	float experience;
	float maxManaValue;			//最大法力值
	float curManaValue;			//当前法力值
	float criticalChance;		//暴击几率
	float criticalDamage;		//暴击效果
	float CDReduction;			//冷却缩减
	float lifeValueRegen;		//每5秒回血
	float manaValueRegen;		//每5秒回蓝
	float armorPenetration;		//物理穿透
	float MRpenetration;		//法术穿透
	float lifeSteal;			//物理吸血
	float spellVamp;			//法术吸血
	float tenacity;				//韧性


public:
	virtual void Qskill();
	virtual void Wskill();
	virtual void Eskill();
	virtual void Rskill();
	virtual void deQskill();
	virtual void deWskill();
	virtual void deEskill();
	virtual void deRskill();

	skillInfo Qinfo;
	skillInfo Winfo;
	skillInfo Einfo;
	skillInfo Rinfo;

};

#endif // __HERO_H__