#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 100;
	int n = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int k[N]{ 0 };
	int m[N]{ 0 };
	int p[N]{ 0 };
	scanf_s("%d", &n);
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);
	for (int i = 1; i <= n; ++i)
	{
		k[i] = i;
		m[i] = i;
	}
	for (int i = a; i <= b; ++i)
	{
		k[i] = m[b + a - i];
	}
	for (int i = 1; i <= n; ++i)
	{
		p[i] = k[i];
	}
	for (int i = c; i <= d; ++i)
	{
		p[i] = k[c + d - i];
	}
	for (int i = 1; i <= n; ++i)
	{
		printf_s("%d", p[i]);
		std::cout << " ";
	}
	return EXIT_SUCCESS;
}