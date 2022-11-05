#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 100000;
	int n = 0;
	int k = 0;
	int a[N]{ 0 };
	int b[N]{ 0 };
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &k);
	for (int i = 0; i < n; ++i)
	{
		b[i] = a[(((i - k) % n) + n) % n];
	}
	for (int i = 0; i < n; ++i)
	{
		printf_s("%d", b[i]);
		std::cout << " ";
	}
	return EXIT_SUCCESS;
}