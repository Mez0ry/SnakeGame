#include "Map.h"

Map::Map(const int& row,const int& col)
{
	mtrx.row = row; // 26
	mtrx.col = col;// 36
	mapPoints = new uint8_t * [mtrx.row]; // x = 20;
	for (int i = 0; i < mtrx.row; i++) mapPoints[i] = new uint8_t[mtrx.col];

}

 
Map::~Map()
{
	this->release();

}

void Map::init()
{
	 
	CleanMap();
	fillMap();
 
}

void Map::CleanMap()
{
	 
	for (int i = 0; i < mtrx.row; i++) {
		for (int j = 0; j < mtrx.col; j++) {
			mapPoints[i][j] = ' ';
			 
		}
	 }

}


void Map::fillMap()
{
	bool end = false;
	int x{}, y{};
	while (y < mtrx.col){
		mapPoints[x][y] = borderSymbol;
		y++;
	}
	 
	if (y >= mtrx.col) {
		y = mtrx.col - 1;
 }

	while (x < mtrx.row) {
		
		mapPoints[x][y] = borderSymbol;
		x++;
	}
	if (x >= mtrx.row) x = mtrx.row - 1;

	while (y >-1) {

		mapPoints[x][y] = borderSymbol;
		if(y >-1)
		y--;
	}

	if (y <0) {
		y = 0;
	}

	while (x > -1) {

		mapPoints[x][y] = borderSymbol;
		x--;
	}
}

void Map::release()
{
	for (int i = 0; i < mtrx.row; i++)  delete [] mapPoints[i];
}


void Map::drawMap()
{
	for (int i = 0; i < mtrx.row; i++) {
		for (int j = 0; j < mtrx.col; j++) {
			std::cout <<mapPoints[i][j];
		}
		std::cout << '\n';
	}
	std::cout <<static_cast<char>('\n\n') << "    Score: " << TotalScore << '\n';
}
