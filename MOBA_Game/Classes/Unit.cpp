#include "Unit.h"

USING_NS_CC;

Layer* UnitLayer::createLayer() {
	return UnitLayer::create();
}

bool UnitLayer::init() {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	return true;
}

void UnitLayer::move(Vec2 destination) {

	if (!true) return;
	unit->stopAllActions();
	Vec2 heroPosition = unit->getPosition();
	float moveTime = ccpDistance(heroPosition, destination) / moveSpeed;
	unit->runAction(MoveTo::create(moveTime, destination));

}

void UnitLayer::attack(UnitLayer* aim) {

	if (!true) return;


}