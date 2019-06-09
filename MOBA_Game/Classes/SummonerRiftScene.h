#ifndef __SUMMONERRIFT_SCENE_H__
#define __SUMMONERRIFT_SCENE_H__

#include "cocos2d.h"
#include "Manager.h"
#include "Hero.h"
#include "bullet.h"

USING_NS_CC;

class  Rift: public Scene {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Rift);

	virtual void update(float delta);
	int _count;//ÓÎÏ·Ö¡¼ÆÊýÆ÷

	TMXTiledMap* tileMap;

	HeroLayer* mainPlayer;

	Vector<UnitLayer *> & vector_unit = Manager::getInstance()->getUnitVector();
	Vector<Bullet *> & vector_bullet = Manager::getInstance()->getBulletVector();

	void onMouseDown(Event *event);
	void onKeyPressed(EventKeyboard::KeyCode keycode, Event *event);
	void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);

	bool isQdown;
	bool isWdown;
	bool isEdown;
	bool isRdown;



};

#endif //__SUMMONERRIFT_SCENE_H__
