#include "Map.h"

Map::Map(const int& row,const int& col)
{
 
	mapPoints = new uint8_t * [row];
	for (int i = 0; i < row; i++) mapPoints[i] = new uint8_t[col];

}

 
Map::~Map()
{
	this->release();

}

void Map::init()
{
	 
	CleanMap();
	FillMap();
 
}

void Map::CleanMap()
{
	 
	for (int i = 0; i < g_MapRows; i++) {
		for (int j = 0; j < g_MapCols; j++) {
			mapPoints[i][j] = ' ';
			 
		}
	 }

}


void Map::FillMap()
{
	for (int i = 0; i < g_MapRows; i++) {
		for (int j = 0; j < g_MapCols; j++) {
			if (i == 0) mapPoints[g_MapRows - g_MapRows][j] = borderSymbol;
			if (i == g_MapRows - 1) mapPoints[g_MapRows - g_MapRows][j] = borderSymbol;
			else { mapPoints[i][g_MapCols - 1] = borderSymbol; mapPoints[i][g_MapCols  - g_MapCols] = borderSymbol;  mapPoints[g_MapRows - 1][j] = borderSymbol; }
		}
	}
}

void Map::release()
{
	for (int i = 0; i < g_MapRows; i++)  delete[]  mapPoints[i];
	delete[] mapPoints;
}


void Map::DrawMap()
{
	for (int i = 0; i < g_MapRows; i++) {
		for (int j = 0; j < g_MapCols; j++) {
			std::cout <<mapPoints[i][j];
		}
		std::cout << '\n';
	}
	std::cout <<static_cast<char>('\n\n') << "    Score: " << g_TotalScore << '\n';
}
