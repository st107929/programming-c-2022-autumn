#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int a = 0;
	int b = 0;
	std::cin >> n;

	a = ((n % 2) + 2) % 2 + 1;
	b = n + 1 + a % 2;

	std::cout << b << std::endl;
	return EXIT_SUCCESS;
}
