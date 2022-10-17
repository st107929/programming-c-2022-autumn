#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int number_of_solutions = 0;
	std::cin >> a >> b >> c >> d >> e;

	for (int x = 0; x <= 1000; ++x)
	{
		float fraction = 0;
		fraction = 1.0 * (a * x * x * x + b * x * x + c * x + d) / (x - e);
		if ((x != e)&&(fraction ==0.0))
		{
			++number_of_solutions;
		}
	}
	std::cout << number_of_solutions << std::endl;
	return EXIT_SUCCESS;
}