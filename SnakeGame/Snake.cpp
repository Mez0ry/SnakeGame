#include "Snake.h"
 
Snake::Snake()
{
 
  
		 
}

Snake::~Snake()
{
 
}

void Snake::setup()
{
	ptrSnakeCoords->x = mtrx.row / 2;
	ptrSnakeCoords->y = mtrx.col / 2;

}

void Snake::spawnSnake()
{
	for (int row = 0; row < mtrx.row; row++) {
		for (int col = 0; col < mtrx.col; col++) {

			if (row == ptrSnakeCoords->x && col == ptrSnakeCoords->y)
				mapPoints[row][col] = SnakeSymbol;
			else if (ptrSnakeCoords->x+1    == mtrx.row || ptrSnakeCoords->y+1   == mtrx.col || ptrSnakeCoords->x  == mtrx.row - mtrx.row  || ptrSnakeCoords->y  == mtrx.col - mtrx.col)
				bGameOver = true;
			else if(isFruit()){}
		}
	}
} 

 bool Snake::isFruit()
{	 
	 for (int i = 0; i < EntsSize; i++) {
		 if (ptrSnakeCoords->x == getFruitCoord(i).x && ptrSnakeCoords->y == getFruitCoord(i).y) {
			 mapPoints[getFruitCoord(i).x][getFruitCoord(i).y] = ' ';
			 TotalScore += FruitScore;
			 randomPosition(getFruitCoord(i).x, getFruitCoord(i).y, i);
			 return true;
		 }
		  
	 }
	 return false;
}

 
 

void Snake::SnakeMovesLogic()
{
	switch (CurrSnakeMove) {
		case static_cast<SnakeMoving>(SnakeMoving::LEFT): {
			ptrSnakeCoords->y--;
			break;
		}//
		case static_cast<SnakeMoving>(SnakeMoving::RIGHT): {
			ptrSnakeCoords->y++;
			break;
		}//
		case static_cast<SnakeMoving>(SnakeMoving::UP): {
			ptrSnakeCoords->x--;
			break;
		}//
		case  static_cast<SnakeMoving>(SnakeMoving::DOWN): {
			ptrSnakeCoords->x++;
			break;
		}//
		 
	}

}
