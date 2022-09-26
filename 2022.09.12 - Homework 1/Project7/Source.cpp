#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;

	c = a;
	a = b;
	b = c;

	std::cout << a << ", " << b << std::endl;
	return EXIT_SUCCESS;
}