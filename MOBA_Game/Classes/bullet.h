#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"
#include "Unit.h"

USING_NS_CC;

class  Bullet : public Sprite
{
public:
	Bullet(void) {}
	~Bullet(void) {}

public:

	virtual bool init();
	CREATE_FUNC(Bullet);

public:
	//³õÊ¼»¯×Óµ¯
	void initBullet(std::string name);

	void bulletMove();

	UnitLayer* aim;
	float bulletSpeed;

};

#endif //__BULLET_H__