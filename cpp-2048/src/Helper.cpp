import Helper;
#include <random>

int Helper::GetRandomInt(const int& min, const int& max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);
	int x = distr(gen);
	return x;
}