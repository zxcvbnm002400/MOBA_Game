#include "SummonerRiftScene.h"
#include "Manager.h"

USING_NS_CC;

Scene* Rift::createScene() {
	return Rift::create();
}

bool Rift::init() {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->scheduleUpdate();

	auto label = Label::createWithTTF("SummonerRiftScene", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	//Background
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	//KeyboardEvent
	auto listenerKeyPad = EventListenerKeyboard::create();
	listenerKeyPad->onKeyPressed = CC_CALLBACK_2(Rift::onKeyPressed, this);
	listenerKeyPad->onKeyReleased = CC_CALLBACK_2(Rift::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyPad, this);

	isQdown = false;
	isWdown = false;
	isEdown = false;
	isRdown = false;

	_count = 0;

	//MouseEvent
	auto listenerMouse = EventListenerMouse::create();
	listenerMouse->onMouseDown = CC_CALLBACK_1(Rift::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerMouse, this);


	return true;
}

void Rift::onKeyPressed(EventKeyboard::KeyCode keycode, Event *event) {
	switch (keycode) {
	case EventKeyboard::KeyCode::KEY_Q:
		isQdown = true;
		break;
	case EventKeyboard::KeyCode::KEY_W:
		isWdown = true;
		break;
	case EventKeyboard::KeyCode::KEY_E:
		isEdown = true;
		break;
	case EventKeyboard::KeyCode::KEY_R:
		isRdown = true;
		break;
	default:
		break;
	}
}

void Rift::onKeyReleased(EventKeyboard::KeyCode keycode, Event *event) {
	switch (keycode) {
	case EventKeyboard::KeyCode::KEY_Q:
		isQdown = false;
		break;
	case EventKeyboard::KeyCode::KEY_W:
		isWdown = false;
		break;
	case EventKeyboard::KeyCode::KEY_E:
		isEdown = false;
		break;
	case EventKeyboard::KeyCode::KEY_R:
		isRdown = false;
		break;
	default:
		break;
	}
}

void Rift::onMouseDown(Event *event) {
	EventMouse *e = (EventMouse *)event;
	Vec2 absPos = Vec2(e->getCursorX() - tileMap->getPositionX(), e->getCursorY() - tileMap->getPositionY());
	EventMouse::MouseButton mouseButton = e->getMouseButton();
	if (mouseButton == EventMouse::MouseButton::BUTTON_RIGHT) {
		for (auto ele : vector_unit) {
			if (mainPlayer->team == ele->team) continue;
			Point pos = Vec2(ele->convertToNodeSpace(tileMap->getPosition()));
			if (ccpDistance(pos, absPos) <= ele->collisionSize) {
				mainPlayer->setAction(ele, 'A');
				return;
			}
		}
		mainPlayer->move(absPos);
	}
	else if (mouseButton == EventMouse::MouseButton::BUTTON_LEFT) {

	}
}

void Rift::update(float delta) {

	++_count;

	int cnt = 0;

	for (auto ele : vector_bullet) {
		ele->bulletMove();
	}

	for (auto ele : vector_unit) {
		switch (ele->actionState.c) {
		case 'A':
			if (ccpDistance(ele->getPosition(), ele->actionState.aim->getPosition()) <= ele->attackRange) {
				ele->attack(ele->actionState.aim);
			}
			else {
				ele->move(ele->actionState.aim->getPosition());
			}
		case 'N':
			break;
		}
	}

	//die
	for (auto ele : vector_unit) {
		if (ele->curLifeValue <= 0) {
			vector_unit.erase(cnt);
			if (ele->revival) {

			}
			else {
				ele->cleanup();
			}
		}
		++cnt;
	}


}