#ifndef SNAKE
#define SNAKE
#include "data.h"
#include <conio.h>
#include "Fruit.h"
class Snake
{
private:
	char m_SnakeSymbol = '0';
	SnakeMoving  m_CurrSnakeMove;
	std::unique_ptr<point> m_SnakeCoords = std::make_unique<point>();
public:
	Snake();
	~Snake() {  }

	void Setup(uint8_t** MapState, Fruit& fruit);
	void SpawnSnake();
	void SnakeMovesLogic();

	bool isFruit();

	bool& get_GameVarState() { return m_bGameOver; }
	SnakeMoving& get_MoveType() { return m_CurrSnakeMove; }
private:
	bool m_bGameOver;
	uint8_t** m_MapState;
	Fruit* m_Fruit;
};

#endif // !SNAKE