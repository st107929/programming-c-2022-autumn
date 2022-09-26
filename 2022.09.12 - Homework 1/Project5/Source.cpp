#include<iostream>

int main(int argc, char argv[])
{
	int n = 0;
	int a = 0;
	int b = 0;
	int c = 0;

	std::cin >> n;

	a = n % 10;
	b = ((n % 100) - a) / 10;
	c = (n - (n % 100)) / 100;

	std::cout << a + b + c << std::endl;

	return EXIT_SUCCESS;
}