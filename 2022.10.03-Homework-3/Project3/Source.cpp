#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int a = 1;
	int delta = 0;
	std::cin >> n;

	do
	{
		do
		{
			std::cout << a + delta << " ";
			a++;
		} while (a <= n - 1);
		std::cout << n + delta << std::endl;
		a = 1;
				delta++;
	} while (delta <= n - 1);
	return EXIT_SUCCESS;
}