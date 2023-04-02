#include "Point.h"

int Point::Norma() // Вычисляет квадрат расстояния
{
	int Norma = 0;
	Norma = x * x + y * y;
	return Norma;
}
void Point::Print()
{
	std::cout << x << " " << y << std::endl;
}