#include<iostream>

int main(int argc, char* argv[])
{
	int xferz = 0;
	int yferz = 0;
	int x = 0;
	int y = 0;
	std::cin >> xferz >> yferz >> x >> y;

	if ((x - xferz) == (y - yferz))
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		if ((x - xferz) == (yferz - y))
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			if (x == xferz)
			{
				std::cout << "YES" << std::endl;
			}
			else
			{
				if (y == yferz)
				{
					std::cout << "YES" << std::endl;
				}
				else
				{
					std::cout << "NO" << std::endl;
				}
			}
		}
	}
	return EXIT_SUCCESS;
}