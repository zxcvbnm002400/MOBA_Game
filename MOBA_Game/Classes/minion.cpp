#include "minion.h"
#include "Unit.h"
#include "Manager.h"

USING_NS_CC;

void MinionLayer::initMinion(int type) {
	if (type = 1) {
		maxLifeValue = 1000;
		curLifeValue = 1000;
		moveSpeed = 300;
		attackDamage = 45;
		attackPower = 0;
		attackInterval = 80;
		attackRange = 130;
		armor = 30;
		magicResistance = 0;
		collisionSize = 90;
	}
	else if (type = 2) {
		maxLifeValue = 850;
		curLifeValue = 850;
		moveSpeed = 300;
		attackDamage = 60;
		attackPower = 0;
		attackInterval = 80;
		attackRange = 350;
		armor = 30;
		magicResistance = 0;
		collisionSize = 90;
	}
	else if (type = 3) {
		maxLifeValue = 1900;
		curLifeValue = 1900;
		moveSpeed = 300;
		attackDamage = 100;
		attackPower = 0;
		attackInterval = 80;
		attackRange = 350;
		armor = 30;
		magicResistance = 0;
		collisionSize = 100;
	}
}

void MinionLayer::minionAI() {
	if (actionState.c == 'A') return;
	else if (actionState.c == 'N') {
		for (auto ele : Manager::getInstance()->getUnitVector()) {
			if (ccpDistance(ele->getPosition(), unit->getPosition()) <= 350) {
				setAction(ele, 'A');
			}
		}
	}
	if (actionState.c == 'N') {
		if (team == 0) {
		//	move();
		}
		else {
		//	move();
		}
	}
}









