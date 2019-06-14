#ifndef __GAMEINFO_H__
#define __GAMEINFO_H__

#include "cocos2d.h"

USING_NS_CC;

class GameInfo {
public:
	static GameInfo * getInstance();
	static void freeInstance(void);

public:
	static GameInfo * gameInfo;

	int player1;
	int player2;



};

#endif
