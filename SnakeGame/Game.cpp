#include "Game.h"
 
Game::Game()
{
	map = new Map(MapRows, MapCols);
	for (int i = 0; i < EntsSize; i++) {
		fruit[i] = new Fruit();
	}
	EntSnake = new Snake();
	gameLoop = true;

	setConsole();
	for (int i = 0; i < 6; i++) {
		fruit[i]->setup();
	}
	EntSnake->setup();
}

Game::~Game()
{

 
}

void Game::setConsole()
{
	SetConsoleTitle(L"Snake Game");
	 RECT consoleDimensions;
	HWND hWindowConsole = GetConsoleWindow();
	 
	GetWindowRect(hWindowConsole, &consoleDimensions); 
	MoveWindow(hWindowConsole, consoleDimensions.left, consoleDimensions.top, SCREEN_WIDTH, SCREEN_HEIGHT, TRUE);
	 

}

void Game::play()
{
 
	while (gameLoop) {
		if ((GetAsyncKeyState(VK_END) & 1)) gameLoop = false;
		
		map->init();
		for (int i = 0; i < EntsSize; i++) {
			fruit[i]->spawnFruit();
		}

		EntSnake->spawnSnake();
		if (bGameOver) gameOver();

		EntSnake->SnakeMovesLogic();

		handleEvents();
		map->drawMap();
		update();

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
				gameLoop = false;
				
			}
	
}

void Game::handleEvents()
{
 
	if (_kbhit()) {
		switch (_getch()) {

		case static_cast<int>(SnakeMoving::LEFT): {
			CurrSnakeMove = SnakeMoving::LEFT;
			break;
		}//
		case static_cast<int>(SnakeMoving::RIGHT): {
			CurrSnakeMove = SnakeMoving::RIGHT;
			break;
		}//
		case static_cast<int>(SnakeMoving::UP): {
			CurrSnakeMove = SnakeMoving::UP;
			break;
		}//
		case static_cast<int>(SnakeMoving::DOWN): {
			CurrSnakeMove = SnakeMoving::DOWN;
			break;
		}//


		}
	}
 
}

void Game::update()
{
	system("cls");
 
}
 

 

 
