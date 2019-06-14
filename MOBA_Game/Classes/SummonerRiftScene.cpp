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

	//init hero



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
	minute = 0;
	second = 0;
	centisecond = 0;
	
	//MouseEvent
	auto listenerMouse = EventListenerMouse::create();
	listenerMouse->onMouseDown = CC_CALLBACK_1(Rift::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerMouse, this);

	return true;
}

void Rift::onKeyPressed(EventKeyboard::KeyCode keycode, Event *event) {
	switch (keycode) {
	case EventKeyboard::KeyCode::KEY_Q:
		if (mainPlayer->stun != 0 || mainPlayer->silence != 0) return;
		if (mainPlayer->Qinfo.timer != 0 && mainPlayer->Qinfo.skillType != passive) return;
		if (mainPlayer->Qinfo.skillType == state || mainPlayer->Qinfo.skillType == instant) {
			mainPlayer->Qskill();
		}
		isQdown = true;
		break;
	case EventKeyboard::KeyCode::KEY_W:
		if (mainPlayer->Winfo.timer != 0 && mainPlayer->Winfo.skillType != passive) return;
		if (mainPlayer->Winfo.skillType == state || mainPlayer->Winfo.skillType == instant) {
			mainPlayer->Wskill();
			return;
		}
		isWdown = true;
		break;
	case EventKeyboard::KeyCode::KEY_E:
		if (mainPlayer->Einfo.timer != 0 && mainPlayer->Einfo.skillType != passive) return;
		if (mainPlayer->Einfo.skillType == state || mainPlayer->Einfo.skillType == instant) {
			mainPlayer->Eskill();
			return;
		}
		isEdown = true;
		break;
	case EventKeyboard::KeyCode::KEY_R:
		if (mainPlayer->Rinfo.timer != 0 && mainPlayer->Rinfo.skillType != passive && mainPlayer->Rinfo.skillType != ban) return;
		if (mainPlayer->Rinfo.skillType == state || mainPlayer->Rinfo.skillType == instant) {
			mainPlayer->Rskill();
			return;
		}
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
		if (isQdown) {

		}
		else if (isWdown) {

		}
		else if (isEdown) {

		}
		else if (isRdown) {

		}
	}
}

void Rift::update(float delta) {

	//time
	++_count;
	++centisecond;
	if (centisecond == 60) {
		centisecond = 0;
		++second;
		if (second == 60) {
			second = 0;
			++minute;
		}
	}

	//state
	for (auto ele : vector_unit) {
		if (ele->attackColdDown != 0) --ele->attackColdDown;
		if (ele->stun != 0) --ele->stun;
		if (ele->silence != 0) --ele->silence;
		if (ele->slowDown.first == 1) {
			ele->moveSpeed += ele->slowDown.second;
			ele->slowDown.second = 0;
		}
		if (ele->slowDown.first != 0) --ele->slowDown.first;
	}
	for (auto ele : vector_hero) {
		if (ele->Qinfo.timer != 0) --ele->Qinfo.timer;
		if (ele->Winfo.timer != 0) --ele->Winfo.timer;
		if (ele->Einfo.timer != 0) --ele->Einfo.timer;
		if (ele->Rinfo.timer != 0) --ele->Rinfo.timer;
		if (ele->Qinfo.duration == 1) ele->deQskill();
		if (ele->Winfo.duration == 1) ele->deWskill();
		if (ele->Einfo.duration == 1) ele->deEskill();
		if (ele->Rinfo.duration == 1) ele->deRskill();
		if (ele->Qinfo.duration != 0) --ele->Qinfo.duration;
		if (ele->Winfo.duration != 0) --ele->Winfo.duration;
		if (ele->Einfo.duration != 0) --ele->Einfo.duration;
		if (ele->Rinfo.duration != 0) --ele->Rinfo.duration;
	}

	//bullet
	int cnt = 0;
	for (auto ele : vector_bullet) {
		if (!ele->bulletMove()) {
			vector_bullet.erase(cnt);
			--cnt;
		}
		++cnt;
	}

	//attack and skill
	for (auto ele : vector_hero) {
		if (ele->actionState.c != 'N' && ele->actionState.aim->curLifeValue == 0) {
			ele->setAction(NULL, 'N');
		}
		switch (ele->actionState.c) {
		case 'A':
			break;
		case 'Q':
			if (ccpDistance(ele->getPosition(), ele->actionState.aim->getPosition()) <= ele->Qinfo.range) {
				ele->Qskill();
			}
			else {
				ele->move(ele->actionState.aim->getPosition());
			}
			break;
		case 'W':
			if (ccpDistance(ele->getPosition(), ele->actionState.aim->getPosition()) <= ele->Winfo.range) {
				ele->Wskill();
			}
			else {
				ele->move(ele->actionState.aim->getPosition());
			}
			break;
		case 'E':
			if (ccpDistance(ele->getPosition(), ele->actionState.aim->getPosition()) <= ele->Einfo.range) {
				ele->Eskill();
			}
			else {
				ele->move(ele->actionState.aim->getPosition());
			}
			break;
		case 'R':
			if (ccpDistance(ele->getPosition(), ele->actionState.aim->getPosition()) <= ele->Rinfo.range) {
				ele->Rskill();
			}
			else {
				ele->move(ele->actionState.aim->getPosition());
			}
			break;
		case 'N':
			break;
		}
	}
	for (auto ele : vector_unit) {
		if (ele->actionState.c == 'A') {
			if (ccpDistance(ele->getPosition(), ele->actionState.aim->getPosition()) <= ele->attackRange) {
				ele->attack(ele->actionState.aim);
			}
			else {
				ele->move(ele->actionState.aim->getPosition());
			}
		}
	}


	//die
	cnt = 0;
	for (auto ele : vector_unit) {
		if (ele->curLifeValue <= 0) {
			vector_unit.erase(cnt);
			--cnt;
			if (ele->unitType == "warrior") {

			}
			else {
				ele->cleanup();
			}
		}
		++cnt;
	}

	//create minions
	if (_count % 20 * 60 == 10 * 60) {

	}
	if (_count % 20 * 60 == 11 * 60) {

	}
	if (_count % 20 * 60 == 12 * 60) {

	}
	if (_count % 20 * 60 == 13 * 60) {

	}
	if (_count % 20 * 60 == 14 * 60 && _count >= 70 * 60) {

	}




}