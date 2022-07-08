#pragma once
#include <vector>
#include "data.h"
#include "Map.h"
#include "Snake.h"
#include "Fruit.h"
#include <stack>

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

	bool bGameLoop = false;
	Snake* m_EntSnake;
	Fruit* m_fruit[EntsSize];

	Map* m_map;
 
	std::stack<int> m_gameScores;

	enum class GameOverState : char {
		SUCCESS = 'S', PRINT = 'P' , FAILURE = 'F'
	};

};

