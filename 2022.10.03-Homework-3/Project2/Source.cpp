#include<iostream>

int main(int argc, char* argv[])
{
	int a = 1;
	int kol = 0;

	while (a != 0)
	{
		std::cin >> a;
		if ((a < 0) && ((a % 2) != 0))
		{
			kol++;
		}
	}
	std::cout << kol << std::endl;
	return EXIT_SUCCESS;
}