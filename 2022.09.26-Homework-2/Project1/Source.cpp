#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	switch ((a / 100) % 100)
	{
	case 1:
		std::cout << "sto ";
		break;
	case 2:
		std::cout << "dvesti ";
		break;
	case 3:
		std::cout << "trista ";
		break;
	case 4:
		std::cout << "chetyresta ";
		break;
	case 5:
		std::cout << "pyat'sot ";
		break;
	case 6:
		std::cout << "shest'sot ";
		break;
	case 7:
		std::cout << "sem'sot ";
		break;
	case 8:
		std::cout << "vosem'sot ";
		break;
	case 9:
		std::cout << "devyat'sot ";
		break;
	case 0:
		std::cout << "";
		break;
	}
	switch ((a / 10) % 10)
	{
	case 2:
		std::cout << "dvadtsat' ";
		break;
	case 3:
		std::cout << "tridtsat' ";
		break;
	case 4:
		std::cout << "sorok ";
		break;
	case 5:
		std::cout << "pyat'desyat ";
		break;
	case 6:
		std::cout << "shest'desyat ";
		break;
	case 7:
		std::cout << "sem'desyat ";
		break;
	case 8:
		std::cout << "vosem'desyat ";
		break;
	case 9:
		std::cout << "devyanosto ";
		break;
	case 0:
		std::cout << "";
		break;
	case 1:
		switch (a % 10)
		{
		case 1:
			std::cout << "odinnadtsat' bananov";
			break;
		case 2:
			std::cout << "dvennadtsat' bananov";
			break;
		case 3:
			std::cout << "trinnadtsat' bananov";
			break;
		case 4:
			std::cout << "chetyrnadtsat' bananov";
			break;
		case 5:
			std::cout << "pyatnadtsat' bananov";
			break;
		case 6:
			std::cout << "shestnadtsat' bananov";
			break;
		case 7:
			std::cout << "semnadtsat' bananov";
			break;
		case 8:
			std::cout << "vosemnadtsat' bananov";
			break;
		case 9:
			std::cout << "devyatnadtsat' bananov";
			break;
		case 0:
			std::cout << "desyat' bananov";
			break;
		}
	}
	if ((a / 10) % 10 != 1)
	{
		switch (a % 10)
		{
		case 1:
			std::cout << "odin banan";
			break;
		case 2:
			std::cout << "dva banana";
			break;
		case 3:
			std::cout << "tri banana";
			break;
		case 4:
			std::cout << "chetyre banana";
			break;
		case 5:
			std::cout << "pyat' bananov";
			break;
		case 6:
			std::cout << "shest' bananov";
			break;
		case 7:
			std::cout << "sem' bananov";
			break;
		case 8:
			std::cout << "vosem' bananov";
			break;
		case 9:
			std::cout << "devyat' bananov";
			break;
		case 0:
			std::cout << "bananov";
			break;
		}
	}
	return EXIT_SUCCESS;

}