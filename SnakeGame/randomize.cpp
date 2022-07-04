#include "randomize.hpp"

int randomize::range_random(const int range_from, const int range_to)
{
	std::random_device sc;
	std::mt19937 gen(sc());
	std::uniform_int_distribution<int> dist(range_from, range_to);
	int result = dist(gen);
	return result;
}
