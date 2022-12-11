#include<iostream>

int min(int a, int b, int c, int d);
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a >> b >> c >> d;
	std::cout << min(a, b, c, d) << std::endl;
	return EXIT_SUCCESS;
}

int min(int a, int b, int c, int d)
{
	if ((a == 0) || (b == 0) || (c == 0) || (d == 0))
	{
		if (a == 0)
		{
			return a;
		}
		else
		{
			if (b == 0)
			{
				return b;
			}
			else
			{
				if (c == 0)
				{
					return c;
				}
				else
				{
					return d;
				}
			}
		}
	}
	else
	{
		return 1 + min(a - 1, b - 1, c - 1, d - 1);
	}
}
