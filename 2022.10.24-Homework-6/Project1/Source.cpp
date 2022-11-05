#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 1000;
	int n = 0;
	int a[N]{ 0 };
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		printf_s("%d", a[n - 1 - i]);
		std::cout << " ";
	}
	return EXIT_SUCCESS;
}