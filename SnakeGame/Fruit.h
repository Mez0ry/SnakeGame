#pragma once
#include "data.h"
#include <random>
 
 

class Fruit 
{
public:
	Fruit();
	~Fruit();

	void setup();
	void spawnFruit();
	void randomPosition(int& row, int& col, int index);
	point& getFruitCoord(int index);

	int getFruitCoordX(int index);
	int getFruitCoordY(int index);

private:
	static inline std::unique_ptr<point* []> FruitCoord = std::make_unique<point* []>(EntsSize);

};

