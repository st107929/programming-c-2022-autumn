#include<iostream>

int main(int argc, char* argv[])
{
	int v = 0;
	int t = 0;
	int a = 0;
	int b = 0;
	std::cin >> v;
	std::cin >> t;

	a = (v * t) % 109;
	b = (a + 109) % 109;
	std::cout << b << std::endl;

	return EXIT_SUCCESS;
}