#include "Game.h"
 
Game::Game()
{
	m_map = new Map(g_MapRows, g_MapCols);
	for (int i = 0; i < EntsSize; i++) {
		m_fruit[i] = new Fruit();
	}
	m_EntSnake = new Snake();
	bGameLoop = true;

	setConsole();
	for (int i = 0; i < 6; i++) {
		m_fruit[i]->Setup(m_map->GetMap());
	}
	m_EntSnake->Setup(m_map->GetMap());
}

Game::~Game()
{
	delete m_EntSnake;
	for (int i = 0; i < EntsSize; i++) delete m_fruit[i];

	delete m_map;
 
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
 
	while (bGameLoop) {
		if ((GetAsyncKeyState(VK_END) & 1)) bGameLoop = false;
		
		m_map->init();
		for (int i = 0; i < EntsSize; i++) {
			m_fruit[i]->SpawnFruit();
		}

		m_EntSnake->SpawnSnake();
		if (m_EntSnake->GetGameVarState()) gameOver();

		m_EntSnake->SnakeMovesLogic();

		handleEvents();
		m_map->DrawMap();
		update();

	}

}
 
void Game::gameOver()
{
	system("cls");
	GameOverState  gmState{};

	m_gameScores.push(g_TotalScore);
	const std::string tmpStr = "Last game";
	std::cout << "\n\n" << "\tGame over" << "\n Score:" << g_TotalScore << '\n';
	int choice = 0;

	bool end_loop = false;
	do {
		if (!m_gameScores.empty()) {
			std::cout << "\n\t\tWants to start over? - 1. " << "Print previous game scores - 2." << " Want to exit? - 3. "; 
			std::cin >> choice;
			if (choice == 1) 
				gmState = GameOverState::SUCCESS;  

			if (choice == 2) 
				gmState = GameOverState::PRINT;

			if (choice == 3) 
				gmState = GameOverState::FAILURE;
		}
		else{
			std::cout << "\n\t\tWants to start over? - 1. " << "Want to exit? - 2. ";
			std::cin >> choice;
			if (choice == 1) {
				gmState = GameOverState::SUCCESS;
			}
			if (choice == 2) {
			gmState = GameOverState::FAILURE;
		}
     }
	 
		switch (gmState) {
		case GameOverState::SUCCESS:{
			g_TotalScore = NULL;
			m_EntSnake->GetGameVarState() = false;

			m_EntSnake->Setup(m_map->GetMap());
			system("cls");
			end_loop = true;
			break;
		}//S
		case GameOverState::PRINT: {
			bool once = false;
			for (size_t i = m_gameScores.size(); i != 0; i--) {
				if (!m_gameScores.empty()) {
					if (i == m_gameScores.size() && !once) { std::cout << "[" << tmpStr << "]" << m_gameScores.top() << ' '; once = true; }
					else std::cout << "[" << i << "]" << m_gameScores.top() << ' ';

					m_gameScores.pop();
				}
				else std::cout << "you're very suspicious, but I didn't tell you about it :/" << '\n';

			}
			break;
		}//P

		case GameOverState::FAILURE: {
			bGameLoop = false;
			end_loop = true;
			break;
		}//F
		 default: {std::cout << "Unknown condition\n"; }
		}//switch end
	 

 
	} while (!end_loop);
	
}

void Game::handleEvents()
{
 
	if (_kbhit()) {
		switch (_getch()) {

		case static_cast<int>(SnakeMoving::LEFT): {
			m_EntSnake->GetTypeMove() = SnakeMoving::LEFT;
			break;
		}//
		case static_cast<int>(SnakeMoving::RIGHT): {
			m_EntSnake->GetTypeMove() = SnakeMoving::RIGHT;
			break;
		}//
		case static_cast<int>(SnakeMoving::UP): {
			m_EntSnake->GetTypeMove() = SnakeMoving::UP;
			break;
		}//
		case static_cast<int>(SnakeMoving::DOWN): {
			m_EntSnake->GetTypeMove() = SnakeMoving::DOWN;
			break;
		}//


		}
	}
 
}

void Game::update()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

 
}
 

 

 
