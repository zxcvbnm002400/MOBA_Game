#include"cocos2d.h"
#include"SimpleAudioEngine.h"
#include"HeroBase.h"
#include"SummonerRift1Scene.h"
USING_NS_CC;

Scene* SummonerRift1Scene::createScene() {
	auto scene = Scene::create();
	auto layer = SummonerRift1Scene::create();
	scene->addChild(layer);
	return scene;
}

bool SummonerRift1Scene::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	_scWidth = visibleSize.width;
	_scHeight = visibleSize.height;
	_tileMap = TMXTiledMap::create("mobamap4.tmx");
	_tileMap->setAnchorPoint(Vec2::ZERO);
	_tileMap->setPosition(Vec2::ZERO);
	this->addChild(_tileMap);//完成对地图的设置
	_player = Sprite::create("issacnew.png");
	_player->setPosition(_scWidth / 2, _scHeight / 2);//完成对英雄的设置
	_tileMap->addChild(_player, 3);
	auto _mouseListener= EventListenerMouse::create();
	_mouseListener->onMouseDown=CC_CALLBACK_1(SummonerRift1Scene::onMouseDown, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_mouseListener, this);
	return true;
}

void SummonerRift1Scene::onMouseDown(Event*event) {
	EventMouse *e = (EventMouse*)event;
	EventMouse::MouseButton mousebutton=e->getMouseButton();
	if (mousebutton == EventMouse::MouseButton::BUTTON_RIGHT) {
		Vec2 temp = Vec2(e->getCursorX(), e->getCursorY());
		this->move(temp);
	}
}

void SummonerRift1Scene::move(Vec2 destination) {
	Vec2 nodeLocation = this->convertToNodeSpace(destination);
	if (_player->getPosition().x < nodeLocation.x) {
		if (!_player->isFlippedX())
			_player->setFlippedX(true);
	}
	else {
		if (_player->isFlippedX())
			_player->setFlippedX(false);
	}
	_player->setPosition(nodeLocation);
	this->setViewpointCenter(_player->getPosition());
}

void SummonerRift1Scene::setViewpointCenter(Vec2 position) {
	int x = MAX(position.x, _scWidth/2);
	int y = MAX(position.y, _scHeight/2);
	x = MIN(x, _tileMap->getMapSize().width * _tileMap->getTileSize().width - _scWidth / 2);
	y = MIN(y, _tileMap->getMapSize().height * _tileMap->getTileSize().height - _scHeight / 2);
	Point actualPosition = Vec2(x, y);
	Point centerofView = Vec2(_scWidth / 2, _scHeight / 2);
	Point viewPoint = centerofView - actualPosition;
	this->setPosition(viewPoint);
}
