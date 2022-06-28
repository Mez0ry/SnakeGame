#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define EntsSize 6

inline bool gameLoop = false, bExit = false, bGameOver = false;
inline  int TotalScore{}, Score4Fruit = 0;

struct point {
	int x, y;
};

inline uint8_t** mapPoints;


struct Matrix {
	int row, col;
};

inline Matrix mtrx;

inline RECT consoleDimensions;

inline char borderSymbol = '*', SnakeSymbol = '0', FruitSymbol = '+';

enum SnakeMoving : char { LEFT = 'a', RIGHT = 'd', UP = 'w', DOWN = 's' };

 inline   SnakeMoving  CurrSnakeMove;

