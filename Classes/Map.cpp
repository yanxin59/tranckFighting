#include "Map.h"
bool Maps::init(){
	if(!Layer::init()){
		return false;
	}
	TMXTiledMap* map = TMXTiledMap::create("mapNew.tmx");
	this->addChild(map);
	m_Map = map;
	m_Map->retain();
	m_bg = map->getLayer("bg");
	m_bg->retain();
	m_iron = map->getLayer("iron");
	m_iron->retain();
	m_bird = map->getLayer("bird");
	m_bird->retain();
	return true;
}