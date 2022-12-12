#include<iostream>

void primeness(int n, int div);
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	primeness(n, 2);
	return EXIT_SUCCESS;
}
void primeness(int n, int div)
{
	if (n % div == 0)
	{
		std::cout << "composite";
	}
	else
	{
		if ((div * div <= n) && ((div + 1) * (div + 1) > n))
		{
			std::cout << "prime";
		}
		else
		{
			primeness(n, div + 1);
		}
	}
}