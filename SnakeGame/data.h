#ifndef DATA
#define DATA
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define FRUIT_SIZE 6

inline int g_TotalScore{};

const int g_MapRows{ 30 }, g_MapCols{ 30 };

struct point {
	point(){}
	~point(){}
	int x{}, y{};
};

enum class SnakeMoving : char { LEFT = 'a', RIGHT = 'd', UP = 'w', DOWN = 's' };
#endif // !DATA
 

