#include "Fruit.h"

Fruit::Fruit()
{
	for(int i = 0;i< EntsSize;i++)
	FruitCoord[i] = new point();
}

Fruit::~Fruit()
{
	this->release();
}

void Fruit::setup()
{
	std::random_device sc;
	std::mt19937 ScoreGen(sc());
	std::uniform_int_distribution<int> Score(2, 24);
	Score4Fruit = Score(ScoreGen);
	for (int i = 0; i < EntsSize; i++)
		randomPosition(FruitCoord[i]->x, FruitCoord[i]->y);
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

 

void Fruit::randomPosition(int& row, int& col)
{
	std::random_device rdX;    
	std::mt19937 genX(rdX()); 
	std::uniform_int_distribution<int> fruitXrandomNum(2, 24);
	row = fruitXrandomNum(genX);

	std::random_device rdY;   
	std::mt19937 genY(rdY());   
	std::uniform_int_distribution<int> fruitYrandomNum(2, 34);
	col = fruitYrandomNum(genY);


}

 
	 
 

void Fruit::release()
{
	for (int i = 0; i < EntsSize; i++)  free((void*) FruitCoord[i])  ;
}
