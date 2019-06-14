#include "warrior.h"
#include "Unit.h"
#include "Manager.h"

USING_NS_CC;

void Warrior::initWarrior() {

	maxLifeValue = 2000;
	curLifeValue = 2000;
	moveSpeed = 380;
	attackDamage = 90;
	attackPower = 0;
	attackInterval = 60;
	attackRange = 150;
	armor = 35;
	magicResistance = 30;
	collisionSize = 120;



}

void Warrior::attack(UnitLayer* aim) {
	if (ccpDistance(unit->getPosition(), actionState.aim->getPosition()) <= attackRange) {
		if (Qinfo.duration) {
			Qinfo.duration = 0;
			moveSpeed -= 100;
			aim->getInjured(90 + attackDamage * 1.4, 'a');
			aim->silence = (1.5 * 60 > aim->silence) ? 1.5 * 60 : aim->silence;
		}
		aim->getInjured(attackDamage, 'a');
	}
}

void Warrior::Qskill() {
	Qinfo.timer = Qinfo.coldDown;
	Qinfo.duration = 5 * 60;
	moveSpeed += 100;
}

void Warrior::Wskill() {
	Winfo.timer = Winfo.coldDown;
	Winfo.duration = 4 * 60;
	armor += 30;
	magicResistance += 30;
}

void Warrior::Eskill() {
	Einfo.timer = Einfo.coldDown;
	for (auto e : Manager::getInstance()->getUnitVector()) {
		if (e->team == team) continue;
		if (ccpDistance(e->getPosition(), unit->getPosition()) <= Einfo.range) {
			e->getInjured(90 + 1 * attackDamage, 'a');
		}
	}
}

void Warrior::Rskill() {
	actionState.aim->getInjured(200 + 0.33 * (actionState.aim->maxLifeValue - actionState.aim->curLifeValue), 'r');
	setAction(NULL, 'N');
}