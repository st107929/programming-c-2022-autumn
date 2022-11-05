#include<iostream>

int main(int argc, char* argv[])
{
	const int N = 1000;
	int n = 0;
	int m = 0;
	const int M = 100;
	int m_i[M]{ 0 };
	int m_j[M]{ 0 };
	scanf_s("%d", &n);
	int a[N]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf_s("%d", &m_i[i]);
		scanf_s("%d", &m_j[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = m_i[i] - 1; j <= m_j[i] - 1; ++j)
		{
			printf_s("%d", a[j]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}