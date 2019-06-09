#include "Bullet.h"

USING_NS_CC;

bool Bullet::init()
{
	if (!Sprite::init())
		return false;

	return true;
}

//根据传入的纹理名称来初始化子弹类
void Bullet::initBullet(std::string name)
{
	//this->initWithSpriteFrameName(name);
	this->initWithFile(name);
}

void Bullet::bulletMove() {
	if (ccpDistance(this->getPosition(), aim->getPosition()) <= aim->collisionSize) {
		
		//造成伤害与效果

		this->cleanup();
	}
	else {
		Vec2 selfPos = this->getPosition();
		Vec2 aimPos = aim->getPosition();
		this->setPosition(selfPos + (aimPos - selfPos) / ccpDistance(selfPos, aimPos) * bulletSpeed / 60);
	}
}