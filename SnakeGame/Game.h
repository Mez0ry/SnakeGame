#ifndef GAME
#define GAME
#include <vector>
#include "data.h"
#include "Map.h"
#include "Snake.h"
#include "Fruit.h"
#include <stack>

class Game 
{
private:
	bool m_bGameLoop = false;
	std::stack<int> m_gameScores;
public:
	Game();
	~Game();
	void play();
private:
	void SetConsole();
	void GameOver();
	void HandleEvents();
	void Update();
 
	Snake m_Snake;
	Fruit m_Fruit;
	Map m_Map;

	enum class GameOverState : char {
		SUCCESS = 'S', PRINT = 'P' , FAILURE = 'F'
	};
};

#endif // !GAME