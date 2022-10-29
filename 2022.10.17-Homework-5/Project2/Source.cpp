#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char* argv[])
{
	const int N = 1000;
	int n = 0;
	int a[N]{ 0 };
	int l = 0;
	int r = 0;
	int max = 0;
	int i_max = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", & a[i]);
	}
	scanf_s("%d", &l);
	scanf_s("%d", &r);
	for (int i = l - 1; i <= r - 1; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
			i_max = i;
		}
	}
	printf("%d", max);
	printf("\n");
	printf("%d", i_max + 1);
	return EXIT_SUCCESS;
}