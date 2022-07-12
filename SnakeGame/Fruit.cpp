#include "Fruit.h"
 
Fruit::Fruit() : m_Map(nullptr)
{
	for (size_t read_index = 0; read_index < FRUIT_SIZE; read_index++) {
		RandomPosition(m_pFruitCoord[read_index].x, m_pFruitCoord[read_index].y);
	}

	std::random_device sc;
	std::mt19937 ScoreGen(sc());
	std::uniform_int_distribution<int> Score(2, 24);
	this->m_FruitScore = Score(ScoreGen);

}

void Fruit::Setup(uint8_t** MapState)
{
	this->m_Map = MapState;
}

void Fruit::SpawnFruit()
{
	for (size_t row_index = 0; row_index < g_MapRows; ++row_index) {
		for (size_t col_index = 0; col_index < g_MapCols; ++col_index) {
			for (size_t fruit_index = 0; fruit_index < FRUIT_SIZE; ++fruit_index) {

				if (row_index == m_pFruitCoord[fruit_index].x && col_index == m_pFruitCoord[fruit_index].y)
					m_Map[row_index][col_index] = m_FruitSymbol;
			}
		}
	}
}

void Fruit::RandomPosition(int& row, int& col)  
{
			std::random_device rdX;
			std::mt19937 genX(rdX());
			std::uniform_int_distribution<int> fruitXrandomNum((g_MapRows - g_MapRows)+5, g_MapRows -5);
			 row = fruitXrandomNum(genX);
		 
			std::random_device rdY;
			std::mt19937 genY(rdY());
			std::uniform_int_distribution<int> fruitYrandomNum((g_MapCols - g_MapCols) + 5, g_MapCols-5);
			 col = fruitYrandomNum(genY);
}

point& Fruit::get_FruitCoord(const int& index)
{
	if (index < 0 || index >= FRUIT_SIZE)
		throw std::out_of_range{ "Fruit::GetFruitCoord() out of range " };
	return m_pFruitCoord[index];

}

 