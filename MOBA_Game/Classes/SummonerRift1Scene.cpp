#include"cocos2d.h"
#include"SimpleAudioEngine.h"
#include"HeroBase.h"
#include"SummonerRift1Scene.h"
using namespace CocosDenshion;
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

	_tileMap = TMXTiledMap::create("MyMap2.tmx");
	_tileMap->setAnchorPoint(Vec2::ZERO);
	_tileMap->setPosition(Vec2::ZERO);
	auto _collidable = _tileMap->getLayer("collidable");
	_collidable->setVisible(false);
	this->addChild(_tileMap);//��ɶԵ�ͼ������/


	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("birth1.plist");
	auto animation1 = Animation::create();//������Ч
	for (int i = 0; i < 5; ++i) {
		std::string szName = StringUtils::format("birth%d.png", i);
		animation1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(szName));
	}
	animation1->setDelayPerUnit(3.0f / 20.0f);
	auto animate1 = Animate::create(animation1);
	auto fadeout = FadeOut::create(4.0);
	auto _birth = Sprite::createWithSpriteFrameName("birth0.png");
	_birth->setPosition(Vec2(284,500));
	this->addChild(_birth);
	_birth->runAction(animate1);
	_birth->runAction(fadeout);

	_player = HeroBase::create("skeleton1.png");
	_player->Name = "skeleton";
	_player->setPosition(284,308);//��ɶ�Ӣ�۵�����
	_tileMap->addChild(_player, 1);
	auto animate = _player->getAnimateByName("skeleton_move_", 0.3f, 4);
	auto repeatanimate = RepeatForever::create(animate);
	_player->runAction(repeatanimate);

	auto _shop = Button::create("shop.png");
	_shop->setPosition(Vec2(visibleSize.width*0.2, visibleSize.height*0.1));
	_shop->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			SimpleAudioEngine::getInstance()->playEffect("press.mp3", false);
		}
	});
	this->addChild(_shop);
	_shop->setTag(1);

	Sprite *_frame = Sprite::create("headframe.png");
	_frame->setPosition(visibleSize.width *0.4, visibleSize.height *0.1);
	this->addChild(_frame);
	_frame->setTag(2);


	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseDown = CC_CALLBACK_1(SummonerRift1Scene::onMouseDown, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_mouseListener, this);
	this->scheduleUpdate();
	return true;
}

void SummonerRift1Scene::onMouseDown(Event*event) {
	EventMouse *e = (EventMouse*)event;
	EventMouse::MouseButton mousebutton = e->getMouseButton();
	if (mousebutton == EventMouse::MouseButton::BUTTON_RIGHT) {
		Vec2 temp1 = Vec2(e->getCursorX(), e->getCursorY());
		Vec2 temp = this->convertToNodeSpace(temp1);

		Vec2 tileCoord = tileCoordForPosition(temp);
		auto _collidable = _tileMap->getLayer("collidable");
		int tileGid;
		tileGid = _collidable->getTileGIDAt(tileCoord);
		if (tileGid) {
			Value properties = _tileMap->getPropertiesForGID(tileGid);
			auto map = properties.asValueMap();
			std::string value = map.at("collidable").asString();
			if (value.compare("true") == 0) {
				return;
			}
		}


		if (_player->getPosition().x > temp.x) {
			if (_player->isFlippedX() == true)
				_player->setFlippedX(false);
		}
		else {
			if (_player->isFlippedX() == false)
				_player->setFlippedX(true);
		}
		if (_player->getNumberOfRunningActions() == 0) {
			this->playerMover(temp);

		}
		else
		{
			//��������������ж�������ֹͣ���鶯���Ͳ㶯������ִ���ƶ�����
			_player->stopAllActions();
			this->stopAllActions();
			this->playerMover(temp);
		}
	}
}



void SummonerRift1Scene::setViewpointCenter(float duration, Vec2 position) {
	int x = MAX(position.x, _scWidth / 2);
	int y = MAX(position.y, _scHeight / 2);
	x = MIN(x, _tileMap->getMapSize().width * _tileMap->getTileSize().width - _scWidth / 2);
	y = MIN(y, _tileMap->getMapSize().height * _tileMap->getTileSize().height - _scHeight / 2);
	Point actualPosition = Vec2(x, y);
	Point centerofView = Vec2(_scWidth / 2, _scHeight / 2);
	Point viewPoint = centerofView - actualPosition;
	this->runAction(MoveTo::create(duration, viewPoint));
	Vec2 temp=this->getPosition();
	for (int i = 1; i <= 2; i++) {
		Node*node = this->getChildByTag(i);
		Vec2 aim = node->getPosition() + (temp - viewPoint);
		node->stopAllActions();
		node->runAction(MoveTo::create(duration, aim));
		Vec2 test = node->getPosition();
	}
}

Vec2 SummonerRift1Scene::tileCoordForPosition(Point position) {
	// CC_CONTENT_SCALE_FACTOR Retina����2�����򷵻�1
	// ���λ�õ�x���Ե�ͼ�Ŀ��õ����ǵ�ͼ����ĵڼ������ӣ�tile��
	// ��ͼ����㣺26[����] * 64[ͼ��Ŀ�] = 1680[��ͼ��]
	// ���羫���ڵ�x������640���������ڵ�ͼ�ĸ��Ӽ��㣺640[����λ��] / 64[ͼ��Ŀ�] = 10 [����]
	int x = (int)(position.x / (_tileMap->getTileSize().width / CC_CONTENT_SCALE_FACTOR()));
	// ���λ�õ�y���Ե�ͼ�ĸߣ��õ����ǵ�ͼ����ڼ������ӣ�tile����
	// ������Ϊcocos2d-x��y�ᣨ���½ǣ���TileMap��y�ᣨ���Ͻǣ����෴������ʹ�õ�ͼ�ĸ߶ȼ�ȥ���λ�õ�y
	float pointHeight = _tileMap->getTileSize().height / CC_CONTENT_SCALE_FACTOR();
	int y = (int)((_tileMap->getMapSize().height * pointHeight - position.y) / pointHeight);
	return Vec2(x, y);
}

float SummonerRift1Scene::getPlayerMoveTime(Vec2 startPos, Vec2 endPos, float speed) {//�ٶ���ָͨ��ÿһ����Ƭ���ʱ��
	Vec2 tileStart = tileCoordForPosition(startPos);
	Vec2 tileEnd = tileCoordForPosition(endPos);
	float duration = speed * sqrtf((tileStart.x - tileEnd.x) * (tileStart.x - tileEnd.x)
		+ (tileStart.y - tileEnd.y) * (tileStart.y - tileEnd.y));
	return duration;
}

void SummonerRift1Scene::playerMover(Point position) {
	std::string moveName = _player->Name;
	moveName.append("_move_");
	auto animate = _player->getAnimateByName(moveName, 0.05f, 4);
	auto repeatanimate = RepeatForever::create(animate);
	_player->runAction(repeatanimate);
	float duration = getPlayerMoveTime(_player->getPosition(), position, 0.4f);
	auto moveTo = MoveTo::create(duration, position);
	std::string endName = _player->Name;
	(endName.append("1")).append(".png");
	auto sequence = Sequence::create(moveTo, CallFunc::create([=] {
		// ֹͣ����
		_player->stopAction(repeatanimate);
		_player->setTexture(endName);
	}), nullptr);
	_player->runAction(sequence);
	this->setViewpointCenter(duration, position);
}

void SummonerRift1Scene::update(float delta) {
	/*Node*node = this->getChildByTag(1);
	Vec2 temp = this->getPosition();
	node->setPosition(temp.x+_scWidth/2,temp.y+_scHeight/2);
	node = this->getChildByTag(1);
	node->setPosition(temp);
	node->setPosition(_scWidth *0.4, _scHeight *0.1);*/
}
