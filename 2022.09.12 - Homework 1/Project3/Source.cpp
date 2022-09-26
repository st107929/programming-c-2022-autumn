#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int k = 0;

	std::cin >> n;
	std::cin >> k;

	std::cout << k % n;

	return EXIT_SUCCESS;
}