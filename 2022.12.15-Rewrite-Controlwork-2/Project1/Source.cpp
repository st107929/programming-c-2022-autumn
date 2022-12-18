#include<iostream>

int** spiral(int** a, int n);
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int** a = nullptr;
	a = new int* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		a[i] = new int [n] { 0 };
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << spiral(a, n)[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < n; ++i)
	{
		delete[]a[i];
	}
	delete[]a;
	return EXIT_SUCCESS;
}
int** spiral(int** a, int n)
{
	if (n == 1)
	{
		a[0][0] = 1;
	}
	else
	{
		if (n == 2)
		{
			a[0][0] = 1;
			a[0][1] = 2;
			a[1][0] = 4;
			a[1][1] = 3;
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if ((i == 0) || (j == (n - 1)))
					{
						a[i][j] = i + j + 1;
					}
					else 
					{
						if ((i == (n - 1)))
						{
							a[i][j] = i + j + 2 * (n - j) - 1;
						}
						else
						{
							if ((j == 0) && (i != 0))
							{
								a[i][j] = i + (4 * n - 3 - 2 * i);
							}
							else
							{
								int** b = nullptr;
								b = new int* [n - 2] { 0 };
								for (int i = 0; i < n - 2; ++i)
								{
									b[i] = new int[n - 2] { 0 };
								}
								a[i][j] = (4 * n - 4) + spiral(b, n - 2)[i - 1][j - 1];
								for (int i = 0; i < n - 2; ++i)
								{
									delete[]b[i];
								}
								delete[]b;
							}
						}
					}
				}
			}
		}
	}
	return a;
}