#pragma once
#include "data.h"
#include "Snake.h"


class Map : public Snake
{
public:
	explicit  Map(const int& height, const  int& width);
	~Map();

	void init();
	void CleanMap();
	void fillMap();
	void drawMap();

private:
	void release();
};

