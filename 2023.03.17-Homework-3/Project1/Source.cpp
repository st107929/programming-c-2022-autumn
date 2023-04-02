#include<iostream>
#include"Point.h"


int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	Point* a = nullptr;
	a = new Point[n]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		int x = 0;
		int y = 0;
		std::cin >> x;
		std::cin >> y;
		a[i] = Point(x, y);
	}
	for (int i = 0; i < 2000001; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[j].Norma() == i)
			{
				a[j].Print();
			}
		}
	}
	delete[] a;
	return EXIT_SUCCESS;
}