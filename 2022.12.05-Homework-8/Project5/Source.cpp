#include<iostream>

int threefive(int n);
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	if (threefive(n) == 1)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "NO";
	}
	return EXIT_SUCCESS;
}
int threefive(int n)
{
	if ((n == 1) || (n == 4))
	{
		return 1;
	}
	if ((n == 2) || (n == 3) || (n == 5))
	{
		return 0;
	}
	else
	{
		if ((threefive(n - 3) == 1) || (threefive(n - 5) == 1))
		{
			return 1;
		}
	}
}