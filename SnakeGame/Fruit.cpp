#include "Fruit.h"

Fruit::Fruit()
{
	m_MapArr = {};

	for (int i = 0; i < EntsSize; i++)
		m_ptrFruitCoord[i] = new point();
 
}

Fruit::~Fruit()
{
 
}

void Fruit::Setup(uint8_t** MapState)
{
 
	std::random_device sc;
	std::mt19937 ScoreGen(sc());
	std::uniform_int_distribution<int> Score(2, 24);
	*m_ptrFruitScore = Score(ScoreGen);
	for (int i = 0; i < EntsSize; i++)
		RandomPosition(m_ptrFruitCoord[i]->x, m_ptrFruitCoord[i]->y, i);

	this->m_MapArr = MapState;
}


void Fruit::SpawnFruit()
{
	for (int i = 0; i < g_MapRows; i++) {
		for (int j = 0; j < g_MapCols; j++) {
			for (int fruit = 0; fruit < EntsSize; fruit++) {
				if (i == m_ptrFruitCoord[fruit]->x && j == m_ptrFruitCoord[fruit]->y)
					m_MapArr[i][j] = FruitSymbol;
			}
		}
	}
	 
}

 

 

void Fruit::RandomPosition(int& row, int& col, int index)
{
	for (int i = 0; i < EntsSize; i++) {
		if (i == index) {
			std::random_device rdX;
			std::mt19937 genX(rdX());
			std::uniform_int_distribution<int> fruitXrandomNum((g_MapRows - g_MapRows)+5, g_MapRows -5);
			 row = fruitXrandomNum(genX);

			std::random_device rdY;
			std::mt19937 genY(rdY());
			std::uniform_int_distribution<int> fruitYrandomNum((g_MapCols - g_MapCols) + 5, g_MapCols-5);
			 col = fruitYrandomNum(genY);
		}
	}
}

point& Fruit::GetFruitCoord(int index)
{

	for (int i = 0; i < EntsSize; i++) {
		if (i == index) { return *m_ptrFruitCoord[i]; }
	}
	return *m_ptrFruitCoord[0];
}

 