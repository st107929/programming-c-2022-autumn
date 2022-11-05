#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 100;
	int n = 0;
	int x = 0;
	int i_peter = 0;
	scanf_s("%d", &n);
	int a[N]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &x);
	for (int i = 0; i < n; ++i)
	{
		if (a[i] >= x)
		{
			++i_peter;
		}
	}
	printf_s("%d", i_peter + 1);
	return EXIT_SUCCESS;
}