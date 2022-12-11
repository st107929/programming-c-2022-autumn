#include<iostream>

void towers(int n, int begin, int end, int middle);
int main(int argc, char* argv[])
{
	int n = 0;
	int begin = 1;
	int middle = 2;
	int end = 3;
	std::cin >> n;
	towers(n, begin, end, middle);
	return EXIT_SUCCESS;
}
void towers(int n, int begin, int end, int middle)
{
	if (n == 1)
	{
		std::cout << "Disc 1 move from " << begin << " to " << end << std::endl;
	}
	else
	{
		towers(n - 1, begin, middle, end);
		std::cout << "Disc " << n << " move from " << begin << " to " << end << std::endl;
		towers(n - 1, middle, end, begin);
	}
}