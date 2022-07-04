#include "Map.h"

Map::Map(const int& row,const int& col)
{
	mtrx.row = row; 
	mtrx.col = col;
	mapPoints = new uint8_t * [mtrx.row]; 
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
	for (int i = 0; i < mtrx.row; i++) {
		for (int j = 0; j < mtrx.col; j++) {
			if (i == 0) mapPoints[mtrx.row - mtrx.row][j] = borderSymbol;
			if (i == mtrx.row - 1) mapPoints[mtrx.row - mtrx.row][j] = borderSymbol;
			else { mapPoints[i][mtrx.col - 1] = borderSymbol; mapPoints[i][mtrx.col - mtrx.col] = borderSymbol;  mapPoints[mtrx.row - 1][j] = borderSymbol; }
		}
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
