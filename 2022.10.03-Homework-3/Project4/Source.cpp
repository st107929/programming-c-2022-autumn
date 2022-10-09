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
			if (a + delta > n)
			{
				std::cout << a + delta - 2 * ((a + delta) % n) << " ";
				a++;
			}
			else
			{
				std::cout << a + delta << " ";
				a++;
			}
		} while (a <= n - 1);
		std::cout << n - delta << std::endl;
		a = 1;
		delta++;
	} while (delta <= n - 1);
	return EXIT_SUCCESS;
}