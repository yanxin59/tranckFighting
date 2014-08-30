#include "Detections.h"


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
	auto s = b1->getSp()->getContentSize();
	auto rec1 = Rect(p1.x - s.width, p1.y - s.height, s.width, s.height);
	auto rec2 = Rect(p2.x - s.width, p2.y - s.height, s.width, s.height);

	if (rec1.intersectsRect(rec2)){
		log("2");
		return true;
	}
	return false;
}