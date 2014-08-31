#include "MapLayer.h"


bool MapLayer::init(){
	if (!Layer::init()){
		return false;
	}
	TMXTiledMap* map = TMXTiledMap::create("mapNew.tmx");
	this->addChild(map);
	


	return true;
}

