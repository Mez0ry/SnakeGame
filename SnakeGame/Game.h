#pragma once
#include <iostream>
#include <vector>
#include "data.h"
#include "Map.h"
#include "Snake.h"
#include "Fruit.h"

class Game
{
public:
	Game();
	~Game();

	void setConsole();
	void play();
	void gameOver();

	void handleEvents();

	void update();
	void exit();
 

private:
	Snake* EntSnake;
	Fruit* fruit[EntsSize];

	Map* map;
};

