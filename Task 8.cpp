#include <iostream>
int main(int argc, char* argv[])
{
	int a1 = 0;
	int b1 = 0;
	int c1 = 0;
	int a2 = 0;
	int b2 = 0;
	int c2 = 0;
	int time_period = 0;
	std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	time_period = 3600 * (a2 - a1) + 60 * (b2 - b1) + (c2 - c1);
	std::cout << time_period << std::endl;
	return EXIT_SUCCESS;
}