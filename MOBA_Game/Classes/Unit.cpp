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
	silence = 0;
	stun = 0;
	slowDown.first = 0;
	slowDown.second = 0;


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//血条
	CCProgressTimer* progressTimeHPBackGround = CCProgressTimer::create(CCSprite::create("hpbackground.png"));
	progressTimeHPBackGround->setPosition(Vec2(unit->getPositionX() + 25, unit->getPositionY() + 50));
	progressTimeHPBackGround->setAnchorPoint(ccp(0, 0));
	progressTimeHPBackGround->setPercentage(100);
	CCProgressTimer* progressTimeHP = CCProgressTimer::create(CCSprite::create("hp.png"));
	progressTimeHP->setPosition(Vec2(unit->getPositionX() + 25, unit->getPositionY() + 50));//下面的配置参加testcpp的样例代码
	progressTimeHP->setAnchorPoint(ccp(0, 0));  //默认是中间，要设置左下角
	progressTimeHP->setPercentage(100);  //初始的百分比
	progressTimeHP->setMidpoint(ccp(0, 1));  //设置中点位置，默认是四周向重点变化。现在把重点设置为左边(纵向居中)，使血从右向左减少
	progressTimeHP->setBarChangeRate(ccp(1, 0));//暂时不知道什么用
	progressTimeHP->setType(kCCProgressTimerTypeBar);//暂时不知道什么用
	unit->addChild(progressTimeHPBackGround, 101);
	unit->addChild(progressTimeHP, 102, 102);


	return true;
}

void UnitLayer::setAction(UnitLayer* aim, char c) {
	actionState.aim = aim;
	actionState.c = c;
}

void UnitLayer::move(Vec2 destination) {

	setAction(NULL, 'N');

	unit->stopAllActions();
	Vec2 heroPosition = unit->getPosition();
	float moveTime = ccpDistance(heroPosition, destination) / moveSpeed;
	unit->runAction(MoveTo::create(moveTime, destination));

}

void UnitLayer::attack(UnitLayer* aim) {

	if (ccpDistance(unit->getPosition(), actionState.aim->getPosition()) <= attackRange) {
		if (attackColdDown != 0) return;
		attackColdDown = attackInterval;
		if (isMelee) {
			//
			aim->getInjured(attackDamage, 'a');
		}
		else {

			//
			auto bullet = Bullet::create();
			bullet->initBullet(unitType + "_attack_bullet.png");
			bullet->aim = aim;
			bullet->setPosition(Point(unit->getPositionX(), unit->getPositionY() + unit->getContentSize().height / 2 + 10));
			this->addChild(bullet, 3);
		}
	}
	else {
		unit->stopAllActions();
		Vec2 selfPosition = unit->getPosition();
		Vec2 destination = actionState.aim->getPosition();
		unit->setPosition(selfPosition + (destination - selfPosition) / ccpDistance(selfPosition, destination) * moveSpeed / 60);
	}

}

void UnitLayer::getInjured(float damage, char type) {
	if (type == 'r') {
		curLifeValue -= damage;
	}
	else if (type == 'a') {
		curLifeValue -= damage * (1 - armor / (160 - armor));
	}
	else if (type == 'm') {
		curLifeValue -= damage * (1 - magicResistance / (160 - magicResistance));
	}
	if (curLifeValue < 0) {
		curLifeValue == 0;
	}
}