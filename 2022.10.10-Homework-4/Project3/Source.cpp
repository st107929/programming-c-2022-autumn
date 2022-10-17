#include<iostream>

int main(int argc, char* argv[])
{
	int sec = 0;
	int imain = 0;
	std::cin >> sec;
	for (int i = 1; (i * (i + 1)) / 2 <= sec; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			std::cout << i << " ";
		}
		imain = i;
	}
	for (int j = 1; j <= sec % ((imain * (imain + 1)) / 2); ++j)
	{
		std::cout << imain + 1 << " ";
	}
	return EXIT_SUCCESS;
}