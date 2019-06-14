#include "GameInfo.h"

GameInfo* GameInfo::gameInfo = NULL;

GameInfo * GameInfo::getInstance() {
	if (gameInfo == NULL) {
		gameInfo = new GameInfo();
	}
	return gameInfo;
}

void GameInfo::freeInstance(void) {
	if (gameInfo != NULL) {
		delete gameInfo;
		gameInfo = NULL;
	}
}