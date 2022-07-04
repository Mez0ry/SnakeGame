#ifndef FRUIT
#define FRUIT
#include "data.h"
#include "randomize.hpp"
class Fruit 
{
private:
	char  m_FruitSymbol = '+';
	point m_pFruitCoord[FRUIT_SIZE];
public:
	Fruit();
	~Fruit(){ }

	void Setup(uint8_t** MapState);
	void SpawnFruit();
	void RandomPosition(int& row, int& col);

	point& get_FruitCoord(const int& index);
	int get_Score() { return m_FruitScore; }
private:
	int m_FruitScore;
	uint8_t** m_Map;
};

#endif // !FRUIT
