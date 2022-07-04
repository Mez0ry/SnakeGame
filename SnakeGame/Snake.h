#pragma once
#include "data.h"
#include <conio.h>
#include "Fruit.h"
 

class Snake : public Fruit
{
public:
	Snake();
	~Snake();

	void setup();
	void spawnSnake();
	bool isFruit();
	 
	void SnakeMovesLogic();
 
private:
 
	std::unique_ptr<point> ptrSnakeCoords = std::make_unique<point>();

};

