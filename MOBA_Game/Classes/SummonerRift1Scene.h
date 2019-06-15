#pragma once
#pragma once
#ifndef _GameScene_
#define _GameScene_
#include"cocos2d.h"
#include"GameInfo.h"
#include"HeroBase.h"
USING_NS_CC;

class SummonerRift1Scene :public cocos2d::Layer {
private:
	TMXTiledMap* _tileMap;
	HeroBase* _player;
	int _scWidth, _scHeight;
	int _count;//游戏帧计数器
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	/*void update(float delta);//帧更新函数*/
	CREATE_FUNC(SummonerRift1Scene);
	Vec2 tileCoordForPosition(Vec2 position);

	float getPlayerMoveTime(Vec2 startPos, Vec2 endPos, float speed);

	void playerMover(Point position);

	void setViewpointCenter(float duration, Vec2 position);

	void onMouseDown(Event*event);
	
	void update(float delta);
};
#endif // !_GameScene_

