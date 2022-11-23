#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
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
	for (int i = 0; i < n / 2; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int c = 0;
			c = a[i][j];
			a[i][j] = a[n - 1 - i][j];
			a[n - 1 - i][j] = c;
		}
	}
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