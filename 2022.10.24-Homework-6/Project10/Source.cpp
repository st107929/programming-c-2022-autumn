#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	const int N = 30000;
	const int M = 30000;
	int a[N]{ 0 };
	int b[M]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf_s("%d", &b[i]);
	}
	for (int i = 0; i <= 100000; ++i)
	{
		int flag1 = 0;
		int flag2 = 0;
		for (int j = 0; j < n; ++j)
		{
			if (a[j] == i)
			{
				flag1 = 1;
			}
		}
		for (int j = 0; j < m; ++j)
		{
			if (b[j] == i)
			{
				flag2 = 1;
			}
		}
		if ((flag1 == 1) && (flag2 == 1))
		{
			printf_s("%d", i);
			std::cout << " ";
		}
	}
	return EXIT_SUCCESS;
}