#include<iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	std::cin >> x;
	int res = 0;
	for (int i = 0; i < 10; ++i)
	{
		int a = 1;
		int b = 1;
		for (int j = 0; j < i; ++j)
		{
			a *= 2;
		}
		int digit = 0;
		
		for (int j = 0; j < i; ++j)
		{
			b *= 10;
		}
		digit = (x / b) % 10;
		res += (digit * a);
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}