#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char* argv[])
{
	const int N = 1000;
	int n = 0;
	int a[N]{ 0 };
	int x = 0;
	int k = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &x);
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == x)
		{
			++k;
		}
	}
	printf("%d", k);
	return EXIT_SUCCESS;
}