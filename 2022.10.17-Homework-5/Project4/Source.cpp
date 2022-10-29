#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 1000;
	int n = 0;
	scanf_s("%d", &n);
	int a[N]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	int max = a[0] + a[1] + a[2];

	for (int i = 0; i < n; ++i)
	{
		if ((a[i] + a[(i + 1) % n] + a[(i + 2) % n]) > max)
		{
			max = a[i] + a[(i + 1) % n] + a[(i + 2) % n];
		}
	}
	printf("%d", max);
	return EXIT_SUCCESS;
}