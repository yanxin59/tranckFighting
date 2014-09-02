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
Point Maps::getGID(Vec2 ver){
	int x = ver.x / m_Map->getTileSize().width;
	int y = ((m_Map->getMapSize().height * m_Map->getTileSize().height) - ver.y) / m_Map->getTileSize().height;
	return Point(x, y);
}