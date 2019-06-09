#include "Unit.h"
#include "Bullet.h"
#include "Manager.h"

USING_NS_CC;

Layer* UnitLayer::createLayer() {
	return UnitLayer::create();
}

bool UnitLayer::init() {

	actionState.aim = NULL;
	actionState.c = 'N';

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	return true;
}

void UnitLayer::setAction(UnitLayer* aim, char c) {
	actionState.aim = aim;
	actionState.c = c;
}

void UnitLayer::move(Vec2 destination) {

	setAction(NULL, 'N');
	if (isStunned) return;
	unit->stopAllActions();
	Vec2 heroPosition = unit->getPosition();
	float moveTime = ccpDistance(heroPosition, destination) / moveSpeed;
	unit->runAction(MoveTo::create(moveTime, destination));

}

void UnitLayer::attack(UnitLayer* aim) {

	if (ccpDistance(unit->getPosition(), actionState.aim->getPosition()) <= attackRange) {
		auto bullet = Bullet::create();
		bullet->initBullet("bullet1.png");
		bullet->aim = aim;
		bullet->setPosition(Point(unit->getPositionX(), unit->getPositionY() + unit->getContentSize().height / 2 + 10));
		this->addChild(bullet, 3);
	}
	else {
		unit->stopAllActions();
		Vec2 selfPosition = unit->getPosition();
		Vec2 destination = actionState.aim->getPosition();
		unit->setPosition(selfPosition + (destination - selfPosition) / ccpDistance(selfPosition, destination) * moveSpeed / 60);
	}

}