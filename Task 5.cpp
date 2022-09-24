#include<iostream>

int main(int argc, char argv[])
{
	int N = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	
	std::cin >> N;

	a = N % 10;
	b = ((N % 100) - a) / 10;
	c = (N - (N % 100)) / 100;

	std::cout << a + b + c << std::endl;

	return EXIT_SUCCESS;
}