#include<iostream>

int main(int argc, char* argv[])
{
	int k = 0;
	std::cin >> k;

	if (k % 4 == 0)
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
	return EXIT_SUCCESS;
}