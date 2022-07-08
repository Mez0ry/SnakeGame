#include "Snake.h"
 
Snake::Snake()
{
	CurrSnakeMove = {};
	*bGameOver = false;
}

Snake::~Snake()
{
 
}

void Snake::Setup(uint8_t** MapState)
{
	m_SnakeCoords->x = g_MapRows / 2;
	m_SnakeCoords->y = g_MapCols / 2;
	this->m_MapState = MapState;
}

void Snake::SpawnSnake()
{
	bool once = false;
	for (int row = 0; row < g_MapRows; row++) {
		for (int col = 0; col < g_MapCols; col++) {
			if (row == m_SnakeCoords->x && col == m_SnakeCoords->y && m_MapState != nullptr && !once) {
				m_MapState[row][col] = SnakeSymbol; once = true;
			}

			else if (m_SnakeCoords->x + 1 == g_MapRows || m_SnakeCoords->y + 1 == g_MapCols || m_SnakeCoords->x == g_MapRows - g_MapRows || m_SnakeCoords->y == g_MapCols - g_MapCols) {
				(*bGameOver) = true;
			}
			else if(isFruit()){}
		}
	}
} 

 bool Snake::isFruit()
{	 
	 for (int i = 0; i < EntsSize; i++) {
		 if (m_SnakeCoords->x == fruit->GetFruitCoord(i).x && m_SnakeCoords->y == fruit->GetFruitCoord(i).y) {
			 m_MapState[fruit->GetFruitCoord(i).x][fruit->GetFruitCoord(i).y] = ' ';
			 g_TotalScore += fruit->GetFruitScore();
			 fruit->RandomPosition(fruit->GetFruitCoord(i).x, fruit->GetFruitCoord(i).y, i);
			 return true;
		 }
		  
	 }
	 return false;
}

 
 

void Snake::SnakeMovesLogic()
{
	switch (CurrSnakeMove) {
		case static_cast<SnakeMoving>(SnakeMoving::LEFT): {
			m_SnakeCoords->y--;
			break;
		}//
		case static_cast<SnakeMoving>(SnakeMoving::RIGHT): {
			m_SnakeCoords->y++;
			break;
		}//
		case static_cast<SnakeMoving>(SnakeMoving::UP): {
			m_SnakeCoords->x--;
			break;
		}//
		case  static_cast<SnakeMoving>(SnakeMoving::DOWN): {
			m_SnakeCoords->x++;
			break;
		}//
		 
	}

}
