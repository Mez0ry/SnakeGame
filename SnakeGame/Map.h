#ifndef MAP
#define MAP
#include "data.h"

class Map 
{
private:
	const char m_BorderSymbol = '*';
	uint8_t** m_Map;
public:
	explicit  Map(const int& height, const  int& width);
	~Map();

	void Init();
	void DrawMap();

	uint8_t** get_Map() const { return m_Map; }
private:
	void CleanMap();
	void FillMap();
	void Release();
};

#endif // !MAP