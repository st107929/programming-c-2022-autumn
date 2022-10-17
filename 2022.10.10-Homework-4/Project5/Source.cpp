#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	float res = 0;
	std::cin >> n;
	for (int i = 0; i <= n; ++i)
	{
		int a = 1;
		for (int j = 1; j <= i; ++j)
		{
			a *= j;
		}
		res += 1.0 / a;
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}