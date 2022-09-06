#include "Game.h"
 
Game::Game() : m_Map(g_MapRows, g_MapCols), m_bGameLoop(true)
{
	SetConsole();
	m_Fruit.Setup(m_Map.get_Map());
	m_Snake.Setup(m_Map.get_Map(), m_Fruit); 
}

Game::~Game()
{

}

void Game::SetConsole()
{
	SetConsoleTitle("Snake Game");
	RECT consoleDimensions;
	HWND hWindowConsole = GetConsoleWindow();
	 
	GetWindowRect(hWindowConsole, &consoleDimensions); 
	MoveWindow(hWindowConsole, consoleDimensions.left, consoleDimensions.top, SCREEN_WIDTH, SCREEN_HEIGHT, TRUE);
}

void Game::play()
{

	while (m_bGameLoop) {
		if ((GetAsyncKeyState(VK_END) & 1))
			m_bGameLoop = false;
		 
		m_Map.Init();
		m_Fruit.SpawnFruit();
		m_Snake.SpawnSnake();
		 

		m_Snake.SnakeMovesLogic();
		HandleEvents();
		m_Map.DrawMap();
		Update();

		if (m_Snake.get_GameVarState()) 
			GameOver();
	}

}
 
void Game::GameOver()
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
		else {
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
			m_Snake.get_GameVarState() = false;

			m_Snake.Setup(m_Map.get_Map(), m_Fruit);
			system("cls");
			end_loop = true;
			break;
		}//S

		case GameOverState::PRINT: {
			bool once = false;
			std::cout << "-> Game Scores: ";
			for (size_t read_index = m_gameScores.size(); read_index != 0; read_index--) {
				if (read_index == m_gameScores.size() && !once) {
					std::cout << "  [" << tmpStr << "]" << m_gameScores.top() << ' '; once = true;
				}
				else {
					std::cout << "  [" << read_index << "] - " << m_gameScores.top() << ' ';
				}
				m_gameScores.pop();
			}
			std::cout << '\n';
			break;
		}//P

		case GameOverState::FAILURE: {
			m_bGameLoop = false;
			end_loop = true;
			break;
		}//F

		default: {
			std::cout << "Unknown condition\n";
		}

		}//switch end
 
	} while (!end_loop);
	
}

void Game::HandleEvents()
{
 
	if (_kbhit()) {
		switch (_getch()) {

		case static_cast<int>(SnakeMoving::LEFT): {
			m_Snake.get_MoveType() = SnakeMoving::LEFT;
			break;
		}//
		case static_cast<int>(SnakeMoving::RIGHT): {
			m_Snake.get_MoveType() = SnakeMoving::RIGHT;
			break;
		}//
		case static_cast<int>(SnakeMoving::UP): {
			m_Snake.get_MoveType() = SnakeMoving::UP;
			break;
		}//
		case static_cast<int>(SnakeMoving::DOWN): {
			m_Snake.get_MoveType() = SnakeMoving::DOWN;
			break;
		}//


		}
	}
 
}

void Game::Update()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}

 
 

 

 
