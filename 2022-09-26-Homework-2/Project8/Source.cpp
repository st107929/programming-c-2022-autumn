#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int sgn_cos_alpha = 0;
	int sgn_cos_betta = 0;
	int sgn_cos_gamma = 0;
	int asqr = 0;
	int bsqr = 0;
	int csqr = 0;
	std::cin >> a >> b >> c;
	
	if (((a < b + c) && (b < a + c)) && (c < b + a))
	{
		asqr = a * a;
		bsqr = b * b;
		csqr = c * c;

		sgn_cos_alpha = bsqr + csqr - asqr;
		sgn_cos_betta = asqr + csqr - bsqr;
		sgn_cos_gamma = asqr + bsqr - csqr;

		if ((sgn_cos_alpha > 0) && (sgn_cos_betta > 0) && (sgn_cos_gamma > 0))
		{
			std::cout << "acute" << std::endl;
		}
		else
		{
			if (sgn_cos_alpha == 0)
			{
				std::cout << "right" << std::endl;
			}
			else
			{
				if (sgn_cos_betta == 0)
				{
					std::cout << "right" << std::endl;
				}
				else
				{
					if (sgn_cos_gamma == 0)
					{
						std::cout << "right" << std::endl;
					}
					else
					{
						std::cout << "obtuse" << std::endl;
					}
				}
			}
		}
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
	return EXIT_SUCCESS;
}