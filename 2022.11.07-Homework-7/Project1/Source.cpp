#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	scanf_s("%d", &n);
	scanf_s("%d", &m);

	int* sumstr = nullptr;
	sumstr = new int[n] { 0 };
	int* sumcolomn = nullptr;
	sumcolomn = new int[m] { 0 };
	int** a = nullptr;
	a = new int* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		a[i] = new int [m] { 0 };
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf_s("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < m; ++j)
		{
			sum += a[i][j];
		}
		sumstr[i] = sum;
	}
	for (int j = 0; j < m; ++j)
	{
		int sum = 0;
		for (int i = 0; i < m; ++i)
		{
			sum += a[i][j];
		}
		sumcolomn[j] = sum;
	}
	for (int i = 0; i < n; ++i)
	{
		printf_s("%d", sumstr[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
	for (int j = 0; j < m; ++j)
	{
		printf_s("%d", sumcolomn[j]);
		std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf_s("%d", a[i][j]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < n; ++i)
	{
		delete[] a[i];
	}
	delete[] a;
	return EXIT_SUCCESS;
}