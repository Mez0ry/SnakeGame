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
	 void CheckSnakeOnFruit();
	 
	void SnakeMovesLogic();
protected:
	point* SnakeCoord;
private:
	
	 
};

