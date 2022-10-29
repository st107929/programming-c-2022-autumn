#include<iostream>

int main(int argc, char* argv[])
{
	const double P = 0.01;
	const int N = 100;
	int n = 0;
	double max = 0;
	int i_max = 0;
	scanf_s("%d", &n);
	int v[N]{ 0 };
	int p[N]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &v[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &p[i]);
	}
	max = p[0] * v[0] * P;
	for (int i = 0; i < n; ++i)
	{
		if (p[i] * v[i] * P > max)
		{
			max = p[i] * v[i] * P;
			i_max = i;
		}
	}
	printf("%d", i_max + 1);
	return EXIT_SUCCESS;
}