#include<iostream>

int f(int a, int b, int c, int*** arr);
void del(int*** arr, int n);
int*** buf(int n);
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a >> b >> c;
	int*** arr = buf(a + b + c);
	std::cout << f(a, b, c, arr);
	del(arr, a + b + c);
	return EXIT_SUCCESS;
}
int*** buf(int n)
{
	int*** res = nullptr;
	res = new int** [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		res[i] = new int* [n] { 0 };
		for (int j = 0; j < n; ++j)
		{
			res[i][j] = new int [n] { 0 };
		}
	}
	return res;
}
void del(int*** arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			delete[]arr[i][j];
		}
	}
	delete[] arr;
}
int f(int a, int b, int c, int*** arr)
{
	if (arr[a][b][c] == 0)
	{
		if ((a <= 0) || (b <= 0) || (c <= 0))
		{
			arr[a][b][c] = 1;
		}
		else
		{
			if ((a > 20) || (b > 20) || (c > 20))
			{
				arr[a][b][c] = f(20, 20, 20, arr);
			}
			else
			{
				if ((a < b) && (b < c))
				{
					arr[a][b][c] = f(a, b, c - 1, arr) + f(a, b - 1, c - 1, arr) - f(a, b - 1, c - 1, arr);
				}
				else
				{
					arr[a][b][c] = f(a - 1, b, c, arr) + f(a - 1, b - 1,c, arr) + f(a - 1, b, c - 1, arr) - f(a - 1, b - 1, c - 1, arr);
				}
			}
		}
	}
	return arr[a][b][c];
}