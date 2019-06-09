#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "cocos2d.h"
#include "Unit.h"
#include "Hero.h"
#include "bullet.h"

USING_NS_CC;

class Manager {
public:
	static Manager * getInstance();
	static void freeInstance(void);

public:
	static Manager * m_manager;
	Manager();
	bool init();

public:
	Vector<UnitLayer *> m_unitVector;
	Vector<Bullet *> m_bulletVector;
	Vector<UnitLayer *> & getUnitVector() { return m_unitVector; }
	Vector<Bullet *> & getBulletVector() { return m_bulletVector; }

};

#endif // __MANAGER_H__
