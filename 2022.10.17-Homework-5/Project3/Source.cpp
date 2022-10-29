#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 1000;
	int a[N]{ 0 };
	int max = 0;
	int min = 0;
	int n = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	max = a[0];
	min = a[0];

	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == max)
		{
			a[i] = min;
		}
		printf("%d", a[i]);
		std::cout << " ";
	}
	return EXIT_SUCCESS;
}