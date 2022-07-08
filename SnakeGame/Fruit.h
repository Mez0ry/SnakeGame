#pragma once
#include "data.h"
#include <random>

 

class Fruit 
{
private:
	char  FruitSymbol = '+';
	static inline std::unique_ptr<point* []> m_ptrFruitCoord = std::make_unique<point* []>(EntsSize);
public:
	Fruit();
	~Fruit();

	void Setup(uint8_t** MapState);
	void SpawnFruit();
	void RandomPosition(int& row, int& col, int index);

	point& GetFruitCoord(int index);
	int GetFruitScore() { return *m_ptrFruitScore; }

private:
	static inline  std::unique_ptr<int> m_ptrFruitScore = std::make_unique<int>();
	uint8_t** m_MapArr;
};

