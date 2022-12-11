#include<iostream>

int c(int n, int k);
int main(int argc, char* argv[])
{
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	std::cout << c(n, k);
	return EXIT_SUCCESS;
}
int c(int n, int k)
{
	if ((k == 0) || (n == k))
	{
		return 1;
	}
	else
	{
		return c(n - 1, k - 1) + c(n - 1, k);
	}
}
