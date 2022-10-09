#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a >> b;

	while (a <= b - 1)
	{
		std::cout << a << ", ";
		a++;
	}
	std::cout << b;
	return EXIT_SUCCESS;
}