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
	int sum = 0;
	int prod = 1;
	int max = a[0];
	int min = a[0];
	int i_min = 0;
	int i_max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > 0)
		{
			sum += a[i];
		}
	}
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
			i_max = i;
		}
		if (a[i] < min)
		{
			min = a[i];
			i_min = i;
		}
	}
	if (i_min < i_max)
	{
		for (int i = i_min + 1; i < i_max; ++i)
		{
			prod *= a[i];
		}
	}
	else
	{
		for (int i = i_max + 1; i < i_min; ++i)
		{
			prod *= a[i];
		}
	}
	printf_s("%d", sum);
	std::cout << " ";
	printf_s("%d", prod);
	return EXIT_SUCCESS;
}