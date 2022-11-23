#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	int** a = nullptr;
	int** b = nullptr;
	int** sum = nullptr;
	a = new int* [n] { 0 };
	b = new int* [n] { 0 };
	sum = new int* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		a[i] = new int [m] { 0 };
	}
	for (int i = 0; i < n; ++i)
	{
		b[i] = new int [m] { 0 };
	}
	for (int i = 0; i < n; ++i)
	{
		sum[i] = new int [m] { 0 };
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
		for (int j = 0; j < m; ++j)
		{
			scanf_s("%d", &b[i][j]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			sum[i][j] = a[i][j] + b[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf_s("%d", sum[i][j]);
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