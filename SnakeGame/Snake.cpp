#include "Snake.h"
 
Snake::Snake() : m_bGameOver(false), m_CurrSnakeMove() , m_MapState(nullptr)
{
	this->m_Fruit = NULL;
}

void Snake::Setup(uint8_t** MapState, Fruit& fruit)
{
	this->m_Fruit = &fruit;
	this->m_MapState = MapState;

	m_SnakeCoords->x = g_MapRows / 2;
	m_SnakeCoords->y = g_MapCols / 2;
}

void Snake::SpawnSnake()
{
	for (size_t row_index = 0; row_index < g_MapRows; ++row_index) {
		for (size_t col_index = 0; col_index < g_MapCols; ++col_index) {
			if (row_index == m_SnakeCoords->x && col_index == m_SnakeCoords->y) {
				m_MapState[row_index][col_index] = m_SnakeSymbol;
			}

			else if (m_SnakeCoords->x + 1 == g_MapRows || m_SnakeCoords->y + 1 == g_MapCols || m_SnakeCoords->x == g_MapRows - g_MapRows || m_SnakeCoords->y == g_MapCols - g_MapCols) {
				m_bGameOver = true;
			}
			else {
				if (isFruit()) {}
			} 
		}
	}
} 

 bool Snake::isFruit()  
{	 
	 for (size_t fruit_index = 0; fruit_index < FRUIT_SIZE; fruit_index++) {
		 if (m_SnakeCoords->x == m_Fruit->get_FruitCoord(fruit_index).x && m_SnakeCoords->y == m_Fruit->get_FruitCoord(fruit_index).y) {
			 m_MapState[m_Fruit->get_FruitCoord(fruit_index).x][m_Fruit->get_FruitCoord(fruit_index).y] = ' ';
			 g_TotalScore += m_Fruit->get_Score();
			 m_Fruit->RandomPosition(m_Fruit->get_FruitCoord(fruit_index).x, m_Fruit->get_FruitCoord(fruit_index).y);
			 return true;
		 }
	 }
	 return false;
}

void Snake::SnakeMovesLogic()
{
	switch (m_CurrSnakeMove) {
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
