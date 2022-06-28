#include "Snake.h"

Snake::Snake()
{
	SnakeCoord = new point();
	 
}

Snake::~Snake()
{
	delete SnakeCoord;
}

void Snake::setup()
{
	SnakeCoord->x = mtrx.row / 2;
	SnakeCoord->y = mtrx.col / 2;

}

void Snake::spawnSnake()
{
	for (int row = 0; row < mtrx.row; row++) {
		for (int col = 0; col < mtrx.col; col++) {

			if (row == SnakeCoord->x && col == SnakeCoord->y)
				mapPoints[row][col] = SnakeSymbol;
			else if (SnakeCoord->x >= mtrx.row || SnakeCoord->y >= mtrx.col || SnakeCoord->x <= mtrx.row - mtrx.row || SnakeCoord->y <= mtrx.col - mtrx.col)
				bGameOver = true;
		}
	}
}

 void Snake::CheckSnakeOnFruit()
{
	 for (int i = 0; i < EntsSize; i++) {
		 if (SnakeCoord->x == FruitCoord[i]->x && SnakeCoord->y == FruitCoord[i]->y) {
			 mapPoints[FruitCoord[i]->x][FruitCoord[i]->y] = ' ';
			 TotalScore += Score4Fruit;
			 randomPosition(FruitCoord[i]->x, FruitCoord[i]->y);
		 }
	 }

}

 
 

void Snake::SnakeMovesLogic()
{
	switch (CurrSnakeMove) {
		case LEFT: {
			SnakeCoord->y--;
			break;
		}//
		case RIGHT: {
			SnakeCoord->y++;
			break;
		}//
		case UP: {
			SnakeCoord->x--;
			break;
		}//
		case  DOWN: {
			SnakeCoord->x++;
			break;
		}//
		 
	}// Switch Closed

}
