#pragma once
#include "data.h"
#include "Snake.h"


class Map : public Snake
{
public:
	explicit  Map(const int& height, const  int& width);
	~Map();

	void init();
	void drawMap();

private:
	void CleanMap();
	void fillMap();
	void release();
};

