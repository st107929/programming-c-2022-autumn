#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 100;
	int n = 0;
	scanf_s("%d", &n);
	int a[N]{ 0 };
	int three[N]{ 0 };
	int four[N]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2 == 0)
		{
			four[i] = a[i];
		}
		else
		{
			three[i] = a[i];
		}
	}
	int kol_three = 0;
	int kol_four = 0;
	for (int i = 0; i < n; ++i)
	{
		if (three[i] != 0)
		{
			printf_s("%d", three[i]);
			++kol_three;
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < n; ++i)
	{
		if (four[i] != 0)
		{
			printf_s("%d", four[i]);
			++kol_four;
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	if (kol_three <= kol_four)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
	return EXIT_SUCCESS;
}