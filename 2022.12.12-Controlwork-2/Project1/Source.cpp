#include<iostream>

int magaradga(int n, int k, int i, int j);
int main(int argc, char* argv[])
{
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	int result = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			result += magaradga(n, k, i, j);
		}
	}
	std::cout << result;
	return EXIT_SUCCESS;
}
int magaradga(int n, int k, int i, int j)
{
	int res = 0;
	if (k == 0)
	{
		return 1;
	}
	else 
	{
		for (int w = 1; (w < n + 1) && (w != i); ++w)
		{
			for (int u = 1; (u < n + 1) && (u != j); ++u)
			{
				if ((abs(w - i) * abs(u - j) != 2) && (abs(w - i) != abs(u - j)))
				{
					int a = 0;
					int b = 0;
					if (w < i)
					{
						a = w;
					}
					else
					{
						a = w - 1;
					}
					if (u < j)
					{
						b = u;
					}
					else
					{
						b = u - 1;
					}
					res += magaradga(n - 1, k - 1, a, b);
				}
			}
		}
		if (res == 0)
		{
			res += 1;
		}
	}
	return res;
}