# include <iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	int a = 0;

	std::cin >> x;
	a = x * x;
	std::cout << (a + x) * (a + 1) + 1 << std::endl;
	
	return EXIT_SUCCESS;

}