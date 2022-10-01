#include<iostream>

int main(int argc, char** argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a >> b >> c >> d;

	switch (c)
	{
	case 0:
		if ((a == 0) && (b == 0))
		{
			std::cout << "INF" << std::endl;
		}
		else
		{
			if ((a == 0) && (b != 0))
			{
				std::cout << "NO" << std::endl;
			}
			else
			{
				if ((a != 0) && (b == 0))
				{
					std::cout << 0 << std::endl;
				}
				else
				{
					if ((-b) % a == 0)
					{
						std::cout << (-b) / a << std::endl;
					}
					else
					{
						std::cout << "NO" << std::endl;
					}
				}
			}
		}
		break;
	default:
	{
		if (d == 0)
		{
			if ((a == 0) && (b == 0))
			{
				std::cout << "INF" << std::endl;
			}
			else
			{
				if ((a == 0) && (b != 0))
				{
					std::cout << "NO" << std::endl;
				}
				else
				{
					if ((a != 0) && (b == 0))
					{
						std::cout << "NO" << std::endl;
					}
					else
					{
						if ((-b) % a == 0)
						{
							std::cout << (-b) / a << std::endl;
						}
						else
						{
							std::cout << "NO" << std::endl;
						}
					}
				}
			}
		}
		else
		{
			if ((-d) % c == 0)
			{
				if ((a == 0) && (b == 0))
				{
					std::cout << "INF" << std::endl;
				}
				else
				{
					if ((a == 0) && (b != 0))
					{
						std::cout << "NO" << std::endl;
					}
					else
					{
						if ((a != 0) && (b == 0))
						{
							std::cout << 0 << std::endl;
						}
						else
						{
							if ((-b) % a == 0)
							{
								if ((-b) / a == (-d) / c)
								{
									std::cout << "NO" << std::endl;
								}
								else
								{
									std::cout << (-b) / a << std::endl;
								}
							}
							else
							{
								std::cout << "NO" << std::endl;
							}
						}
					}
				}
			}
			else
			{
				if ((a == 0) && (b == 0))
				{
					std::cout << "INF" << std::endl;
				}
				else
				{
					if ((a == 0) && (b != 0))
					{
						std::cout << "NO" << std::endl;
					}
					else
					{
						if ((a != 0) && (b == 0))
						{
							std::cout << 0 << std::endl;
						}
						else
						{
							if ((-b) % a == 0)
							{
								std::cout << (-b) / a << std::endl;
							}
							else
							{
								std::cout << "NO" << std::endl;
							}
						}
					}
				}
			}
		}
		break;
	}
	}
	return EXIT_SUCCESS;
}