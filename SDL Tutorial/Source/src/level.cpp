#include "level.h"
#include "graphics.h"

#include "SDL.h"

Level::Level() {}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) :
	_mapName(mapName),
	_spawnPoint(spawnPoint),
	_size(Vector2(0,0))

{
	this->loadMap(mapName, graphics);
}

Level::Level() {

}

void Level::loadMap(std::string mapName, Graphics &graphics) {
	//TEMPORARY CODE TO LOAD THE BACKGROUND
	this->_backgroundTetxture = 
		SDL_CreateTextureFromSurface(graphics.getRenderer(), 
		graphics.loadImage("content/background/bkBlue.png"));
	this->_size = Vector2(1280, 960);
}

void Level::update(int elapsedTime) {

}

void Level::draw(Graphics &graphics) {
	//Draw the background
	SDL_Rect sourceRect = {};
}