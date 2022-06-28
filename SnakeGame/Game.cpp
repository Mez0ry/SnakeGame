#include "Game.h"
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

 
Game::Game()
{
	map = new Map(26, 36);
	for (int i = 0; i < EntsSize; i++) {
		fruit[i] = new Fruit();
	}

	EntSnake = new Snake();
	gameLoop = true;

}

Game::~Game()
{

 
}

void Game::setConsole()
{
	SetConsoleTitle(L"Snake Game");

	HWND hWindowConsole = GetConsoleWindow();
	 
	GetWindowRect(hWindowConsole, &consoleDimensions); 
	MoveWindow(hWindowConsole, consoleDimensions.left, consoleDimensions.top, SCREEN_WIDTH, SCREEN_HEIGHT, TRUE);
	 

}


void Game::play()
{
 
 
	setConsole();
	for (int i = 0; i < EntsSize; i++) {
		fruit[i]->setup();
	}
	EntSnake->setup();
	while (gameLoop) {
		if ((GetAsyncKeyState(VK_END) & 1)) bExit = true;
		
		map->init();
		for (int i = 0; i < EntsSize; i++) {
			fruit[i]->spawnFruit();
		}
		EntSnake->spawnSnake();
		if (bGameOver) gameOver();

		EntSnake->SnakeMovesLogic();
		EntSnake->CheckSnakeOnFruit();

		handleEvents();
		map->drawMap();
		update();
		if (bExit == true) {
			exit();
		}
			 

	}
}

void Game::gameOver()
{
	bool check = false;
	std::cout << "\n\n" << "\tGame over" << "\n Score:" << TotalScore << '\n';
	int choice = 0;
	 
			std::cout << "\n\t\tWants to start over? - 1. " << " Want to exit? - 2. "; std::cin >> choice;
			if (choice == 1) {
				TotalScore = NULL;
				bGameOver = false;
				check = true;
				EntSnake->setup();
			}
			else {
				bExit = true;
				
			}

 


 
	
}

void Game::handleEvents()
{

	if (_kbhit()) {
		switch (_getch()) {
		case LEFT: {
			CurrSnakeMove = LEFT;
			break;
		}//
		case RIGHT: {
			CurrSnakeMove = RIGHT;
			break;
		}//
		case UP: {
			CurrSnakeMove = UP;
			break;
		}//
		case DOWN: {
			CurrSnakeMove = DOWN;
			break;
		}//

			 
		}
	}
 
}

void Game::update()
{
	system("cls");
}
 

void Game::exit()
{
	gameLoop = false;
	map->release();

}

 
