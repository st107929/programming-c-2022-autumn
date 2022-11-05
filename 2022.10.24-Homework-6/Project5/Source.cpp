#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 10000;
	int n = 0;
	int a[N]{ 0 };
	int p_min[N]{ 0 };
	int p = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		p_min[i] = a[i];
		int y = 1;
		for (int j = 0; j < n - 1 - i; ++j)
		{
			y = y * 10;
		}
		p += p_min[i] * y;
	}
	for (int k = 0; k < n; ++k)
	{
		int b[N]{ 0 };
		int x = 0;
		for (int i = 0; i < n; ++i)
		{
			b[i] = a[(i + k) % n];
			int y = 1;
			for (int j = 0; j < n - 1 - i; ++j)
			{
				y = y * 10;
			}
			x += b[i] * y;
		}
		if (x <= p)
		{
			for (int i = 0; i < n; ++i)
			{
				p_min[i] = b[i];
			}
			p = x;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf_s("%d", p_min[i]);
		std::cout << " ";
	}
	return EXIT_SUCCESS;
}