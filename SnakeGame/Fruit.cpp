#include "Fruit.h"

Fruit::Fruit()
{
	for (int i = 0; i < EntsSize; i++)
		FruitCoord[i] = new point();

	 
}

Fruit::~Fruit()
{
 
}

void Fruit::setup()
{
 

	std::random_device sc;
	std::mt19937 ScoreGen(sc());
	std::uniform_int_distribution<int> Score(2, 24);
	FruitScore = Score(ScoreGen);
	for (int i = 0; i < EntsSize; i++)
		randomPosition(FruitCoord[i]->x, FruitCoord[i]->y, i);
}


void Fruit::spawnFruit()
{
	for (int i = 0; i < mtrx.row; i++) {
		for (int j = 0; j < mtrx.col; j++) {
			for (int fruit = 0; fruit < EntsSize; fruit++) {
				if (i == FruitCoord[fruit]->x && j == FruitCoord[fruit]->y)
					mapPoints[i][j] = FruitSymbol;
			}
		}
	}
	 
}

 

 

void Fruit::randomPosition(int& row, int& col, int index)
{
	for (int i = 0; i < EntsSize; i++) {
		if (i == index) {
			std::random_device rdX;
			std::mt19937 genX(rdX());
			std::uniform_int_distribution<int> fruitXrandomNum((MapRows- MapRows)+5, MapRows-5);
			 row = fruitXrandomNum(genX);

			std::random_device rdY;
			std::mt19937 genY(rdY());
			std::uniform_int_distribution<int> fruitYrandomNum((MapCols - MapCols) + 5, MapCols-5);
			 col = fruitYrandomNum(genY);
		}
	}
}

point& Fruit::getFruitCoord(int index)
{

	for (int i = 0; i < EntsSize; i++) {
		if (i == index) { return *FruitCoord[i]; }
	}
	return *FruitCoord[0];
}

int Fruit::getFruitCoordX(int index)
{
	 
	for (int i = 0; i < EntsSize; i++) {
		if (i == index) { return FruitCoord[i]->x; }
	 }

	return 0;
}

int Fruit::getFruitCoordY(int index)
{
	for (int i = 0; i < EntsSize; i++) {
		if (i == index) { return FruitCoord[i]->y; }
	}

	return 0;
}

 
	 
 
 