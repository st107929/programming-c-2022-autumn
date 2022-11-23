#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	scanf_s("%d", &n);
	int** a = nullptr;
	a = new int* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		a[i] = new int [n] { 0 };
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			int c = 0;
			c = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = c;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
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