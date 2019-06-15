#include"cocos2d.h"
#include"HeroBase.h"

Animate* HeroBase::getAnimateByName(std::string animName, float delay, int animNum) {
	Animation*animation = Animation::create();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skeleton.plist");
	for (unsigned int i = 1; i <= animNum; i++) {
		std::string frameName = animName;
		frameName.append(StringUtils::format("%d", i)).append(".png");
		animation->addSpriteFrameWithFileName(frameName);
	}
	animation->setDelayPerUnit(delay);
	animation->setRestoreOriginalFrame(true);
	Animate*animate = Animate::create(animation);
	return animate;
}

