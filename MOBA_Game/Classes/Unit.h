#ifndef __UNIT_H__
#define __UNIT_H__

#include "cocos2d.h"

USING_NS_CC;

struct ActionState {
	UnitLayer* aim;
	char c;
};

class UnitLayer : public Layer {
public:
	static Layer* createLayer();
	virtual bool init();
	CREATE_FUNC(UnitLayer);

	Sprite* unit;

public:
	bool revival;
	int team;
	//属性
	float maxLifeValue;			//最大生命值
	float curLifeValue;			//当前生命值
	float moveSpeed;			//移动速度
	float attackDamage;			//物理攻击
	float attackPower;			//法术攻击
	float attackSpeed;			//攻击速度
	float attackRange;			//攻击范围
	float armor;				//物理防御
	float magicResistance;		//法术防御

	bool isStunned;

public:
	bool isMelee;				//是否为近战
	float collisionSize;		//碰撞体积

public:
	void move(Vec2 destination);
	void attack(UnitLayer* aim);
	void setAction(UnitLayer* aim, char c);

public:
	ActionState actionState;

};

#endif // __UNIT_H__
