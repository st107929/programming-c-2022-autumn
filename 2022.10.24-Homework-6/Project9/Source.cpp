#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 100;
	int n = 0;
	int a[N]{ 0 };
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	int p = -1;
	int res = 0;
	while (p + 1 < n)
	{
		int max0 = a[p + 1];
		int i_max0 = p + 1;
		for (int i = p + 1; i < n; ++i)
		{ 
			if (a[i] > max0)
			{
				max0 = a[i];
				i_max0 = i;
			}
		}
		res += (max0 * (i_max0 - p));
		p = i_max0;
	}
	printf_s("%d", res);
	return EXIT_SUCCESS;
}