#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define EntsSize 6

inline bool gameLoop = false, bGameOver = false;
inline  int TotalScore{}, FruitScore = 0;

inline const int MapRows{ 30 }, MapCols{ 30 };

struct point {
	point(){}
	~point(){}
	int x{}, y{};
};

inline uint8_t** mapPoints;


struct Matrix {
	int row, col;
};

inline Matrix mtrx;

inline char borderSymbol = '*', SnakeSymbol = '0', FruitSymbol = '+';

enum class SnakeMoving : char { LEFT = 'a', RIGHT = 'd', UP = 'w', DOWN = 's' };

 inline SnakeMoving  CurrSnakeMove;

