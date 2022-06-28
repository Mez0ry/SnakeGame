#pragma once
#include "data.h"
#include <random>
 
  inline  point* FruitCoord[EntsSize];

class Fruit 
{
public:
	Fruit();
	~Fruit();

	void setup();
	void spawnFruit();
	void randomPosition(int& row,int& col);
	void release();
private:

 

};

