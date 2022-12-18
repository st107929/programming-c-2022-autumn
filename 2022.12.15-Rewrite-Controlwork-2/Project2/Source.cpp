#include<iostream>

void move(int n, int begin, int end);
void hanoi_cycle(int n, int begin, int end);
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi_cycle(n, 1, 3);
	return EXIT_SUCCESS;
}
void move(int n, int begin, int end)
{
	if (((begin == 1) && (end == 2)) || ((begin == 2) && (end == 3)) || ((begin == 3) && (end == 1)))
	{
		std::cout << n << " " << begin << " " << end << std::endl;
	}
	else
	{
		std::cout << n << " " << begin << " " << 6 - begin - end << std::endl;
		std::cout << n << " " << 6 - begin - end << " " << end << std::endl;
	}
}
void hanoi_cycle(int n, int begin, int end)
{
	if (((begin == 1) && (end == 3)) || ((begin == 2) && (end == 1)) || ((begin == 3) && (end == 2)))
	{
		if (n == 1)
		{
			move(1, begin, end);
		}
		else
		{
			hanoi_cycle(n - 1, begin, end);
			move(n, begin, 6 - begin - end);
			hanoi_cycle(n - 1, end, begin);
			move(n, 6 - begin - end, end);
			hanoi_cycle(n - 1, begin, end);
		}
	}
	else
	{
		if (n == 1)
		{
			move(n, begin, end);
		}
		else
		{
			hanoi_cycle(n - 1, begin, 6 - begin - end);
			move(n, begin, end);
			hanoi_cycle(n - 1, 6 - begin - end, end);
		}
	}
}