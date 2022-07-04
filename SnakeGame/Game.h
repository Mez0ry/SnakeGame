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
	void play();
private:
	void setConsole();
	void gameOver();
	void handleEvents();
	void update();

	Snake* EntSnake;
	Fruit* fruit[EntsSize];

	Map* map;
};

