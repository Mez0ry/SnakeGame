#pragma once
#include "data.h"
  
 

class Map 
{
private:
	const char borderSymbol = '*';
	uint8_t** mapPoints;
public:
	explicit  Map(const int& height, const  int& width);
	~Map();

	void init();
	void DrawMap();

	uint8_t** GetMap() { return mapPoints; }
private:
	void CleanMap();
	void FillMap();
	void release();
};

