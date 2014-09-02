#include "Detections.h"
#include "tanks.h"


Detections* Detections::instance = nullptr;

Detections* Detections::getInstance(){
	if (!instance){
		instance = new Detections();
	}
	return instance;
}

bool Detections::BulletBullet(Bullet* b1, Bullet* b2){
	auto p1 = b1->getPosition();
	auto p2 = b2->getPosition();
	auto s = b1->getBulletSize();
	auto rec1 = Rect(p1.x - s.width, p1.y - s.height, s.width, s.height);
	auto rec2 = Rect(p2.x - s.width, p2.y - s.height, s.width, s.height);

	if (rec1.intersectsRect(rec2)){
		return true;
	}
	return false;
}

bool Detections::BulletBullet(Bullet* b1, Enemy* e1){
	auto p1 = b1->getPosition();
	auto p2 = e1->getPosition();
	
	auto s1 = b1->getBulletSize();
	auto s2 = e1->getRect();
	auto rec1 = Rect(p1.x - s1.width, p1.y - s1.height, s1.width, s1.height);

	if (rec1.intersectsRect(*s2)){
		return true;
	}
	return false;
}

bool Detections::BulletBullet(Bullet* b){
	auto p = b->getPosition();
	auto tan = tanks::getInstance()->getBoundingBox();
	auto s = b->getBulletSize();
	auto rec1 = Rect(p.x - s.width, p.y - s.height, s.width, s.height);
	if (rec1.intersectsRect(tan)){
		return true;
	}
	return false;
}