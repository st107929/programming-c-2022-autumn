#include<iostream>

int main(int argc, char* argv[])
{
	int k = 0;
	int m = 0;
	int n = 0;

	std::cin >> k >> m >> n;

	if (n <= k)
	{
		std::cout << 2 * m << std::endl;
	}
	else
	{
		if (n % k == 0)
		{
			std::cout << (n / k) * 2 * m << std::endl;
		}
		else
		{
			std::cout << ((n / k) + 1) * 2 * m << std::endl;
		}
	}

	return EXIT_SUCCESS;
}