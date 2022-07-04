#include "Map.h"

Map::Map(const int& row,const int& col)
{
		m_Map = new uint8_t * [row];
		for (int write_index = 0; write_index < row; write_index++)
			m_Map[write_index] = new uint8_t[col];	 
}

Map::~Map()
{
	this->Release();
}

void Map::Init()
{
	this->CleanMap();
	this->FillMap();
}

void Map::CleanMap()
{
	for (size_t row_index = 0; row_index < g_MapRows; ++row_index) {
		for (size_t col_index = 0; col_index < g_MapCols; ++col_index) {
			m_Map[row_index][col_index] = ' ';
		}
	 }
}

void Map::FillMap()
{
	for (size_t row_index = 0; row_index < g_MapRows; ++row_index) {
		for (size_t col_index = 0; col_index < g_MapCols; ++col_index) {
			if (row_index == 0) {

				m_Map[g_MapRows - g_MapRows][col_index] = m_BorderSymbol;
			}

			if (row_index == g_MapRows - 1) {
				m_Map[g_MapRows - g_MapRows][col_index] = m_BorderSymbol;
			}

			else {
				m_Map[row_index][g_MapCols - 1] = m_BorderSymbol;
				m_Map[row_index][g_MapCols - g_MapCols] = m_BorderSymbol;
				m_Map[g_MapRows - 1][col_index] = m_BorderSymbol;
			}

		}
	}

}

void Map::Release()
{
	if (m_Map != nullptr) {
		for (size_t delete_index = 0; delete_index < g_MapRows; delete_index++)
			delete[] m_Map[delete_index];
		delete[] m_Map;
	}
}

void Map::DrawMap()
{
	for (size_t row_index = 0; row_index < g_MapRows; ++row_index) {
		for (size_t col_index = 0; col_index < g_MapCols; ++col_index) {
			std::cout << m_Map[row_index][col_index];
		}
		std::cout << '\n';
	}
	std::cout <<static_cast<char>('\n\n') << "\t\tScore: " << g_TotalScore << '\n';
}
