#pragma once
#include "data.h"
#include "Snake.h"


class Map : public Snake
{
public:
	Map(int height, int width);
	Map();

	~Map();
	void init();
	void loadMap();
	void fillMap();
	void release();

	void drawMap();

private:
	 
	Snake* snake;
	 
};

