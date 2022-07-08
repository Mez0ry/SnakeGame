#pragma once
#include "data.h"
#include <conio.h>
#include "Fruit.h"


class Snake
{
private:
	char SnakeSymbol = '0';
	SnakeMoving  CurrSnakeMove;
	std::unique_ptr<point> m_SnakeCoords = std::make_unique<point>();

public:
	Snake();
	~Snake();

	void Setup(uint8_t** MapState);
	void SpawnSnake();
	void SnakeMovesLogic();

	bool isFruit();
	bool& GetGameVarState() { return *bGameOver; }

	SnakeMoving& GetTypeMove() { return CurrSnakeMove; }
	 
private:
	std::unique_ptr<bool> bGameOver = std::make_unique<bool>();
	uint8_t** m_MapState = nullptr;
 	std::unique_ptr<Fruit> fruit = std::make_unique<Fruit>();
};

