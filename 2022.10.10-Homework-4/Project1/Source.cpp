#include<iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	int number_of_divisors = 0;
	std::cin >> x;

	for (int d = 1; d * d <= x; ++d)
	{
		if ((x % d == 0) && (d * d != x))
		{
			number_of_divisors += 2;
		}
		if ((x % d == 0) && (d * d == x))
		{
			number_of_divisors += 1;
		}
	}
	std::cout << number_of_divisors << std::endl;

	return EXIT_SUCCESS;
}