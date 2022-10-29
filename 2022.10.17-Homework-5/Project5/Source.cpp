#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 1000;
	int n = 0;
	int a[N]{ 0 };
	int i_min = 0;
	int x = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &x);
	int min = 0;
	if ((a[0] - x) >= 0)
	{
		min = a[0] - x;
	}
	else
	{
		min = (x - a[0]);
	}
	for (int i = 0; i < n; ++i)
	{
		int module = 0;
		if ((a[i] - x) >= 0)
		{
			module = a[i] - x;
		}
		else
		{
			module = x - a[i];
		}
		if (module < min)
		{
			min = module;
			i_min = i;
		}
	}
	printf("%d", a[i_min]);
	return EXIT_SUCCESS;
}